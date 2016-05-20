./compile.sh
mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub
cp myos.bin isodir/boot/myos.bin
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "Chien First OS" {
	multiboot /boot/myos.bin
}
EOF
grub-mkrescue -o myos.iso isodir
qemu-system-i386 -cdrom myos.iso