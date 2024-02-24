# FIXME: before you push into master...
RUNTIMEDIR=/usr/bin/../include/omc/c/
#COPY_RUNTIMEFILES=$(FMI_ME_OBJS:%= && (OMCFILE=% && cp $(RUNTIMEDIR)/$$OMCFILE.c $$OMCFILE.c))

fmu:
	rm -f SimpleRoomFourElements.fmutmp/sources/SimpleRoomFourElements_init.xml
	cp -a "/usr/bin/../share/omc/runtime/c/fmi/buildproject/"* SimpleRoomFourElements.fmutmp/sources
	cp -a SimpleRoomFourElements_FMU.libs SimpleRoomFourElements.fmutmp/sources/

