if(document.getElementById('selectfile')){
    document.getElementById('selectfile').addEventListener('click',function(event){document.getElementById('file').click();})
}
document.getElementById('btn-sidebar').addEventListener('click',function(event){
    var a=document.getElementById('sidebar');
    if(a.getAttribute("open")===null){
        a.setAttribute("open","1");
    }else{
        a.removeAttribute("open","");
    }
})
window.addEventListener('resize', function(){
    var a=document.getElementById('sidebar');
    if(window.innerWidth<840){
        a.removeAttribute("open","");
    }else{
        a.setAttribute("open","1");
    }
});
if(window.innerWidth>=840){
    a.setAttribute("open","");
}