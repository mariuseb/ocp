# FIXME: before you push into master...
RUNTIMEDIR=/usr/bin/../include/omc/c/
#COPY_RUNTIMEFILES=$(FMI_ME_OBJS:%= && (OMCFILE=% && cp $(RUNTIMEDIR)/$$OMCFILE.c $$OMCFILE.c))

fmu:
	rm -f PI.fmutmp/sources/PI_init.xml
	cp -a "/usr/bin/../share/omc/runtime/c/fmi/buildproject/"* PI.fmutmp/sources
	cp -a PI_FMU.libs PI.fmutmp/sources/

