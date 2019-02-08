OBJ_DIR  := obj
INCLUDE = -I..

swatch_test:
	gcc -c -o $(OBJ_DIR)/swatch.o ../swatch.c $(INCLUDE)
	gcc -c -o $(OBJ_DIR)/swatch_test.o swatch_test.c $(INCLUDE)
	gcc -o swatch_test $(OBJ_DIR)/swatch_test.o $(OBJ_DIR)/swatch.o -lcunit $(INCLUDE)

clean:
	rm -rf swatch_test obj/*.o