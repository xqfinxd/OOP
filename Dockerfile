# base image
FROM ubuntu
RUN apt-get update
RUN apt-get install -y build-essential gcc g++
RUN apt-get install -y python
#COPY std.cpp /home/
RUN cd /home/
#ADD https://s3-us-west-2.amazonaws.com/blanknoweb.com/src.cpp /home/
#ADD https://s3-us-west-2.amazonaws.com/blanknoweb.com/std.cpp /home/
#ADD demo_in.txt ~/
#ADD demo_out.txt ~/
#RUN g++ /home/src.cpp -o /home/src -std=c++11
#RUN g++ /home/std.cpp -o /home/std -std=c++11
#ADD test.py /home/
ADD https://s3-us-west-2.amazonaws.com/blanknoweb.com/test.py /home/
RUN chmod a+x /home/test.py
#RUN /home/test.py
ENTRYPOINT ["python","/home/test.py"]
