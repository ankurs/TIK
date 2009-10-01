cp src/kernel iso/boot/kernel
cp README iso/README
mkisofs -R -b boot/grub/stage2_eltorito -no-emul-boot -boot-load-size 4 -boot-info-table -o TIK.iso iso
echo "iso created OK"

