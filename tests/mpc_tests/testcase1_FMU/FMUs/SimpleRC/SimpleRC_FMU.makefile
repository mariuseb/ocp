# FIXME: before you push into master...
RUNTIMEDIR=/usr/bin/../include/omc/c/
#COPY_RUNTIMEFILES=$(FMI_ME_OBJS:%= && (OMCFILE=% && cp $(RUNTIMEDIR)/$$OMCFILE.c $$OMCFILE.c))

fmu:
	rm -f SimpleRC.fmutmp/sources/SimpleRC_init.xml
	cp -a "/usr/bin/../share/omc/runtime/c/fmi/buildproject/"* SimpleRC.fmutmp/sources
	cp -a SimpleRC_FMU.libs SimpleRC.fmutmp/sources/

