FROM mcr.microsoft.com/devcontainers/cpp:1-debian-12

ARG REINSTALL_CMAKE_VERSION_FROM_SOURCE="none"

# Optionally install the cmake for vcpkg
COPY ./reinstall-cmake.sh /tmp/

RUN if [ "${REINSTALL_CMAKE_VERSION_FROM_SOURCE}" != "none" ]; then \
        chmod +x /tmp/reinstall-cmake.sh && /tmp/reinstall-cmake.sh ${REINSTALL_CMAKE_VERSION_FROM_SOURCE}; \
    fi \
    && rm -f /tmp/reinstall-cmake.sh

RUN echo "Types: deb\n\
# http://snapshot.debian.org/archive/debian/20250428T000000Z\n\
URIs: http://deb.debian.org/debian\n\
Suites: trixie\n\
Components: main\n\
Signed-By: /usr/share/keyrings/debian-archive-keyring.gpg\n"\
>> /etc/apt/sources.list.d/debian.sources \
    && apt-get update \
    && apt-get install -y \
        gcc-14 \
        g++-14 \
    && update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-14 10 \
    && update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-14 10 \
    && update-alternatives --install /usr/bin/gcov gcov /usr/bin/gcov-14 10 \
    && update-alternatives --set gcc /usr/bin/gcc-14 \
    && update-alternatives --set g++ /usr/bin/g++-14 \
    && update-alternatives --set gcov /usr/bin/gcov-14

ARG GOOGLE_TEST_VERSION="1.17.0"

RUN curl -sSL -O https://github.com/google/googletest/releases/download/v${GOOGLE_TEST_VERSION}/googletest-${GOOGLE_TEST_VERSION}.tar.gz \
    && tar -xzf googletest-${GOOGLE_TEST_VERSION}.tar.gz \
    && cd googletest-${GOOGLE_TEST_VERSION} \
    && mkdir build \
    && cd build \
    && cmake .. \
    && make \
    && make install \
    && rm -rf googletest-${GOOGLE_TEST_VERSION} \
    && rm -f googletest-${GOOGLE_TEST_VERSION}.tar.gz

RUN apt-get install -y \
    clang \
    clang-tidy \
    clang-format

RUN pip3 install gcovr --break-system-packages

# [Optional] Uncomment this section to install additional vcpkg ports.
# RUN su vscode -c "${VCPKG_ROOT}/vcpkg install <your-port-name-here>"

# [Optional] Uncomment this section to install additional packages.
# RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
#     && apt-get -y install --no-install-recommends <your-package-list-here>
