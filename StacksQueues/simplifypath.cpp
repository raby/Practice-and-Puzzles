/*
Given an absolute path for a file (Unix-style), simplify it.

Examples:

path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
Note that absolute path always begin with ‘/’ ( root directory )
Path will not have whitespace characters.
*/
string Solution::simplifyPath(string path) {
        int i=0;
        while (i<path.size()-1){
            if (path[i]=='/' && path[i+1]=='/'){
                path.erase(i,1);
            }else{ i++; }
        }
        //Add a '/' in the end.
        if (path[path.size()-1]!='/'){path=path+"/";}
         
        //main part
        stack<string> dirs;
        string str="";
        int flag =0;
        for (int i=0;i<path.size();i++){
            if (path[i]=='/'){flag++;}        
            if (flag==1){ str+=path[i];}
            if (flag==2){
                if (str=="/.." && !dirs.empty()){
                    dirs.pop();
                }
                if (str!="/." && str!="/.."){
                    dirs.push(str);    
                }
                flag=1;
                str="/";
            }
        }
         
        //Output Result
        if (dirs.empty()){return "/";}
        str="";
        while (!dirs.empty()){
            str=dirs.top()+str;
            dirs.pop();
        }
        return str;
    }
    

