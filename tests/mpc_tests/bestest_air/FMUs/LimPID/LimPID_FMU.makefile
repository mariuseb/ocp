# FIXME: before you push into master...
RUNTIMEDIR=/usr/bin/../include/omc/c/
#COPY_RUNTIMEFILES=$(FMI_ME_OBJS:%= && (OMCFILE=% && cp $(RUNTIMEDIR)/$$OMCFILE.c $$OMCFILE.c))

fmu:
	rm -f LimPID.fmutmp/sources/LimPID_init.xml
	cp -a "/usr/bin/../share/omc/runtime/c/fmi/buildproject/"* LimPID.fmutmp/sources
	cp -a LimPID_FMU.libs LimPID.fmutmp/sources/

