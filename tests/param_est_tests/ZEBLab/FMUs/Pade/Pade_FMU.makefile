# FIXME: before you push into master...
RUNTIMEDIR=/home/marius/Documents/OpenModelica/build/install_cmake/bin/../include/omc/c/
#COPY_RUNTIMEFILES=$(FMI_ME_OBJS:%= && (OMCFILE=% && cp $(RUNTIMEDIR)/$$OMCFILE.c $$OMCFILE.c))

fmu:
	rm -f Pade.fmutmp/sources/Pade_init.xml
	cp -a "/home/marius/Documents/OpenModelica/build/install_cmake/bin/../share/omc/runtime/c/fmi/buildproject/"* Pade.fmutmp/sources
	cp -a Pade_FMU.libs Pade.fmutmp/sources/

