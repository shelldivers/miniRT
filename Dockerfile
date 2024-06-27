# TO BUILD THIS IMAGE
# docker build -t minirt:valgrind .

# TO RUN THE GOOGLE TEST WITH VALGRIND
# docker run minirt:valgrind

# TO RUN A SPECIFIC TEST WITH VALGRIND
# docker run -e TEST=<file_name> minirt_test:valgrind

# lightweight linux for reducing build time
FROM alpine:latest

# Install dependencies
RUN apk add --no-cache build-base git make cmake valgrind

# copy the source code into the container
COPY . /app

# set the working directory
WORKDIR /app

# build the project
RUN cmake . -B build && cd build && make

ENV TEST build/minirt_test

# run the tests
# you can run another test by changing the TEST variable
CMD valgrind --leak-check=full ./${TEST}
