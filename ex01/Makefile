NAME := ex01

SOURCES_DIRECTORY := ./sources
OBJECTS_DIRECTORY := ./objects
INCLUDES_DIRECTORY := ./includes

SOURCES := Bureaucrat.cpp Form.cpp main.cpp

SOURCE_FILES := $(addprefix $(SOURCES_DIRECTORY)/, $(SOURCES))
OBJECT_FILES := $(addprefix $(OBJECTS_DIRECTORY)/, $(SOURCES:.cpp=.o))
DEPENDENCE_FILES := $(addprefix $(OBJECTS_DIRECTORY)/, $(SOURCES:.cpp=.d))

CPP := c++
CPP_VERSION := -std=c++11
CPP_FLAGS := -Wall -Wextra -Werror -MMD -MP -I$(INCLUDES_DIRECTORY)
DEBUG_FLAGS := -DDEBUG -g -O0

all: $(NAME)

debug: CPP_FLAGS := $(CPP_FLAGS) $(DEBUG_FLAGS)
debug: fclean $(NAME)

$(NAME): $(OBJECT_FILES)
	$(CPP) $(CPP_FLAGS) $(CPP_VERSION) $(OBJECT_FILES) -o $@

-include $(DEPENDENCE_FILES)

$(OBJECTS_DIRECTORY)/%.o: $(SOURCES_DIRECTORY)/%.cpp | $(OBJECTS_DIRECTORY)
	$(CPP) $(CPP_FLAGS) $(CPP_VERSION) -c $< -o $@

$(OBJECTS_DIRECTORY):
	mkdir -p $@

clean:
	rm -rf $(OBJECTS_DIRECTORY)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re debug
