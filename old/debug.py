class Debug:

    def __init__(self):
        pass

    MOSIOP_NOTICE = lambda msg:print('\033[30;42mMOSIOP:{}\033[0m'.format(msg))
    MOSIOP_WARNING = lambda msg:print('\033[30;41mMOSIOP:{}\033[0m'.format(msg))