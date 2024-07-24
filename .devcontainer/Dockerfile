# Use the official Ubuntu 24.04 base image
FROM ubuntu:24.04

# Set environment variables to non-interactive (prevent prompts)
ENV DEBIAN_FRONTEND=noninteractive

# Install necessary packages
RUN apt-get update && \
    apt-get install -y \
    curl \
    build-essential \
    cmake \
    git \
    python3 \
    python3-pip \
    && rm -rf /var/lib/apt/lists/*

# Install Emscripten SDK
RUN git clone https://github.com/emscripten-core/emsdk.git /opt/emsdk && \
    cd /opt/emsdk && \
    ./emsdk install latest && \
    ./emsdk activate latest

# Set environment variables for Emscripten
ENV PATH="/opt/emsdk/emsdk_env.sh:${PATH}"
ENV EMSDK="/opt/emsdk"

# Source Emscripten environment variables
RUN echo "source /opt/emsdk/emsdk_env.sh" >> /root/.bashrc

# Set the working directory
WORKDIR /workspace

# Set the default shell to bash
SHELL ["/bin/bash", "-c"]

# Entry point for the container
ENTRYPOINT [ "bash" ]
