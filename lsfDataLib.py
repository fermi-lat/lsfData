# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/lsfData/lsfDataLib.py,v 1.3 2009/01/23 00:20:59 ecephas Exp $
def generate(env, **kw):
    if not kw.get('depsOnly', 0):
        env.Tool('addLibrary', library = ['lsfData'])
    env.Tool('eventFileLib')
    # env.Tool('addLibrary', library = env['ldfLibs'])
def exists(env):
    return 1;
