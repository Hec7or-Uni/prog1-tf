# Nombre del ejecutable
TARGET = cesar

# Compilador
CXX = g++

# Flags de compilación (puedes añadir más si es necesario)
CXXFLAGS = -Wall -g -std=c++11

# Archivos fuente
SRCS = analisis-cesar.cpp cesar.cpp cesar-main.cpp diccionario.cpp pedir-nombre-fichero.cpp

# Archivos de cabecera
HEADERS = analisis-cesar.h cesar.h diccionario.h pedir-nombre-fichero.h

# Archivos objeto (los archivos .o se generan a partir de los .cpp)
OBJS = $(SRCS:.cpp=.o)

# Regla por defecto, compilar todo
all: $(TARGET)

# Regla para compilar el ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regla para compilar cada archivo .cpp a .o
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
