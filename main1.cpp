#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>

bool bulidincommand(vector<string> &cmd)
{
    char  *env;
    env=getenv("PATH");
    if (cmd == "setenv")
    {
        if (env==NULL)
        {
            setenv(env,"/bin",1);
        }
        else {setenv(env,"/bin:np.bin",1);}
    else if(cmd == "printenv")
    {
        if (env!=NULL)
        {
            std::cout << printenv(*env);
        }
        else (std::out << "env does not exist";)
    }
    else if (cmd == "exit")
    {
        exit(EXIT_SUCCESS);
    }
    return true;
}