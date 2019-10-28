#!/bin/bash
set -x

#Pass the release name
export BASE=$PWD
export OS_RELEASE_NAME="trusty"
export QEMU_IMG=$BASE
export KERN_SRC=$BASE/linux-4.17
export KERNEL=$BASE/KERNEL
#CPU parallelism
export PARA="-j"
export VER="4.17.0"
export QEMU_IMG_FILE=$PWD/qemu-image.img
export MOUNT_DIR=$PWD/mountdir
export QEMUMEM="4096M"
mkdir "$KERNEL"

set +x
