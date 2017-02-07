#include <iostream>

//http://baxincc.cc/questions/366316/how-to-prevent-implicit-conversion-from-char-array-to-bool

class Obj
{
public:

    //Templatized Constructor , forced to use
    template<typename T>
    Obj(const std::string & s1, T)
    {
        static_assert(std::is_same<T,bool>::value,"T is not bool, need to provide bool argument");

        std::cout<<"c1 called"<<'\n';
    }
    Obj(const std::string & s1, const std::string & s2, bool boolean=true){std::cout<<"c2 called"<<'\n';}
    Obj(const char * s1, const char * s2, bool boolean=true){std::cout<<"c3 called"<<'\n';}
    ~Obj(){}

};

int main(int argc, char *argv[])
{
    std::string s("s");

    Obj preventedFromBeingConverted(s,"a" /*,true*/);//uncomment 3rd boolean parameter to make it work

    Obj callingConstructor1Explicitly(s,true);

    //the rest work fine, don't cause issues
    Obj o2(s,s);
    Obj o3("a","a");

    return 0;
}
