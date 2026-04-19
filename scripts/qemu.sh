#!/bin/sh
set -e
. ./scripts/iso.sh

qemu-system-$(./scripts/target-triplet-to-arch.sh $HOST) --enable-kvm --cpu host,hv_time,hv_relaxed -cdrom myos.iso
