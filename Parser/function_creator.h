#ifndef FUNCTION_CREATOR_H
#define FUNCTION_CREATOR_H
#include <string>
#include <sstream>
#include <binary_tree.h>



class function_creator
{
    public:
        function_creator(binary_tree<std::string>*);
        virtual ~function_creator();
        binary_tree<std::string>* tree;

    protected:
    private:

};

#endif // FUNCTION_CREATOR_H
