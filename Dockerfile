FROM ubuntu

RUN apt-get update
RUN apt-get install -y pip cmake
RUN pip install conan
COPY include debed/include
COPY src debed/src
COPY CMakeLists.txt debed/CMakeLists.txt
COPY conanfile.txt debed/conanfile.txt
COPY main.cpp debed/main.cpp
RUN conan profile detect
RUN conan install debed/ -b debed/build --build missing
RUN ls / -la
RUN sleep 100
RUN cd debed
RUN cat CMakeLists.txt
#RUN cmake -S debed/ -B debed/build
#RUN cmake --build debed/build

CMD debed/build/debed

