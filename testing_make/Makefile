OUT_DIR = ./out_dir

all: hello

hello: makeoutputdir hello.o func.o
	g++ -o $(OUT_DIR)/hello hello.o func.o



hello.o:
	g++ -o $(OUT_DIR)/hello.o -c hello.cpp

func.o:
	g++ -c func.h func.cpp

run:
	$(OUT_DIR)/hello


# Directory management
clean_output:
	rm -rf $(OUT_DIR)
	# rm *.o *.h.gch

makeoutputdir: clean_output
	mkdir $(OUT_DIR)