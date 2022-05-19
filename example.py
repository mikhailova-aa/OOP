
import ctypes

print('Library loading')
deadline_lib = ctypes.CDLL('./res.so')

print('Initializing library interface')
deadline_lib.create_deadline.argtypes = [ctypes.c_char_p, ctypes.c_char_p, ctypes.c_char_p,
                                          ctypes.c_int, ctypes.c_int]
deadline_lib.create_deadline.restype = ctypes.c_void_p

print('Function calling')
dt = deadline_lib.create_deadline(b'id', b'text', b'name', 100500, 10)

print('Success')
