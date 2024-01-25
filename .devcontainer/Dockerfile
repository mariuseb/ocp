# Use an official Ubuntu image as a parent image
FROM ubuntu:latest

# Set the working directory
WORKDIR /app

# Update the package list and install required packages
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    git \
    python3 \
    python3-pip \
    curl \
    && rm -rf /var/lib/apt/lists/


# Install PyTorch (CPU version) and other packages we need
#RUN pip3 install --no-cache-dir torch --index-url https://download.pytorch.org/whl/cpu
RUN pip3 install --no-cache-dir scipy
RUN pip3 install --no-cache-dir numpy
RUN pip3 install --no-cache-dir pandas
RUN pip3 install --no-cache-dir matplotlib
RUN pip3 install --no-cache-dir casadi
# Add further installations here as they are cached
