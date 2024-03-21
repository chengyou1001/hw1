#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <cstdlib>
using namespace std;
void commandpipe(string strcmd,vector<string> v)
{
    int n=0,n1=0;
    for(;n<strcmd.size(); n++)
    {
        if(strcmd[n]=='|')
        {
            v.push_back(strcmd.substr(n1,n));
            n1=n+1;
        }
        else if(strcmd[n]=='>')
        {
            if(n+1 < strcmd.size()&& strcmd[n+1]=='>')
            {
                v.push_back(strcmd.substr(n1,n));
                v.push_back(">" + strcmd.substr(n+1));               
            }
        }
    }
    std::array<char,80> buffer;
    std::string s(v.begin(),v.end());
    FILE *pipe=_popen(s.c_str(),"r");
    int c=0;
    while (fgets(buffer.data(),80, pipe) !=NULL)
    {
        c++;
        std::cout << c << " " << buffer.data();
    }
    _pclose(pipe);
}
int main()
{
    string strcmd={"Hello>"};
    vector<string> *v
    commandpipe(strcmd,*v)
    return 0;
}