
CC=g++

CFLAGS=-Wall

LFLAGS=-L/usr/local/lib -lallegro `pkg-config --libs allegro-5 allegro_audio-5 allegro_dialog-5 allegro_image-5 allegro_memfile-5 allegro_primitives-5 allegro_acodec-5 allegro_color-5 allegro_font-5 allegro_main-5 allegro_physfs-5 allegro_ttf-5` 

INCLUDE=-I/usr/local/include/allegro5

CODES=*.cpp classes/*.cpp

EXE=pacman

all: executable

executable: $(CODES)
	$(CC) $(CODES) -o $(EXE) $(INCLUDE) $(CFLAGS) $(LFLAGS)

clean:
	rm -rf *.o

run:
	./$(EXE)

srgb:
	pngcrush -ow -rem allb -reduce images/*.png