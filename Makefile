
NAME	= game

SRC		= Collidable.cpp Enemy.cpp Place.cpp Player.cpp main.cpp
SRC		+= Level.cpp Bullet.cpp Weapon.cpp PointShot.cpp YEnemy.cpp
SRC		+= PowerUp.cpp
OBJ		= $(addprefix $(OBJDIR),$(SRC:.cpp=.o))

CC		= clang++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -O3
LDFLAGS	= -Wall -Wextra -Werror -lncurses

INCDIR	= ./includes/
SRCDIR	= ./src/
OBJDIR	= ./obj/

all: obj $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	$(CC) $(CGLAGS) -I $(INCDIR) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

f: re
	./$(NAME)

re: fclean all
