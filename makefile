COMPILER=g++

FLAGS=-Wall -Werror -std=c++17 -O3

LIBS=-L /usr/local/lib -lallegro `pkg-config --libs allegro-5 allegro_audio-5 allegro_dialog-5 allegro_image-5 allegro_memfile-5 allegro_primitives-5 allegro_acodec-5 allegro_color-5 allegro_font-5 allegro_main-5 allegro_physfs-5 allegro_ttf-5`

INCLUDES=-I /usr/local/include/allegro5

SOURCES=*.cpp classes/*.cpp

EXECUTABLE=pacman

all: executable

executable: $(SOURCES)
	$(COMPILER) $(SOURCES) -o $(EXECUTABLE) $(INCLUDES) $(FLAGS) $(LIBS)

run:
	./$(EXECUTABLE)

clean:
	rm -rf *.o

rgb:
	pngcrush -ow -rem allb -reduce images/*.png