#include "Completion.h"
#include <iostream>

namespace RhIO
{
        // probably a very unefficient way to do that
    std::string Completion::getSubstring(std::deque<std::string> matches)
    {
        std::string line="";
            //so there are at least two elements but lets check anyway...
        if(matches.size()>1)
        {
            int len=9999;
            std::string tmpcmd;
            for(std::deque<std::string>::iterator it=matches.begin(); it!=matches.end();++it)
            {
                if((*it).length()<len) //get the smallest
                {
                    len=(*it).length();
                    tmpcmd=*it;
                }
            }

                //ckeck char by char...
            for(int i=1;i<tmpcmd.length();i++)
            {
                bool iscommon=true;
                std::string tmp(tmpcmd,0,i);

                for(std::deque<std::string>::iterator it=matches.begin(); it!=matches.end();++it)
                {
                    if((*it).compare(tmpcmd)!=0) //dont compare with ourself
                    {

                        if((*it).compare(0,i,tmp)!=0)
                            iscommon=false;
                    }
                }
                if(iscommon)
                    line=tmp;
            }


        }
        return line;

    }
}