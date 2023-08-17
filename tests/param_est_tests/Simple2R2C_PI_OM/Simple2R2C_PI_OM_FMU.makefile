# FIXME: before you push into master...
RUNTIMEDIR=/home/marius/Documents/OpenModelica/build/install_cmake/bin/../include/omc/c/
#COPY_RUNTIMEFILES=$(FMI_ME_OBJS:%= && (OMCFILE=% && cp $(RUNTIMEDIR)/$$OMCFILE.c $$OMCFILE.c))

fmu:
	rm -f Simple2R2C_PI_OM.fmutmp/sources/Simple2R2C_PI_OM_init.xml
	cp -a "/home/marius/Documents/OpenModelica/build/install_cmake/bin/../share/omc/runtime/c/fmi/buildproject/"* Simple2R2C_PI_OM.fmutmp/sources
	cp -a Simple2R2C_PI_OM_FMU.libs Simple2R2C_PI_OM.fmutmp/sources/

