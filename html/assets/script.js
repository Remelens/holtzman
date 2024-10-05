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
    document.getElementById('sidebar').setAttribute("open","");
}
const dialog = document.querySelector(".delete-file-action");
if(dialog){
    document.querySelector("#del-dia-cancel").addEventListener("click", () => dialog.open = false);
    document.querySelector("#del-dia-del").addEventListener("click", () => dialog.open = false);
    const openButton = document.querySelectorAll(".delete-file-btn");
    openButton.forEach((node)=>{
        node.addEventListener("click", (event) => {
            let fname=event.srcElement.parentNode.childNodes[0].textContent;
            dialog.open = true;
            document.getElementById('del-file-name').value=fname;
            dialog.headline="Delete file '"+fname+"'?";
        });
    });
}
const cdia = document.querySelector(".deleted-dia");
if(cdia){
    document.querySelector("#deleted-dia-btn").addEventListener("click", () => cdia.open = false);
}
