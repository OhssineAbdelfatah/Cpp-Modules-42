#include"ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyForm",145,137),_Target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy): AForm(copy),_Target(copy._Target)
{
    *this = copy ;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
    if(this == &copy )
        return *this;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}


std::string ShrubberyCreationForm::getTarget() const {
    return this->_Target;
}

void ShrubberyCreationForm::execute(const Bureaucrat & executor) const 
{
    if (!this->getSignedStatus() )
        throw ShrubberyCreationForm::FormNotSignedException();
    if( executor.getGrade() > this->getExecuteGrade())
        throw ShrubberyCreationForm::GradeTooLowException();
    else{
        std::ofstream file(this->getTarget().append("_shrubbery").c_str());
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
