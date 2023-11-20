# Определение компилятора и флагов компиляции
CXX := g++
CPPFLAGS := -Isrc/HeaderFiles
CXXFLAGS := -g -O0 -std=c++11

# Определение директорий
SRCDIR := src/SourceFiles
OBJDIR := obj
BINDIR := bin

# Создание списка исходных файлов
SOURCES := $(wildcard $(SRCDIR)/*.cpp)

# Создание списка объектных файлов
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

# Правило для сборки объектных файлов
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# Правило для сборки исполняемого файла
$(BINDIR)/program: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Правило сборки по умолчанию
all: $(BINDIR)/program

#make run ARGS1="input.txt" ARGS2="output.txt"
run: 
	./$(BINDIR)/program $(ARGS1) $(ARGS2) 

# Правило очистки собранных файлов
clean:
	rm -f $(OBJDIR)/*.o $(BINDIR)/program