# $Header$
def generate(env, **kw):
    if not kw.get('depsOnly', 0):
        env.Tool('addLibrary', library = ['lsfData'])
    env.Tool('eventFileLib')

def exists(env):
    return 1;
