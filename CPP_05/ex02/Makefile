NAME = Shrubbery

FLAGS = -Wall -Wextra -Werror -std=gnu++98

SRCS = main.cpp Bureaucrat.cpp Form.cpp  ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	@echo "Tyler is Compiling..."
	@clang++ $(FLAGS) -o $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	@echo "Tyler is Creating objects..."
	@clang++ $(FLAGS) -c $(SRCS)

all: $(NAME)

clean:
	@echo "Tyler is Cleaning..."
	@rm -rf $(OBJS) *_shrubbery
	
fclean: clean
	@rm -f $(NAME)

re: fclean all

run: all
	@./$(NAME)