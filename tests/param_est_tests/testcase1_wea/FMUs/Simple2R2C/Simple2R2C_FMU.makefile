# FIXME: before you push into master...
RUNTIMEDIR=/usr/bin/../include/omc/c/
#COPY_RUNTIMEFILES=$(FMI_ME_OBJS:%= && (OMCFILE=% && cp $(RUNTIMEDIR)/$$OMCFILE.c $$OMCFILE.c))

fmu:
	rm -f Simple2R2C.fmutmp/sources/Simple2R2C_init.xml
	cp -a "/usr/bin/../share/omc/runtime/c/fmi/buildproject/"* Simple2R2C.fmutmp/sources
	cp -a Simple2R2C_FMU.libs Simple2R2C.fmutmp/sources/

