#include "httplib.h"
#include <filesystem>
#include "error.hpp"
using namespace std;
namespace fs = std::filesystem;
using namespace httplib;
const string name="Holtzman";
const int PORT=8000;
string file_get_contents(string fn){
    ifstream fin (fn.c_str());
    string s,rst;
    while(getline(fin,s)){
        rst+=s+"\n";
    }
    fin.close();
    return rst;
}
string replace_str(string s,string be_repl,string repled){
    int index = 0;
    while (true) {
        index = s.find(be_repl, index);
        if (index == std::string::npos) break;
        s.replace(index, be_repl.size(), repled);
        index += 3;
    }
    return s;
}
string process_html(string fn,map<string,string> mp){
    ifstream fin (fn.c_str());
    string s,rst;
    while(getline(fin,s)){
        for(auto im=mp.begin();im!=mp.end();++im){
            s=replace_str(s,"%{"+im->first+"}%",im->second);
        }
        rst+=s+"\n";
    }
    fin.close();
    return rst;
}
string fileserver(string pt,string path){
    string rst="<mdui-list>",tmp;
    chdir(path.c_str());
    for (const auto & entry : fs::directory_iterator(".")){
        tmp=string(entry.path().filename());
        rst+="<mdui-list-item rounded title=\""+tmp+"\">"+tmp+"<mdui-button-icon slot=\"end-icon\" icon=\"link\" target=\"_blank\" href=\""+pt+"/"+tmp+"\"></mdui-button-icon><mdui-button-icon slot=\"end-icon\" icon=\"delete\" class=\"delete-file-btn\"></mdui-button-icon></mdui-list-item>";
    }
    rst+="</mdui-list>";
    chdir("..");
    if(rst==""){
        rst="<span>No file exists.</span>";
    }
    return rst;
}
string del_getfilename(string s){
    int a=s.find("=");
    s.erase(0,a+1);
    return s;
}
int main(){
    cout<<"Server listening at port "<<PORT<<endl;
    cout<<"Url: http://localhost:"<<PORT<<"/"<<endl;
    ecode_init();
    Server svr;
    if (!svr.set_mount_point("/file/","file")) {
        cerr << "The specified base directory 'file' doesn't exist.\nQuitting..."<<endl;
        return 1;
    }
    if (!svr.set_mount_point("/assets/","html/assets")) {
        cerr << "The specified base directory 'html/assets' doesn't exist.\nQuitting..."<<endl;
        return 1;
    }
    svr.Get("/", [](const Request &req, Response &res) {
        res.set_content(file_get_contents("html/index.html"), "text/html;charset=utf-8");
    });
    svr.Get("/file", [](const Request &req, Response &res) {
        map<string,string> m;
        m["allfiles"]=fileserver("/file","file");
        m["opinfo"]="";
        m["script"]="";
        res.set_content(process_html("html/file.html",m), "text/html;charset=utf-8");
    });
    svr.Post("/file", [](const Request &req, Response &res) {
        map<string,string> m;
        string a_fname=del_getfilename(req.body);
        string file="./file/"+a_fname;
        if(a_fname.find("/")!=std::string::npos||a_fname.find("\\")!=std::string::npos){
            m["opinfo"]="Failed to delete '"+a_fname+"'.";
        }else if(fs::exists(file)&&fs::remove(file)){
            m["opinfo"]="File '"+a_fname+"' deleted.";
            //success
        }else{
            m["opinfo"]="Failed to delete '"+a_fname+"'.";
            //failed
        }
        m["script"]="cdia.open=true";
        m["allfiles"]=fileserver("/file","file");
        res.set_content(process_html("html/file.html",m), "text/html;charset=utf-8");
    });
    svr.Post("/upload", [](const Request &req, Response &res) {
        auto filectt = req.get_file_value("file");
        string uploadinfo="File size: "+to_string(filectt.content.length())+"<br>\n"+
            "File name: "+filectt.filename+"<br>\n"+
            "File path: "+"<a target=\"_blank\" href=\"/file/"+filectt.filename+"\">/file/"+filectt.filename+"</a>";
        {
            ofstream ofs("./file/"+filectt.filename, ios::binary);
            ofs << filectt.content;
            ofs.close();
        }
        map<string,string> m;
        m["uploadinfo"]=uploadinfo;
        res.set_content(process_html("html/uploaded.html",m), "text/html;charset=utf-8");
    });
    svr.set_error_handler([](const auto& req, auto& res) {
        auto fmt = "<center><h1>%d %s</h1><hr>%s</center>";
        char buf[BUFSIZ];
        snprintf(buf, sizeof(buf), fmt, res.status,ecode[res.status].c_str(),name.c_str());
        res.set_content(buf, "text/html;charset=utf-8");
    });
    svr.listen("0.0.0.0", PORT);
    return 0;
}
