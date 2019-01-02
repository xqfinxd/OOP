# base image
FROM ubuntu
RUN sudo apt-get update
RUN sudo apt-get install -y build-essential gcc g++
ARG SRC=src.cpp
ADD $SRC ~/
ADD standard.cpp ~/
#ADD demo_in.txt ~/
#ADD demo_out.txt ~/
RUN g++ $SRC -o src -std=c++11
RUN g++ standard.cpp -o standard -std=c++11
ADD test.py ~/
RUN chmod a+x test.py
