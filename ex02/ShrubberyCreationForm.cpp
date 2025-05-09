#include"ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string name):_Name(name),_Signed(false),_SignGrade(145),_ExecuteGrade(137){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy): AForm(copy),_Name(copy.getName()),_Signed(false),_SignGrade(copy.getSigneGrade()),_ExecuteGrade(copy.getExecuteGrade())
{
    *this = copy ;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
    (void)  copy;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::execute(const Bureaucrat & executor) const 
{
    if (!this->_Signed )
        throw ShrubberyCreationForm::FormNotSigned();
    if( executor.getGrade() > this->_ExecuteGrade)
        throw ShrubberyCreationForm::GradeTooLowException();
    else{
        std::ofstream file(this->getName().append("_shrubbery").c_str());
        for(int i = 0 ; i < 100 ; i++)
        {
            file << "                            #**# #%#*#*+==#              " << std::endl;
            file << "                            #++*#%#***++==%              " << std::endl;
            file << "                            #*++=++**+===+               " << std::endl;
            file << "                            %++++=+++=+==#               " << std::endl;
            file << "                             *++==++=++++                " << std::endl;
            file << "                             %++-=====++%                " << std::endl;
            file << "                              *=---==++*                 " << std::endl;
            file << "                              %=--===**                  " << std::endl;
            file << "                              %*=++*##                   " << std::endl;
            file << "                      %%%#**#**+===++#                   " << std::endl;
            file << "                   ***#*++++=====-----=*###%%            " << std::endl;
            file << "                  +-##*+=====-----:-=:::.:-=+*%          " << std::endl;
            file << "                  =+%#+---==-:::-+-::.:::::=++*#         " << std::endl;
            file << "                  =*%*=---+*=---:-+=:...:::=+%*-%        " << std::endl;
            file << "                 *=%#*=---=**+=-..:=+-:..:-=#%==         " << std::endl;
            file << "                #-% #+======+**=-:.:=*+--=+#%+-%         " << std::endl;
            file << "                -* #=---+++===++--:-=*#+=-+%#-+          " << std::endl;
            file << "               +=  +--:--=*++==--=+**+-::-= *-#          " << std::endl;
            file << "              #-%  +--::-:****+-*##+-:..:+* +-           " << std::endl;
            file << "              -#  %=-::-=* *#*-+#*=:...:++# +-           " << std::endl;
            file << "             *+   #--:-=*  ##=+#+-::.:-+*# +-            " << std::endl;
            file << "             -%   +--:-+   %=+#+-:..--==% +=             " << std::endl;
            file << "            +*   %=---=#   =*#+-:.:-==--++*              " << std::endl;
            file << "           %+    #=-:-=  #=# *-:::=+-:--+%               " << std::endl;
            file << "           +#    *-::-*%+*   *---=+--:::*                " << std::endl;
            file << "           +%    +-::-+*%    +-=-===:...=                " << std::endl;
            file << "    **#***%+%%%##=-:-*       +=-===-:..:=                " << std::endl;
            file << "   +#    %*=*###+-::=       *-:-*+--::::=                " << std::endl;
            file << "  %+       =+*#*-::-%     #=-:.+*+==-:===                " << std::endl;
            file << "  %+       +  %+:.=%     *+#+::*#*=-::-:-%               " << std::endl;
            file << "   +%      =   =:-%    %+# %=::%%*=::..::%               " << std::endl;
            file << "    +%     +  *+:+    %+%  #-:: %*+-::.::#               " << std::endl;
            file << "           * %++-#   %+%   +=::  *=--::::#               " << std::endl;
            file << "             *#*-%  %*#  %+##-:% %+---:::#               " << std::endl;
            file << "            *# #=##%%   #*%  +.*  *=--:::*               " << std::endl;
            file << "           +*  **      +#    %-- %#*=-:::=               " << std::endl;
            file << "           %   #      +#      %-=#*#=-::::*              " << std::endl;
            file << "                      %        +-+**-----::#             " << std::endl;
            file << "                              +-=-#=::==-:--%            " << std::endl;
            file << "                             =:-+=-=:-=+-:+*=*%          " << std::endl;
            file << "                            =-#%*#=-:-*=+=*  #*+**##%    " << std::endl;
            file << "                         %#=*  *%+=--# =%=#         %*#  " << std::endl;
            file << "                       #++-=  *%%----**=%-%           %# " << std::endl;
            file << "                      ++%*= %*% +:-*%+-++=               " << std::endl;
            file << "                     =# %- %#%%+:-%   %*=                " << std::endl;
            file << "                  %*+% #=%  %%+.=      =%                " << std::endl;
            file << "                #**%  *+     #:+      +#                 " << std::endl;
            file << "            %####    #=     %--      #*                  " << std::endl;
            file << "                   %*+      -:%      %                   " << std::endl;
            file << "                   #%      #:#                           " << std::endl;
            file << "                           +=                            " << std::endl;
            file << "                           -+                            " << std::endl;
            file << "                           -+                            " << std::endl;
            file << std::endl << std::endl<< std::endl<< std::endl<< std::endl<< std::endl;
        } 
        file.close();
    }
}

std::string ShrubberyCreationForm::getName() const 
{
    return this->_Name;
}

bool ShrubberyCreationForm::getSignedStatus() const 
{
    return this->_Signed;
}

int ShrubberyCreationForm::getSigneGrade() const 
{
    return this->_SignGrade;
}

int ShrubberyCreationForm::getExecuteGrade() const 
{
    return this->_ExecuteGrade;
}

bool ShrubberyCreationForm::beSigned(Bureaucrat& emp)
{
    if(emp.getGrade() <= this->_SignGrade)
    {
        if(this->_Signed)
            return false;
        this->_Signed = true ;
        return true;
    }
    else
        throw AForm::GradeTooLowException();
}
