#!/usr/bin/env bash

set -e

if [ `uname -s` != "Linux" ]; then
    echo "*** ERROR *** This script can be run only on a Linux environment!"
    exit 1
fi

MAKE=make

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# Clean project
clean () {
    pushd "$DIR/../"
        echo "Clean .."
        $MAKE clean
    popd
}

# Build project
build () {
    mkdir -p "build"
    mkdir -p "build/boot/grub"

    pushd "$DIR/../Kernel/"
        echo "Build 'Kernel' .."
        $MAKE
    popd

    pushd "$DIR/../"
        echo "Setup 'Kernel' Build .."
        cp Kernel/kernel.bin Toolchain/build/boot/kernel.bin
        cp grub.cfg Toolchain/build/boot/grub/grub.cfg
    popd

    pushd "$DIR"
        echo "ISO generation in progress.."
        grub-mkrescue -o Qlipha.iso build/
        rm -rf build/
    popd
}

if [ ! -z "$1" ]; then
    if [ "$1" == "clean" ]; then
        clean
    fi
else
    build
fi