
#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

class ShrubberyCreationForm : public AForm {

    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& ShrubberyCreationForm);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
        ~ShrubberyCreationForm(void);
        
        void    execute(Bureaucrat const & executor);

        std::string getTarget(void);
    class FailToOpenFileException : public std::exception {
        
        public:
            virtual const char* what() throw();
            
    }

    private:
        std::string _target;

};

std::ostream& operator<<(std::ostream& o, const ShrubberyCreationForm& ShrubberyCreationForm);

#endif

