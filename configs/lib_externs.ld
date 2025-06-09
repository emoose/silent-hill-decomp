# SDK/library funcs included in overlays, but only referenced outside of the overlay, can be defined here.
# (workaround to ensure linker always pulls in the functions object from the library)

# main
EXTERN(strcmp);
EXTERN(GetVideoMode);
