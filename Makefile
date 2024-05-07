# Nombres de los ejecutables
CLIENT_EXEC := build/client_app
SERVER_EXEC := build/server_app

# Objetos intermedios
THREAD_OBJ := build/pool.o
PROTOCOL_OBJ := build/protocol.o

# Código fuente
CLIENT_SOURCES := src/client/main.cpp src/client/client.cpp
SERVER_SOURCES := src/server/main.cpp src/server/server.cpp
THREAD_SOURCES := src/thread/pool.cpp
PROTOCOL_SOURCES := src/protocol/chat.pb.cc

# Flags de compilación y enlace
CXX := g++
CXXFLAGS := -Wall -Wextra -I src/
# LDFLAGS := 

# Objetivos por defecto
.PHONY: all clean client server

# Objetivo por defecto: compilar todo
all: $(CLIENT_EXEC) $(SERVER_EXEC)

client: $(CLIENT_EXEC)
server: $(SERVER_EXEC)

# Compilar el cliente
$(CLIENT_EXEC): $(CLIENT_SOURCES) $(THREAD_OBJ) $(PROTOCOL_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilar el servidor
$(SERVER_EXEC): $(SERVER_SOURCES) $(THREAD_OBJ) $(PROTOCOL_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilar el pool de threads
$(THREAD_OBJ): $(THREAD_SOURCES)
	$(CXX) $(CXXFLAGS) -c -o $@ $^

# Compilar el protocolo
$(PROTO_OBJ): $(PROTOCOL_SOURCES)
	$(CXX) $(CXXFLAGS) -lprotobuf -c -o $@ $^

# Limpiar los archivos generados
clean:
	rm -rf build

# Directorio de salida
build:
	mkdir -p build

# Asegurar que el directorio build sea creado
$(CLIENT_EXEC): | build
$(SERVER_EXEC): | build
$(THREAD_OBJ): 	| build
$(PROTOC_OBJ): 	| build