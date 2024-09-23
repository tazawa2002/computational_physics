# Makefile for duffing simulation

# コンパイラ
CXX = g++

# コンパイルオプション
CXXFLAGS = -std=c++11 -O2

# 実行ファイル名
TARGET = duffing.exe

# ソースファイル
SRCS = duffing.cpp

# オブジェクトファイル
OBJS = $(SRCS:.cpp=.o)

# 出力ファイル
OUTPUT = duffing.png

# デフォルトターゲット
all: $(TARGET) $(OUTPUT)

# 実行ファイルの生成
$(TARGET): $(OBJS)
	$(CXX) -o $@ $^

# オブジェクトファイルの生成
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

duffing.dat: duffing
	./duffing

# gnuplotを用いて画像を生成
$(OUTPUT): duffing.dat duffing.plt
	gnuplot duffing.plt

# クリーンターゲット
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean