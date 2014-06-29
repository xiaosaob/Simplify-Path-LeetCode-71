// Given an absolute path for a file (Unix-style), simplify it.

// For example,
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> myStack;
        int i = 0;
        while(i < path.length()) {
            while(i < path.length() && path[i] == '/') ++i;
            if(i == path.length()) break;
            int start = i;
            while(i < path.length() && path[i] != '/') ++i;
            string dir = path.substr(start, i-start);
            if(dir == ".") continue;
            else if(dir == "..") {
                if(!myStack.empty()) myStack.pop();
            } else myStack.push(dir);
        }
        string res("");
        while(!myStack.empty()) {
            string tmpStr = myStack.top();
            myStack.pop();
            reverse(tmpStr.begin(), tmpStr.end());
            res += tmpStr+"/";
        }
        reverse(res.begin(), res.end());
        return res.length() ? res : "/";
    }
};
