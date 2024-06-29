#ifndef _ERROR_HPP
#define _ERROR_HPP

#include <map>
std::map<int,std::string> ecode;
extern void ecode_init(){
    ecode[400]="Bad Request";
    ecode[401]="Unauthorized";
    ecode[402]="Payment Required";
    ecode[403]="Forbidden";
    ecode[404]="Not Found";
    ecode[405]="Method Not Allowed";
    ecode[406]="Not Acceptable";
    ecode[407]="Proxy Authentication Required";
    ecode[408]="Request Timeout";
    ecode[409]="Conflict";
    ecode[410]="Gone";
    ecode[411]="Length Required";
    ecode[412]="Precondition Failed";
    ecode[413]="Content Too Large";
    ecode[414]="URI Too Long";
    ecode[415]="Unsupported Media Type";
    ecode[416]="Range Not Satisfiable";
    ecode[417]="Expectation Failed";
    ecode[418]="I'm a teapot";
    ecode[421]="Misdirected Request";
    ecode[422]="Unprocessable Content";
    ecode[423]="Locked";
    ecode[424]="Failed Dependency";
    ecode[425]="Too Early";
    ecode[426]="Upgrade Required";
    ecode[428]="Precondition Required";
    ecode[429]="Too Many Requests";
    ecode[431]="Request Header Fields Too Large";
    ecode[451]="Unavailable For Legal Reasons";
    ecode[500]="Internal Server Error";
    ecode[501]="Not Implemented";
    ecode[502]="Bad Gateway";
    ecode[503]="Service Unavailable";
    ecode[504]="Gateway Timeout";
    ecode[505]="HTTP Version Not Supported";
    ecode[506]="Variant Also Negotiates";
    ecode[507]="Insufficient Storage";
    ecode[508]="Loop Detected";
    ecode[510]="Not Extended";
    ecode[511]="Network Authentication Required";
}
#endif /*_ERROR_HPP*/