#ifndef __glcorearb_h_
#define __glcorearb_h_ 1

#ifdef __cplusplus
extern "C" {
#endif
    
    /*
    ** Copyright (c) 2013-2017 The Khronos Group Inc.
    **
    ** Permission is hereby granted, free of charge, to any person obtaining a
    ** copy of this software and/or associated documentation files (the
    ** "Materials"), to deal in the Materials without restriction, including
    ** without limitation the rights to use, copy, modify, merge, publish,
    ** distribute, sublicense, and/or sell copies of the Materials, and to
    ** permit persons to whom the Materials are furnished to do so, subject to
    ** the following conditions:
    **
    ** The above copyright notice and this permission notice shall be included
    ** in all copies or substantial portions of the Materials.
    **
    ** THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    ** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
    ** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
    ** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
    ** CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
    ** TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
    ** MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
    */
    /*
    ** This header is generated from the Khronos OpenGL / OpenGL ES XML
    ** API Registry. The current version of the Registry, generator scripts
    ** used to make the header, and the header can be found at
    **   https://github.com/KhronosGroup/OpenGL-Registry
    */

#if defined(_WIN32) && !defined(APIENTRY) && !defined(__CYGWIN__) && !defined(__SCITECH_SNAP__)
#endif
    
#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
#endif
#ifndef GLAPI
#define GLAPI extern
#endif
    
    /* glcorearb.h is for use with OpenGL core profile implementations.
    ** It should should be placed in the same directory as gl.h and
    ** included as <GL/glcorearb.h>.
    **
    ** glcorearb.h includes only APIs in the latest OpenGL core profile
    ** implementation together with APIs in newer ARB extensions which 
    ** can be supported by the core profile. It does not, and never will
    ** include functionality removed from the core profile, such as
    ** fixed-function vertex and fragment processing.
    **
    ** Do not #include both <GL/glcorearb.h> and either of <GL/gl.h> or
    ** <GL/glext.h> in the same source file.
    */
    
    /* Generated C header for:
     * API: gl
     * Profile: core
     * Versions considered: .*
     * Versions emitted: .*
     * Default extensions included: glcore
     * Additional extensions included: _nomatch_^
     * Extensions removed: _nomatch_^
     */
    
#ifndef GL_VERSION_1_0
#define GL_VERSION_1_0 1
    typedef void GLvoid;
    typedef unsigned int GLenum;
    typedef float GLfloat;
    typedef int GLint;
    typedef int GLsizei;
    typedef unsigned int GLbitfield;
    typedef double GLdouble;
    typedef unsigned int GLuint;
    typedef unsigned char GLboolean;
    typedef unsigned char GLubyte;
#define GL_DEPTH_BUFFER_BIT               0x00000100
#define GL_STENCIL_BUFFER_BIT             0x00000400
#define GL_COLOR_BUFFER_BIT               0x00004000
#define GL_FALSE                          0
#define GL_TRUE                           1
#define GL_POINTS                         0x0000
#define GL_LINES                          0x0001
#define GL_LINE_LOOP                      0x0002
#define GL_LINE_STRIP                     0x0003
#define GL_TRIANGLES                      0x0004
#define GL_TRIANGLE_STRIP                 0x0005
#define GL_TRIANGLE_FAN                   0x0006
#define GL_QUADS                          0x0007
#define GL_NEVER                          0x0200
#define GL_LESS                           0x0201
#define GL_EQUAL                          0x0202
#define GL_LEQUAL                         0x0203
#define GL_GREATER                        0x0204
#define GL_NOTEQUAL                       0x0205
#define GL_GEQUAL                         0x0206
#define GL_ALWAYS                         0x0207
#define GL_ZERO                           0
#define GL_ONE                            1
#define GL_SRC_COLOR                      0x0300
#define GL_ONE_MINUS_SRC_COLOR            0x0301
#define GL_SRC_ALPHA                      0x0302
#define GL_ONE_MINUS_SRC_ALPHA            0x0303
#define GL_DST_ALPHA                      0x0304
#define GL_ONE_MINUS_DST_ALPHA            0x0305
#define GL_DST_COLOR                      0x0306
#define GL_ONE_MINUS_DST_COLOR            0x0307
#define GL_SRC_ALPHA_SATURATE             0x0308
#define GL_NONE                           0
#define GL_FRONT_LEFT                     0x0400
#define GL_FRONT_RIGHT                    0x0401
#define GL_BACK_LEFT                      0x0402
#define GL_BACK_RIGHT                     0x0403
#define GL_FRONT                          0x0404
#define GL_BACK                           0x0405
#define GL_LEFT                           0x0406
#define GL_RIGHT                          0x0407
#define GL_FRONT_AND_BACK                 0x0408
#define GL_NO_ERROR                       0
#define GL_INVALID_ENUM                   0x0500
#define GL_INVALID_VALUE                  0x0501
#define GL_INVALID_OPERATION              0x0502
#define GL_OUT_OF_MEMORY                  0x0505
#define GL_CW                             0x0900
#define GL_CCW                            0x0901
#define GL_POINT_SIZE                     0x0B11
#define GL_POINT_SIZE_RANGE               0x0B12
#define GL_POINT_SIZE_GRANULARITY         0x0B13
#define GL_LINE_SMOOTH                    0x0B20
#define GL_LINE_WIDTH                     0x0B21
#define GL_LINE_WIDTH_RANGE               0x0B22
#define GL_LINE_WIDTH_GRANULARITY         0x0B23
#define GL_POLYGON_MODE                   0x0B40
#define GL_POLYGON_SMOOTH                 0x0B41
#define GL_CULL_FACE                      0x0B44
#define GL_CULL_FACE_MODE                 0x0B45
#define GL_FRONT_FACE                     0x0B46
#define GL_DEPTH_RANGE                    0x0B70
#define GL_DEPTH_TEST                     0x0B71
#define GL_DEPTH_WRITEMASK                0x0B72
#define GL_DEPTH_CLEAR_VALUE              0x0B73
#define GL_DEPTH_FUNC                     0x0B74
#define GL_STENCIL_TEST                   0x0B90
#define GL_STENCIL_CLEAR_VALUE            0x0B91
#define GL_STENCIL_FUNC                   0x0B92
#define GL_STENCIL_VALUE_MASK             0x0B93
#define GL_STENCIL_FAIL                   0x0B94
#define GL_STENCIL_PASS_DEPTH_FAIL        0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS        0x0B96
#define GL_STENCIL_REF                    0x0B97
#define GL_STENCIL_WRITEMASK              0x0B98
#define GL_VIEWPORT                       0x0BA2
#define GL_DITHER                         0x0BD0
#define GL_BLEND_DST                      0x0BE0
#define GL_BLEND_SRC                      0x0BE1
#define GL_BLEND                          0x0BE2
#define GL_LOGIC_OP_MODE                  0x0BF0
#define GL_DRAW_BUFFER                    0x0C01
#define GL_READ_BUFFER                    0x0C02
#define GL_SCISSOR_BOX                    0x0C10
#define GL_SCISSOR_TEST                   0x0C11
#define GL_COLOR_CLEAR_VALUE              0x0C22
#define GL_COLOR_WRITEMASK                0x0C23
#define GL_DOUBLEBUFFER                   0x0C32
#define GL_STEREO                         0x0C33
#define GL_LINE_SMOOTH_HINT               0x0C52
#define GL_POLYGON_SMOOTH_HINT            0x0C53
#define GL_UNPACK_SWAP_BYTES              0x0CF0
#define GL_UNPACK_LSB_FIRST               0x0CF1
#define GL_UNPACK_ROW_LENGTH              0x0CF2
#define GL_UNPACK_SKIP_ROWS               0x0CF3
#define GL_UNPACK_SKIP_PIXELS             0x0CF4
#define GL_UNPACK_ALIGNMENT               0x0CF5
#define GL_PACK_SWAP_BYTES                0x0D00
#define GL_PACK_LSB_FIRST                 0x0D01
#define GL_PACK_ROW_LENGTH                0x0D02
#define GL_PACK_SKIP_ROWS                 0x0D03
#define GL_PACK_SKIP_PIXELS               0x0D04
#define GL_PACK_ALIGNMENT                 0x0D05
#define GL_MAX_TEXTURE_SIZE               0x0D33
#define GL_MAX_VIEWPORT_DIMS              0x0D3A
#define GL_SUBPIXEL_BITS                  0x0D50
#define GL_TEXTURE_1D                     0x0DE0
#define GL_TEXTURE_2D                     0x0DE1
#define GL_TEXTURE_WIDTH                  0x1000
#define GL_TEXTURE_HEIGHT                 0x1001
#define GL_TEXTURE_BORDER_COLOR           0x1004
#define GL_DONT_CARE                      0x1100
#define GL_FASTEST                        0x1101
#define GL_NICEST                         0x1102
#define GL_BYTE                           0x1400
#define GL_UNSIGNED_BYTE                  0x1401
#define GL_SHORT                          0x1402
#define GL_UNSIGNED_SHORT                 0x1403
#define GL_INT                            0x1404
#define GL_UNSIGNED_INT                   0x1405
#define GL_FLOAT                          0x1406
#define GL_STACK_OVERFLOW                 0x0503
#define GL_STACK_UNDERFLOW                0x0504
#define GL_CLEAR                          0x1500
#define GL_AND                            0x1501
#define GL_AND_REVERSE                    0x1502
#define GL_COPY                           0x1503
#define GL_AND_INVERTED                   0x1504
#define GL_NOOP                           0x1505
#define GL_XOR                            0x1506
#define GL_OR                             0x1507
#define GL_NOR                            0x1508
#define GL_EQUIV                          0x1509
#define GL_INVERT                         0x150A
#define GL_OR_REVERSE                     0x150B
#define GL_COPY_INVERTED                  0x150C
#define GL_OR_INVERTED                    0x150D
#define GL_NAND                           0x150E
#define GL_SET                            0x150F
#define GL_TEXTURE                        0x1702
#define GL_COLOR                          0x1800
#define GL_DEPTH                          0x1801
#define GL_STENCIL                        0x1802
#define GL_STENCIL_INDEX                  0x1901
#define GL_DEPTH_COMPONENT                0x1902
#define GL_RED                            0x1903
#define GL_GREEN                          0x1904
#define GL_BLUE                           0x1905
#define GL_ALPHA                          0x1906
#define GL_RGB                            0x1907
#define GL_RGBA                           0x1908
#define GL_POINT                          0x1B00
#define GL_LINE                           0x1B01
#define GL_FILL                           0x1B02
#define GL_KEEP                           0x1E00
#define GL_REPLACE                        0x1E01
#define GL_INCR                           0x1E02
#define GL_DECR                           0x1E03
#define GL_VENDOR                         0x1F00
#define GL_RENDERER                       0x1F01
#define GL_VERSION                        0x1F02
#define GL_EXTENSIONS                     0x1F03
#define GL_NEAREST                        0x2600
#define GL_LINEAR                         0x2601
#define GL_NEAREST_MIPMAP_NEAREST         0x2700
#define GL_LINEAR_MIPMAP_NEAREST          0x2701
#define GL_NEAREST_MIPMAP_LINEAR          0x2702
#define GL_LINEAR_MIPMAP_LINEAR           0x2703
#define GL_TEXTURE_MAG_FILTER             0x2800
#define GL_TEXTURE_MIN_FILTER             0x2801
#define GL_TEXTURE_WRAP_S                 0x2802
#define GL_TEXTURE_WRAP_T                 0x2803
#define GL_REPEAT                         0x2901
    typedef void (APIENTRYP PFNGLCULLFACEPROC) (GLenum mode);
    typedef void (APIENTRYP PFNGLFRONTFACEPROC) (GLenum mode);
    typedef void (APIENTRYP PFNGLHINTPROC) (GLenum target, GLenum mode);
    typedef void (APIENTRYP PFNGLLINEWIDTHPROC) (GLfloat width);
    typedef void (APIENTRYP PFNGLPOINTSIZEPROC) (GLfloat size);
    typedef void (APIENTRYP PFNGLPOLYGONMODEPROC) (GLenum face, GLenum mode);
    typedef void (APIENTRYP PFNGLSCISSORPROC) (GLint x, GLint y, GLsizei width, GLsizei height);
    typedef void (APIENTRYP PFNGLTEXPARAMETERFPROC) (GLenum target, GLenum pname, GLfloat param);
    typedef void (APIENTRYP PFNGLTEXPARAMETERFVPROC) (GLenum target, GLenum pname, const GLfloat *params);
    typedef void (APIENTRYP PFNGLTEXPARAMETERIPROC) (GLenum target, GLenum pname, GLint param);
    typedef void (APIENTRYP PFNGLTEXPARAMETERIVPROC) (GLenum target, GLenum pname, const GLint *params);
    typedef void (APIENTRYP PFNGLTEXIMAGE1DPROC) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
    typedef void (APIENTRYP PFNGLTEXIMAGE2DPROC) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
    typedef void (APIENTRYP PFNGLDRAWBUFFERPROC) (GLenum buf);
    typedef void (APIENTRYP PFNGLCLEARPROC) (GLbitfield mask);
    typedef void (APIENTRYP PFNGLCLEARCOLORPROC) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
    typedef void (APIENTRYP PFNGLCLEARSTENCILPROC) (GLint s);
    typedef void (APIENTRYP PFNGLCLEARDEPTHPROC) (GLdouble depth);
    typedef void (APIENTRYP PFNGLSTENCILMASKPROC) (GLuint mask);
    typedef void (APIENTRYP PFNGLCOLORMASKPROC) (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
    typedef void (APIENTRYP PFNGLDEPTHMASKPROC) (GLboolean flag);
    typedef void (APIENTRYP PFNGLDISABLEPROC) (GLenum cap);
    typedef void (APIENTRYP PFNGLENABLEPROC) (GLenum cap);
    typedef void (APIENTRYP PFNGLFINISHPROC) (void);
    typedef void (APIENTRYP PFNGLFLUSHPROC) (void);
    typedef void (APIENTRYP PFNGLBLENDFUNCPROC) (GLenum sfactor, GLenum dfactor);
    typedef void (APIENTRYP PFNGLLOGICOPPROC) (GLenum opcode);
    typedef void (APIENTRYP PFNGLSTENCILFUNCPROC) (GLenum func, GLint ref, GLuint mask);
    typedef void (APIENTRYP PFNGLSTENCILOPPROC) (GLenum fail, GLenum zfail, GLenum zpass);
    typedef void (APIENTRYP PFNGLDEPTHFUNCPROC) (GLenum func);
    typedef void (APIENTRYP PFNGLPIXELSTOREFPROC) (GLenum pname, GLfloat param);
    typedef void (APIENTRYP PFNGLPIXELSTOREIPROC) (GLenum pname, GLint param);
    typedef void (APIENTRYP PFNGLREADBUFFERPROC) (GLenum src);
    typedef void (APIENTRYP PFNGLREADPIXELSPROC) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
    typedef void (APIENTRYP PFNGLGETBOOLEANVPROC) (GLenum pname, GLboolean *data);
    typedef void (APIENTRYP PFNGLGETDOUBLEVPROC) (GLenum pname, GLdouble *data);
    typedef GLenum (APIENTRYP PFNGLGETERRORPROC) (void);
    typedef void (APIENTRYP PFNGLGETFLOATVPROC) (GLenum pname, GLfloat *data);
    typedef void (APIENTRYP PFNGLGETINTEGERVPROC) (GLenum pname, GLint *data);
    typedef const GLubyte *(APIENTRYP PFNGLGETSTRINGPROC) (GLenum name);
    typedef void (APIENTRYP PFNGLGETTEXIMAGEPROC) (GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
    typedef void (APIENTRYP PFNGLGETTEXPARAMETERFVPROC) (GLenum target, GLenum pname, GLfloat *params);
    typedef void (APIENTRYP PFNGLGETTEXPARAMETERIVPROC) (GLenum target, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERFVPROC) (GLenum target, GLint level, GLenum pname, GLfloat *params);
    typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERIVPROC) (GLenum target, GLint level, GLenum pname, GLint *params);
    typedef GLboolean (APIENTRYP PFNGLISENABLEDPROC) (GLenum cap);
    typedef void (APIENTRYP PFNGLDEPTHRANGEPROC) (GLdouble near, GLdouble far);
    typedef void (APIENTRYP PFNGLVIEWPORTPROC) (GLint x, GLint y, GLsizei width, GLsizei height);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glCullFace (GLenum mode);
    GLAPI void APIENTRY glFrontFace (GLenum mode);
    GLAPI void APIENTRY glHint (GLenum target, GLenum mode);
    GLAPI void APIENTRY glLineWidth (GLfloat width);
    GLAPI void APIENTRY glPointSize (GLfloat size);
    GLAPI void APIENTRY glPolygonMode (GLenum face, GLenum mode);
    GLAPI void APIENTRY glScissor (GLint x, GLint y, GLsizei width, GLsizei height);
    GLAPI void APIENTRY glTexParameterf (GLenum target, GLenum pname, GLfloat param);
    GLAPI void APIENTRY glTexParameterfv (GLenum target, GLenum pname, const GLfloat *params);
    GLAPI void APIENTRY glTexParameteri (GLenum target, GLenum pname, GLint param);
    GLAPI void APIENTRY glTexParameteriv (GLenum target, GLenum pname, const GLint *params);
    GLAPI void APIENTRY glTexImage1D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
    GLAPI void APIENTRY glTexImage2D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
    GLAPI void APIENTRY glDrawBuffer (GLenum buf);
    GLAPI void APIENTRY glClear (GLbitfield mask);
    GLAPI void APIENTRY glClearColor (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
    GLAPI void APIENTRY glClearStencil (GLint s);
    GLAPI void APIENTRY glClearDepth (GLdouble depth);
    GLAPI void APIENTRY glStencilMask (GLuint mask);
    GLAPI void APIENTRY glColorMask (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
    GLAPI void APIENTRY glDepthMask (GLboolean flag);
    GLAPI void APIENTRY glDisable (GLenum cap);
    GLAPI void APIENTRY glEnable (GLenum cap);
    GLAPI void APIENTRY glFinish (void);
    GLAPI void APIENTRY glFlush (void);
    GLAPI void APIENTRY glBlendFunc (GLenum sfactor, GLenum dfactor);
    GLAPI void APIENTRY glLogicOp (GLenum opcode);
    GLAPI void APIENTRY glStencilFunc (GLenum func, GLint ref, GLuint mask);
    GLAPI void APIENTRY glStencilOp (GLenum fail, GLenum zfail, GLenum zpass);
    GLAPI void APIENTRY glDepthFunc (GLenum func);
    GLAPI void APIENTRY glPixelStoref (GLenum pname, GLfloat param);
    GLAPI void APIENTRY glPixelStorei (GLenum pname, GLint param);
    GLAPI void APIENTRY glReadBuffer (GLenum src);
    GLAPI void APIENTRY glReadPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
    GLAPI void APIENTRY glGetBooleanv (GLenum pname, GLboolean *data);
    GLAPI void APIENTRY glGetDoublev (GLenum pname, GLdouble *data);
    GLAPI GLenum APIENTRY glGetError (void);
    GLAPI void APIENTRY glGetFloatv (GLenum pname, GLfloat *data);
    GLAPI void APIENTRY glGetIntegerv (GLenum pname, GLint *data);
    GLAPI const GLubyte *APIENTRY glGetString (GLenum name);
    GLAPI void APIENTRY glGetTexImage (GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
    GLAPI void APIENTRY glGetTexParameterfv (GLenum target, GLenum pname, GLfloat *params);
    GLAPI void APIENTRY glGetTexParameteriv (GLenum target, GLenum pname, GLint *params);
    GLAPI void APIENTRY glGetTexLevelParameterfv (GLenum target, GLint level, GLenum pname, GLfloat *params);
    GLAPI void APIENTRY glGetTexLevelParameteriv (GLenum target, GLint level, GLenum pname, GLint *params);
    GLAPI GLboolean APIENTRY glIsEnabled (GLenum cap);
    GLAPI void APIENTRY glDepthRange (GLdouble near, GLdouble far);
    GLAPI void APIENTRY glViewport (GLint x, GLint y, GLsizei width, GLsizei height);
#endif
#endif /* GL_VERSION_1_0 */
    
#ifndef GL_VERSION_1_1
#define GL_VERSION_1_1 1
    typedef float GLclampf;
    typedef double GLclampd;
#define GL_COLOR_LOGIC_OP                 0x0BF2
#define GL_POLYGON_OFFSET_UNITS           0x2A00
#define GL_POLYGON_OFFSET_POINT           0x2A01
#define GL_POLYGON_OFFSET_LINE            0x2A02
#define GL_POLYGON_OFFSET_FILL            0x8037
#define GL_POLYGON_OFFSET_FACTOR          0x8038
#define GL_TEXTURE_BINDING_1D             0x8068
#define GL_TEXTURE_BINDING_2D             0x8069
#define GL_TEXTURE_INTERNAL_FORMAT        0x1003
#define GL_TEXTURE_RED_SIZE               0x805C
#define GL_TEXTURE_GREEN_SIZE             0x805D
#define GL_TEXTURE_BLUE_SIZE              0x805E
#define GL_TEXTURE_ALPHA_SIZE             0x805F
#define GL_DOUBLE                         0x140A
#define GL_PROXY_TEXTURE_1D               0x8063
#define GL_PROXY_TEXTURE_2D               0x8064
#define GL_R3_G3_B2                       0x2A10
#define GL_RGB4                           0x804F
#define GL_RGB5                           0x8050
#define GL_RGB8                           0x8051
#define GL_RGB10                          0x8052
#define GL_RGB12                          0x8053
#define GL_RGB16                          0x8054
#define GL_RGBA2                          0x8055
#define GL_RGBA4                          0x8056
#define GL_RGB5_A1                        0x8057
#define GL_RGBA8                          0x8058
#define GL_RGB10_A2                       0x8059
#define GL_RGBA12                         0x805A
#define GL_RGBA16                         0x805B
#define GL_VERTEX_ARRAY                   0x8074
    typedef void (APIENTRYP PFNGLDRAWARRAYSPROC) (GLenum mode, GLint first, GLsizei count);
    typedef void (APIENTRYP PFNGLDRAWELEMENTSPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices);
    typedef void (APIENTRYP PFNGLGETPOINTERVPROC) (GLenum pname, void **params);
    typedef void (APIENTRYP PFNGLPOLYGONOFFSETPROC) (GLfloat factor, GLfloat units);
    typedef void (APIENTRYP PFNGLCOPYTEXIMAGE1DPROC) (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
    typedef void (APIENTRYP PFNGLCOPYTEXIMAGE2DPROC) (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
    typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE1DPROC) (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
    typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE2DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    typedef void (APIENTRYP PFNGLTEXSUBIMAGE1DPROC) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
    typedef void (APIENTRYP PFNGLTEXSUBIMAGE2DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
    typedef void (APIENTRYP PFNGLBINDTEXTUREPROC) (GLenum target, GLuint texture);
    typedef void (APIENTRYP PFNGLDELETETEXTURESPROC) (GLsizei n, const GLuint *textures);
    typedef void (APIENTRYP PFNGLGENTEXTURESPROC) (GLsizei n, GLuint *textures);
    typedef GLboolean (APIENTRYP PFNGLISTEXTUREPROC) (GLuint texture);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glDrawArrays (GLenum mode, GLint first, GLsizei count);
    GLAPI void APIENTRY glDrawElements (GLenum mode, GLsizei count, GLenum type, const void *indices);
    GLAPI void APIENTRY glGetPointerv (GLenum pname, void **params);
    GLAPI void APIENTRY glPolygonOffset (GLfloat factor, GLfloat units);
    GLAPI void APIENTRY glCopyTexImage1D (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
    GLAPI void APIENTRY glCopyTexImage2D (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
    GLAPI void APIENTRY glCopyTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
    GLAPI void APIENTRY glCopyTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    GLAPI void APIENTRY glTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
    GLAPI void APIENTRY glTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
    GLAPI void APIENTRY glBindTexture (GLenum target, GLuint texture);
    GLAPI void APIENTRY glDeleteTextures (GLsizei n, const GLuint *textures);
    GLAPI void APIENTRY glGenTextures (GLsizei n, GLuint *textures);
    GLAPI GLboolean APIENTRY glIsTexture (GLuint texture);
#endif
#endif /* GL_VERSION_1_1 */
    
#ifndef GL_VERSION_1_2
#define GL_VERSION_1_2 1
#define GL_UNSIGNED_BYTE_3_3_2            0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4         0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1         0x8034
#define GL_UNSIGNED_INT_8_8_8_8           0x8035
#define GL_UNSIGNED_INT_10_10_10_2        0x8036
#define GL_TEXTURE_BINDING_3D             0x806A
#define GL_PACK_SKIP_IMAGES               0x806B
#define GL_PACK_IMAGE_HEIGHT              0x806C
#define GL_UNPACK_SKIP_IMAGES             0x806D
#define GL_UNPACK_IMAGE_HEIGHT            0x806E
#define GL_TEXTURE_3D                     0x806F
#define GL_PROXY_TEXTURE_3D               0x8070
#define GL_TEXTURE_DEPTH                  0x8071
#define GL_TEXTURE_WRAP_R                 0x8072
#define GL_MAX_3D_TEXTURE_SIZE            0x8073
#define GL_UNSIGNED_BYTE_2_3_3_REV        0x8362
#define GL_UNSIGNED_SHORT_5_6_5           0x8363
#define GL_UNSIGNED_SHORT_5_6_5_REV       0x8364
#define GL_UNSIGNED_SHORT_4_4_4_4_REV     0x8365
#define GL_UNSIGNED_SHORT_1_5_5_5_REV     0x8366
#define GL_UNSIGNED_INT_8_8_8_8_REV       0x8367
#define GL_UNSIGNED_INT_2_10_10_10_REV    0x8368
#define GL_BGR                            0x80E0
#define GL_BGRA                           0x80E1
#define GL_MAX_ELEMENTS_VERTICES          0x80E8
#define GL_MAX_ELEMENTS_INDICES           0x80E9
#define GL_CLAMP_TO_EDGE                  0x812F
#define GL_TEXTURE_MIN_LOD                0x813A
#define GL_TEXTURE_MAX_LOD                0x813B
#define GL_TEXTURE_BASE_LEVEL             0x813C
#define GL_TEXTURE_MAX_LEVEL              0x813D
#define GL_SMOOTH_POINT_SIZE_RANGE        0x0B12
#define GL_SMOOTH_POINT_SIZE_GRANULARITY  0x0B13
#define GL_SMOOTH_LINE_WIDTH_RANGE        0x0B22
#define GL_SMOOTH_LINE_WIDTH_GRANULARITY  0x0B23
#define GL_ALIASED_LINE_WIDTH_RANGE       0x846E
    typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSPROC) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
    typedef void (APIENTRYP PFNGLTEXIMAGE3DPROC) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
    typedef void (APIENTRYP PFNGLTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
    typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glDrawRangeElements (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
    GLAPI void APIENTRY glTexImage3D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
    GLAPI void APIENTRY glTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
    GLAPI void APIENTRY glCopyTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#endif
#endif /* GL_VERSION_1_2 */
    
#ifndef GL_VERSION_1_3
#define GL_VERSION_1_3 1
#define GL_TEXTURE0                       0x84C0
#define GL_TEXTURE1                       0x84C1
#define GL_TEXTURE2                       0x84C2
#define GL_TEXTURE3                       0x84C3
#define GL_TEXTURE4                       0x84C4
#define GL_TEXTURE5                       0x84C5
#define GL_TEXTURE6                       0x84C6
#define GL_TEXTURE7                       0x84C7
#define GL_TEXTURE8                       0x84C8
#define GL_TEXTURE9                       0x84C9
#define GL_TEXTURE10                      0x84CA
#define GL_TEXTURE11                      0x84CB
#define GL_TEXTURE12                      0x84CC
#define GL_TEXTURE13                      0x84CD
#define GL_TEXTURE14                      0x84CE
#define GL_TEXTURE15                      0x84CF
#define GL_TEXTURE16                      0x84D0
#define GL_TEXTURE17                      0x84D1
#define GL_TEXTURE18                      0x84D2
#define GL_TEXTURE19                      0x84D3
#define GL_TEXTURE20                      0x84D4
#define GL_TEXTURE21                      0x84D5
#define GL_TEXTURE22                      0x84D6
#define GL_TEXTURE23                      0x84D7
#define GL_TEXTURE24                      0x84D8
#define GL_TEXTURE25                      0x84D9
#define GL_TEXTURE26                      0x84DA
#define GL_TEXTURE27                      0x84DB
#define GL_TEXTURE28                      0x84DC
#define GL_TEXTURE29                      0x84DD
#define GL_TEXTURE30                      0x84DE
#define GL_TEXTURE31                      0x84DF
#define GL_ACTIVE_TEXTURE                 0x84E0
#define GL_MULTISAMPLE                    0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE       0x809E
#define GL_SAMPLE_ALPHA_TO_ONE            0x809F
#define GL_SAMPLE_COVERAGE                0x80A0
#define GL_SAMPLE_BUFFERS                 0x80A8
#define GL_SAMPLES                        0x80A9
#define GL_SAMPLE_COVERAGE_VALUE          0x80AA
#define GL_SAMPLE_COVERAGE_INVERT         0x80AB
#define GL_TEXTURE_CUBE_MAP               0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP       0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X    0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X    0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y    0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y    0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z    0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z    0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP         0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE      0x851C
#define GL_COMPRESSED_RGB                 0x84ED
#define GL_COMPRESSED_RGBA                0x84EE
#define GL_TEXTURE_COMPRESSION_HINT       0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE  0x86A0
#define GL_TEXTURE_COMPRESSED             0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS     0x86A3
#define GL_CLAMP_TO_BORDER                0x812D
    typedef void (APIENTRYP PFNGLACTIVETEXTUREPROC) (GLenum texture);
    typedef void (APIENTRYP PFNGLSAMPLECOVERAGEPROC) (GLfloat value, GLboolean invert);
    typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE3DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
    typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE2DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
    typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE1DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
    typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
    typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
    typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
    typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXIMAGEPROC) (GLenum target, GLint level, void *img);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glActiveTexture (GLenum texture);
    GLAPI void APIENTRY glSampleCoverage (GLfloat value, GLboolean invert);
    GLAPI void APIENTRY glCompressedTexImage3D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
    GLAPI void APIENTRY glCompressedTexImage2D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
    GLAPI void APIENTRY glCompressedTexImage1D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
    GLAPI void APIENTRY glCompressedTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
    GLAPI void APIENTRY glCompressedTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
    GLAPI void APIENTRY glCompressedTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
    GLAPI void APIENTRY glGetCompressedTexImage (GLenum target, GLint level, void *img);
#endif
#endif /* GL_VERSION_1_3 */
    
#ifndef GL_VERSION_1_4
#define GL_VERSION_1_4 1
#define GL_BLEND_DST_RGB                  0x80C8
#define GL_BLEND_SRC_RGB                  0x80C9
#define GL_BLEND_DST_ALPHA                0x80CA
#define GL_BLEND_SRC_ALPHA                0x80CB
#define GL_POINT_FADE_THRESHOLD_SIZE      0x8128
#define GL_DEPTH_COMPONENT16              0x81A5
#define GL_DEPTH_COMPONENT24              0x81A6
#define GL_DEPTH_COMPONENT32              0x81A7
#define GL_MIRRORED_REPEAT                0x8370
#define GL_MAX_TEXTURE_LOD_BIAS           0x84FD
#define GL_TEXTURE_LOD_BIAS               0x8501
#define GL_INCR_WRAP                      0x8507
#define GL_DECR_WRAP                      0x8508
#define GL_TEXTURE_DEPTH_SIZE             0x884A
#define GL_TEXTURE_COMPARE_MODE           0x884C
#define GL_TEXTURE_COMPARE_FUNC           0x884D
#define GL_FUNC_ADD                       0x8006
#define GL_FUNC_SUBTRACT                  0x800A
#define GL_FUNC_REVERSE_SUBTRACT          0x800B
#define GL_MIN                            0x8007
#define GL_MAX                            0x8008
#define GL_CONSTANT_COLOR                 0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR       0x8002
#define GL_CONSTANT_ALPHA                 0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA       0x8004
    typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEPROC) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
    typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSPROC) (GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
    typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSPROC) (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount);
    typedef void (APIENTRYP PFNGLPOINTPARAMETERFPROC) (GLenum pname, GLfloat param);
    typedef void (APIENTRYP PFNGLPOINTPARAMETERFVPROC) (GLenum pname, const GLfloat *params);
    typedef void (APIENTRYP PFNGLPOINTPARAMETERIPROC) (GLenum pname, GLint param);
    typedef void (APIENTRYP PFNGLPOINTPARAMETERIVPROC) (GLenum pname, const GLint *params);
    typedef void (APIENTRYP PFNGLBLENDCOLORPROC) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
    typedef void (APIENTRYP PFNGLBLENDEQUATIONPROC) (GLenum mode);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glBlendFuncSeparate (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
    GLAPI void APIENTRY glMultiDrawArrays (GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
    GLAPI void APIENTRY glMultiDrawElements (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount);
    GLAPI void APIENTRY glPointParameterf (GLenum pname, GLfloat param);
    GLAPI void APIENTRY glPointParameterfv (GLenum pname, const GLfloat *params);
    GLAPI void APIENTRY glPointParameteri (GLenum pname, GLint param);
    GLAPI void APIENTRY glPointParameteriv (GLenum pname, const GLint *params);
    GLAPI void APIENTRY glBlendColor (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
    GLAPI void APIENTRY glBlendEquation (GLenum mode);
#endif
#endif /* GL_VERSION_1_4 */
    
#ifndef GL_VERSION_1_5
#define GL_VERSION_1_5 1
#include <stddef.h>
    typedef ptrdiff_t GLsizeiptr;
    typedef ptrdiff_t GLintptr;
#define GL_BUFFER_SIZE                    0x8764
#define GL_BUFFER_USAGE                   0x8765
#define GL_QUERY_COUNTER_BITS             0x8864
#define GL_CURRENT_QUERY                  0x8865
#define GL_QUERY_RESULT                   0x8866
#define GL_QUERY_RESULT_AVAILABLE         0x8867
#define GL_ARRAY_BUFFER                   0x8892
#define GL_ELEMENT_ARRAY_BUFFER           0x8893
#define GL_ARRAY_BUFFER_BINDING           0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING   0x8895
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#define GL_READ_ONLY                      0x88B8
#define GL_WRITE_ONLY                     0x88B9
#define GL_READ_WRITE                     0x88BA
#define GL_BUFFER_ACCESS                  0x88BB
#define GL_BUFFER_MAPPED                  0x88BC
#define GL_BUFFER_MAP_POINTER             0x88BD
#define GL_STREAM_DRAW                    0x88E0
#define GL_STREAM_READ                    0x88E1
#define GL_STREAM_COPY                    0x88E2
#define GL_STATIC_DRAW                    0x88E4
#define GL_STATIC_READ                    0x88E5
#define GL_STATIC_COPY                    0x88E6
#define GL_DYNAMIC_DRAW                   0x88E8
#define GL_DYNAMIC_READ                   0x88E9
#define GL_DYNAMIC_COPY                   0x88EA
#define GL_SAMPLES_PASSED                 0x8914
#define GL_SRC1_ALPHA                     0x8589
    typedef void (APIENTRYP PFNGLGENQUERIESPROC) (GLsizei n, GLuint *ids);
    typedef void (APIENTRYP PFNGLDELETEQUERIESPROC) (GLsizei n, const GLuint *ids);
    typedef GLboolean (APIENTRYP PFNGLISQUERYPROC) (GLuint id);
    typedef void (APIENTRYP PFNGLBEGINQUERYPROC) (GLenum target, GLuint id);
    typedef void (APIENTRYP PFNGLENDQUERYPROC) (GLenum target);
    typedef void (APIENTRYP PFNGLGETQUERYIVPROC) (GLenum target, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLGETQUERYOBJECTIVPROC) (GLuint id, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLGETQUERYOBJECTUIVPROC) (GLuint id, GLenum pname, GLuint *params);
    typedef void (APIENTRYP PFNGLBINDBUFFERPROC) (GLenum target, GLuint buffer);
    typedef void (APIENTRYP PFNGLDELETEBUFFERSPROC) (GLsizei n, const GLuint *buffers);
    typedef void (APIENTRYP PFNGLGENBUFFERSPROC) (GLsizei n, GLuint *buffers);
    typedef GLboolean (APIENTRYP PFNGLISBUFFERPROC) (GLuint buffer);
    typedef void (APIENTRYP PFNGLBUFFERDATAPROC) (GLenum target, GLsizeiptr size, const void *data, GLenum usage);
    typedef void (APIENTRYP PFNGLBUFFERSUBDATAPROC) (GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
    typedef void (APIENTRYP PFNGLGETBUFFERSUBDATAPROC) (GLenum target, GLintptr offset, GLsizeiptr size, void *data);
    typedef void *(APIENTRYP PFNGLMAPBUFFERPROC) (GLenum target, GLenum access);
    typedef GLboolean (APIENTRYP PFNGLUNMAPBUFFERPROC) (GLenum target);
    typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERIVPROC) (GLenum target, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLGETBUFFERPOINTERVPROC) (GLenum target, GLenum pname, void **params);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glGenQueries (GLsizei n, GLuint *ids);
    GLAPI void APIENTRY glDeleteQueries (GLsizei n, const GLuint *ids);
    GLAPI GLboolean APIENTRY glIsQuery (GLuint id);
    GLAPI void APIENTRY glBeginQuery (GLenum target, GLuint id);
    GLAPI void APIENTRY glEndQuery (GLenum target);
    GLAPI void APIENTRY glGetQueryiv (GLenum target, GLenum pname, GLint *params);
    GLAPI void APIENTRY glGetQueryObjectiv (GLuint id, GLenum pname, GLint *params);
    GLAPI void APIENTRY glGetQueryObjectuiv (GLuint id, GLenum pname, GLuint *params);
    GLAPI void APIENTRY glBindBuffer (GLenum target, GLuint buffer);
    GLAPI void APIENTRY glDeleteBuffers (GLsizei n, const GLuint *buffers);
    GLAPI void APIENTRY glGenBuffers (GLsizei n, GLuint *buffers);
    GLAPI GLboolean APIENTRY glIsBuffer (GLuint buffer);
    GLAPI void APIENTRY glBufferData (GLenum target, GLsizeiptr size, const void *data, GLenum usage);
    GLAPI void APIENTRY glBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
    GLAPI void APIENTRY glGetBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, void *data);
    GLAPI void *APIENTRY glMapBuffer (GLenum target, GLenum access);
    GLAPI GLboolean APIENTRY glUnmapBuffer (GLenum target);
    GLAPI void APIENTRY glGetBufferParameteriv (GLenum target, GLenum pname, GLint *params);
    GLAPI void APIENTRY glGetBufferPointerv (GLenum target, GLenum pname, void **params);
#endif
#endif /* GL_VERSION_1_5 */
    
#ifndef GL_VERSION_2_0
#define GL_VERSION_2_0 1
    typedef char GLchar;
    typedef short GLshort;
    typedef signed char GLbyte;
    typedef unsigned short GLushort;
#define GL_BLEND_EQUATION_RGB             0x8009
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED    0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE       0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE     0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE       0x8625
#define GL_CURRENT_VERTEX_ATTRIB          0x8626
#define GL_VERTEX_PROGRAM_POINT_SIZE      0x8642
#define GL_VERTEX_ATTRIB_ARRAY_POINTER    0x8645
#define GL_STENCIL_BACK_FUNC              0x8800
#define GL_STENCIL_BACK_FAIL              0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL   0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS   0x8803
#define GL_MAX_DRAW_BUFFERS               0x8824
#define GL_DRAW_BUFFER0                   0x8825
#define GL_DRAW_BUFFER1                   0x8826
#define GL_DRAW_BUFFER2                   0x8827
#define GL_DRAW_BUFFER3                   0x8828
#define GL_DRAW_BUFFER4                   0x8829
#define GL_DRAW_BUFFER5                   0x882A
#define GL_DRAW_BUFFER6                   0x882B
#define GL_DRAW_BUFFER7                   0x882C
#define GL_DRAW_BUFFER8                   0x882D
#define GL_DRAW_BUFFER9                   0x882E
#define GL_DRAW_BUFFER10                  0x882F
#define GL_DRAW_BUFFER11                  0x8830
#define GL_DRAW_BUFFER12                  0x8831
#define GL_DRAW_BUFFER13                  0x8832
#define GL_DRAW_BUFFER14                  0x8833
#define GL_DRAW_BUFFER15                  0x8834
#define GL_BLEND_EQUATION_ALPHA           0x883D
#define GL_MAX_VERTEX_ATTRIBS             0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_MAX_TEXTURE_IMAGE_UNITS        0x8872
#define GL_FRAGMENT_SHADER                0x8B30
#define GL_VERTEX_SHADER                  0x8B31
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS  0x8B4A
#define GL_MAX_VARYING_FLOATS             0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#define GL_SHADER_TYPE                    0x8B4F
#define GL_FLOAT_VEC2                     0x8B50
#define GL_FLOAT_VEC3                     0x8B51
#define GL_FLOAT_VEC4                     0x8B52
#define GL_INT_VEC2                       0x8B53
#define GL_INT_VEC3                       0x8B54
#define GL_INT_VEC4                       0x8B55
#define GL_BOOL                           0x8B56
#define GL_BOOL_VEC2                      0x8B57
#define GL_BOOL_VEC3                      0x8B58
#define GL_BOOL_VEC4                      0x8B59
#define GL_FLOAT_MAT2                     0x8B5A
#define GL_FLOAT_MAT3                     0x8B5B
#define GL_FLOAT_MAT4                     0x8B5C
#define GL_SAMPLER_1D                     0x8B5D
#define GL_SAMPLER_2D                     0x8B5E
#define GL_SAMPLER_3D                     0x8B5F
#define GL_SAMPLER_CUBE                   0x8B60
#define GL_SAMPLER_1D_SHADOW              0x8B61
#define GL_SAMPLER_2D_SHADOW              0x8B62
#define GL_DELETE_STATUS                  0x8B80
#define GL_COMPILE_STATUS                 0x8B81
#define GL_LINK_STATUS                    0x8B82
#define GL_VALIDATE_STATUS                0x8B83
#define GL_INFO_LOG_LENGTH                0x8B84
#define GL_ATTACHED_SHADERS               0x8B85
#define GL_ACTIVE_UNIFORMS                0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH      0x8B87
#define GL_SHADER_SOURCE_LENGTH           0x8B88
#define GL_ACTIVE_ATTRIBUTES              0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH    0x8B8A
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B
#define GL_SHADING_LANGUAGE_VERSION       0x8B8C
#define GL_CURRENT_PROGRAM                0x8B8D
#define GL_POINT_SPRITE_COORD_ORIGIN      0x8CA0
#define GL_LOWER_LEFT                     0x8CA1
#define GL_UPPER_LEFT                     0x8CA2
#define GL_STENCIL_BACK_REF               0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK        0x8CA4
#define GL_STENCIL_BACK_WRITEMASK         0x8CA5
    typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEPROC) (GLenum modeRGB, GLenum modeAlpha);
    typedef void (APIENTRYP PFNGLDRAWBUFFERSPROC) (GLsizei n, const GLenum *bufs);
    typedef void (APIENTRYP PFNGLSTENCILOPSEPARATEPROC) (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
    typedef void (APIENTRYP PFNGLSTENCILFUNCSEPARATEPROC) (GLenum face, GLenum func, GLint ref, GLuint mask);
    typedef void (APIENTRYP PFNGLSTENCILMASKSEPARATEPROC) (GLenum face, GLuint mask);
    typedef void (APIENTRYP PFNGLATTACHSHADERPROC) (GLuint program, GLuint shader);
    typedef void (APIENTRYP PFNGLBINDATTRIBLOCATIONPROC) (GLuint program, GLuint index, const GLchar *name);
    typedef void (APIENTRYP PFNGLCOMPILESHADERPROC) (GLuint shader);
    typedef GLuint (APIENTRYP PFNGLCREATEPROGRAMPROC) (void);
    typedef GLuint (APIENTRYP PFNGLCREATESHADERPROC) (GLenum type);
    typedef void (APIENTRYP PFNGLDELETEPROGRAMPROC) (GLuint program);
    typedef void (APIENTRYP PFNGLDELETESHADERPROC) (GLuint shader);
    typedef void (APIENTRYP PFNGLDETACHSHADERPROC) (GLuint program, GLuint shader);
    typedef void (APIENTRYP PFNGLDISABLEVERTEXATTRIBARRAYPROC) (GLuint index);
    typedef void (APIENTRYP PFNGLENABLEVERTEXATTRIBARRAYPROC) (GLuint index);
    typedef void (APIENTRYP PFNGLGETACTIVEATTRIBPROC) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
    typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMPROC) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
    typedef void (APIENTRYP PFNGLGETATTACHEDSHADERSPROC) (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
    typedef GLint (APIENTRYP PFNGLGETATTRIBLOCATIONPROC) (GLuint program, const GLchar *name);
    typedef void (APIENTRYP PFNGLGETPROGRAMIVPROC) (GLuint program, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLGETPROGRAMINFOLOGPROC) (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
    typedef void (APIENTRYP PFNGLGETSHADERIVPROC) (GLuint shader, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLGETSHADERINFOLOGPROC) (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
    typedef void (APIENTRYP PFNGLGETSHADERSOURCEPROC) (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
    typedef GLint (APIENTRYP PFNGLGETUNIFORMLOCATIONPROC) (GLuint program, const GLchar *name);
    typedef void (APIENTRYP PFNGLGETUNIFORMFVPROC) (GLuint program, GLint location, GLfloat *params);
    typedef void (APIENTRYP PFNGLGETUNIFORMIVPROC) (GLuint program, GLint location, GLint *params);
    typedef void (APIENTRYP PFNGLGETVERTEXATTRIBDVPROC) (GLuint index, GLenum pname, GLdouble *params);
    typedef void (APIENTRYP PFNGLGETVERTEXATTRIBFVPROC) (GLuint index, GLenum pname, GLfloat *params);
    typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIVPROC) (GLuint index, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLGETVERTEXATTRIBPOINTERVPROC) (GLuint index, GLenum pname, void **pointer);
    typedef GLboolean (APIENTRYP PFNGLISPROGRAMPROC) (GLuint program);
    typedef GLboolean (APIENTRYP PFNGLISSHADERPROC) (GLuint shader);
    typedef void (APIENTRYP PFNGLLINKPROGRAMPROC) (GLuint program);
    typedef void (APIENTRYP PFNGLSHADERSOURCEPROC) (GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
    typedef void (APIENTRYP PFNGLUSEPROGRAMPROC) (GLuint program);
    typedef void (APIENTRYP PFNGLUNIFORM1FPROC) (GLint location, GLfloat v0);
    typedef void (APIENTRYP PFNGLUNIFORM2FPROC) (GLint location, GLfloat v0, GLfloat v1);
    typedef void (APIENTRYP PFNGLUNIFORM3FPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
    typedef void (APIENTRYP PFNGLUNIFORM4FPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
    typedef void (APIENTRYP PFNGLUNIFORM1IPROC) (GLint location, GLint v0);
    typedef void (APIENTRYP PFNGLUNIFORM2IPROC) (GLint location, GLint v0, GLint v1);
    typedef void (APIENTRYP PFNGLUNIFORM3IPROC) (GLint location, GLint v0, GLint v1, GLint v2);
    typedef void (APIENTRYP PFNGLUNIFORM4IPROC) (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
    typedef void (APIENTRYP PFNGLUNIFORM1FVPROC) (GLint location, GLsizei count, const GLfloat *value);
    typedef void (APIENTRYP PFNGLUNIFORM2FVPROC) (GLint location, GLsizei count, const GLfloat *value);
    typedef void (APIENTRYP PFNGLUNIFORM3FVPROC) (GLint location, GLsizei count, const GLfloat *value);
    typedef void (APIENTRYP PFNGLUNIFORM4FVPROC) (GLint location, GLsizei count, const GLfloat *value);
    typedef void (APIENTRYP PFNGLUNIFORM1IVPROC) (GLint location, GLsizei count, const GLint *value);
    typedef void (APIENTRYP PFNGLUNIFORM2IVPROC) (GLint location, GLsizei count, const GLint *value);
    typedef void (APIENTRYP PFNGLUNIFORM3IVPROC) (GLint location, GLsizei count, const GLint *value);
    typedef void (APIENTRYP PFNGLUNIFORM4IVPROC) (GLint location, GLsizei count, const GLint *value);
    typedef void (APIENTRYP PFNGLUNIFORMMATRIX2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    typedef void (APIENTRYP PFNGLUNIFORMMATRIX3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    typedef void (APIENTRYP PFNGLUNIFORMMATRIX4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPROC) (GLuint program);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB1DPROC) (GLuint index, GLdouble x);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB1DVPROC) (GLuint index, const GLdouble *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB1FPROC) (GLuint index, GLfloat x);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB1FVPROC) (GLuint index, const GLfloat *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB1SPROC) (GLuint index, GLshort x);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB1SVPROC) (GLuint index, const GLshort *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB2DPROC) (GLuint index, GLdouble x, GLdouble y);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB2DVPROC) (GLuint index, const GLdouble *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB2FPROC) (GLuint index, GLfloat x, GLfloat y);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB2FVPROC) (GLuint index, const GLfloat *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB2SPROC) (GLuint index, GLshort x, GLshort y);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB2SVPROC) (GLuint index, const GLshort *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB3DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB3DVPROC) (GLuint index, const GLdouble *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB3FPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB3FVPROC) (GLuint index, const GLfloat *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB3SPROC) (GLuint index, GLshort x, GLshort y, GLshort z);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB3SVPROC) (GLuint index, const GLshort *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB4NBVPROC) (GLuint index, const GLbyte *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB4NIVPROC) (GLuint index, const GLint *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB4NSVPROC) (GLuint index, const GLshort *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBPROC) (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBVPROC) (GLuint index, const GLubyte *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUIVPROC) (GLuint index, const GLuint *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUSVPROC) (GLuint index, const GLushort *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB4BVPROC) (GLuint index, const GLbyte *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB4DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB4DVPROC) (GLuint index, const GLdouble *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB4FPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB4FVPROC) (GLuint index, const GLfloat *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB4IVPROC) (GLuint index, const GLint *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB4SPROC) (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB4SVPROC) (GLuint index, const GLshort *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB4UBVPROC) (GLuint index, const GLubyte *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB4UIVPROC) (GLuint index, const GLuint *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIB4USVPROC) (GLuint index, const GLushort *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBPOINTERPROC) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glBlendEquationSeparate (GLenum modeRGB, GLenum modeAlpha);
    GLAPI void APIENTRY glDrawBuffers (GLsizei n, const GLenum *bufs);
    GLAPI void APIENTRY glStencilOpSeparate (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
    GLAPI void APIENTRY glStencilFuncSeparate (GLenum face, GLenum func, GLint ref, GLuint mask);
    GLAPI void APIENTRY glStencilMaskSeparate (GLenum face, GLuint mask);
    GLAPI void APIENTRY glAttachShader (GLuint program, GLuint shader);
    GLAPI void APIENTRY glBindAttribLocation (GLuint program, GLuint index, const GLchar *name);
    GLAPI void APIENTRY glCompileShader (GLuint shader);
    GLAPI GLuint APIENTRY glCreateProgram (void);
    GLAPI GLuint APIENTRY glCreateShader (GLenum type);
    GLAPI void APIENTRY glDeleteProgram (GLuint program);
    GLAPI void APIENTRY glDeleteShader (GLuint shader);
    GLAPI void APIENTRY glDetachShader (GLuint program, GLuint shader);
    GLAPI void APIENTRY glDisableVertexAttribArray (GLuint index);
    GLAPI void APIENTRY glEnableVertexAttribArray (GLuint index);
    GLAPI void APIENTRY glGetActiveAttrib (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
    GLAPI void APIENTRY glGetActiveUniform (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
    GLAPI void APIENTRY glGetAttachedShaders (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
    GLAPI GLint APIENTRY glGetAttribLocation (GLuint program, const GLchar *name);
    GLAPI void APIENTRY glGetProgramiv (GLuint program, GLenum pname, GLint *params);
    GLAPI void APIENTRY glGetProgramInfoLog (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
    GLAPI void APIENTRY glGetShaderiv (GLuint shader, GLenum pname, GLint *params);
    GLAPI void APIENTRY glGetShaderInfoLog (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
    GLAPI void APIENTRY glGetShaderSource (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
    GLAPI GLint APIENTRY glGetUniformLocation (GLuint program, const GLchar *name);
    GLAPI void APIENTRY glGetUniformfv (GLuint program, GLint location, GLfloat *params);
    GLAPI void APIENTRY glGetUniformiv (GLuint program, GLint location, GLint *params);
    GLAPI void APIENTRY glGetVertexAttribdv (GLuint index, GLenum pname, GLdouble *params);
    GLAPI void APIENTRY glGetVertexAttribfv (GLuint index, GLenum pname, GLfloat *params);
    GLAPI void APIENTRY glGetVertexAttribiv (GLuint index, GLenum pname, GLint *params);
    GLAPI void APIENTRY glGetVertexAttribPointerv (GLuint index, GLenum pname, void **pointer);
    GLAPI GLboolean APIENTRY glIsProgram (GLuint program);
    GLAPI GLboolean APIENTRY glIsShader (GLuint shader);
    GLAPI void APIENTRY glLinkProgram (GLuint program);
    GLAPI void APIENTRY glShaderSource (GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
    GLAPI void APIENTRY glUseProgram (GLuint program);
    GLAPI void APIENTRY glUniform1f (GLint location, GLfloat v0);
    GLAPI void APIENTRY glUniform2f (GLint location, GLfloat v0, GLfloat v1);
    GLAPI void APIENTRY glUniform3f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
    GLAPI void APIENTRY glUniform4f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
    GLAPI void APIENTRY glUniform1i (GLint location, GLint v0);
    GLAPI void APIENTRY glUniform2i (GLint location, GLint v0, GLint v1);
    GLAPI void APIENTRY glUniform3i (GLint location, GLint v0, GLint v1, GLint v2);
    GLAPI void APIENTRY glUniform4i (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
    GLAPI void APIENTRY glUniform1fv (GLint location, GLsizei count, const GLfloat *value);
    GLAPI void APIENTRY glUniform2fv (GLint location, GLsizei count, const GLfloat *value);
    GLAPI void APIENTRY glUniform3fv (GLint location, GLsizei count, const GLfloat *value);
    GLAPI void APIENTRY glUniform4fv (GLint location, GLsizei count, const GLfloat *value);
    GLAPI void APIENTRY glUniform1iv (GLint location, GLsizei count, const GLint *value);
    GLAPI void APIENTRY glUniform2iv (GLint location, GLsizei count, const GLint *value);
    GLAPI void APIENTRY glUniform3iv (GLint location, GLsizei count, const GLint *value);
    GLAPI void APIENTRY glUniform4iv (GLint location, GLsizei count, const GLint *value);
    GLAPI void APIENTRY glUniformMatrix2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    GLAPI void APIENTRY glUniformMatrix3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    GLAPI void APIENTRY glUniformMatrix4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    GLAPI void APIENTRY glValidateProgram (GLuint program);
    GLAPI void APIENTRY glVertexAttrib1d (GLuint index, GLdouble x);
    GLAPI void APIENTRY glVertexAttrib1dv (GLuint index, const GLdouble *v);
    GLAPI void APIENTRY glVertexAttrib1f (GLuint index, GLfloat x);
    GLAPI void APIENTRY glVertexAttrib1fv (GLuint index, const GLfloat *v);
    GLAPI void APIENTRY glVertexAttrib1s (GLuint index, GLshort x);
    GLAPI void APIENTRY glVertexAttrib1sv (GLuint index, const GLshort *v);
    GLAPI void APIENTRY glVertexAttrib2d (GLuint index, GLdouble x, GLdouble y);
    GLAPI void APIENTRY glVertexAttrib2dv (GLuint index, const GLdouble *v);
    GLAPI void APIENTRY glVertexAttrib2f (GLuint index, GLfloat x, GLfloat y);
    GLAPI void APIENTRY glVertexAttrib2fv (GLuint index, const GLfloat *v);
    GLAPI void APIENTRY glVertexAttrib2s (GLuint index, GLshort x, GLshort y);
    GLAPI void APIENTRY glVertexAttrib2sv (GLuint index, const GLshort *v);
    GLAPI void APIENTRY glVertexAttrib3d (GLuint index, GLdouble x, GLdouble y, GLdouble z);
    GLAPI void APIENTRY glVertexAttrib3dv (GLuint index, const GLdouble *v);
    GLAPI void APIENTRY glVertexAttrib3f (GLuint index, GLfloat x, GLfloat y, GLfloat z);
    GLAPI void APIENTRY glVertexAttrib3fv (GLuint index, const GLfloat *v);
    GLAPI void APIENTRY glVertexAttrib3s (GLuint index, GLshort x, GLshort y, GLshort z);
    GLAPI void APIENTRY glVertexAttrib3sv (GLuint index, const GLshort *v);
    GLAPI void APIENTRY glVertexAttrib4Nbv (GLuint index, const GLbyte *v);
    GLAPI void APIENTRY glVertexAttrib4Niv (GLuint index, const GLint *v);
    GLAPI void APIENTRY glVertexAttrib4Nsv (GLuint index, const GLshort *v);
    GLAPI void APIENTRY glVertexAttrib4Nub (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
    GLAPI void APIENTRY glVertexAttrib4Nubv (GLuint index, const GLubyte *v);
    GLAPI void APIENTRY glVertexAttrib4Nuiv (GLuint index, const GLuint *v);
    GLAPI void APIENTRY glVertexAttrib4Nusv (GLuint index, const GLushort *v);
    GLAPI void APIENTRY glVertexAttrib4bv (GLuint index, const GLbyte *v);
    GLAPI void APIENTRY glVertexAttrib4d (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    GLAPI void APIENTRY glVertexAttrib4dv (GLuint index, const GLdouble *v);
    GLAPI void APIENTRY glVertexAttrib4f (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    GLAPI void APIENTRY glVertexAttrib4fv (GLuint index, const GLfloat *v);
    GLAPI void APIENTRY glVertexAttrib4iv (GLuint index, const GLint *v);
    GLAPI void APIENTRY glVertexAttrib4s (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
    GLAPI void APIENTRY glVertexAttrib4sv (GLuint index, const GLshort *v);
    GLAPI void APIENTRY glVertexAttrib4ubv (GLuint index, const GLubyte *v);
    GLAPI void APIENTRY glVertexAttrib4uiv (GLuint index, const GLuint *v);
    GLAPI void APIENTRY glVertexAttrib4usv (GLuint index, const GLushort *v);
    GLAPI void APIENTRY glVertexAttribPointer (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
#endif
#endif /* GL_VERSION_2_0 */
    
#ifndef GL_VERSION_2_1
#define GL_VERSION_2_1 1
#define GL_PIXEL_PACK_BUFFER              0x88EB
#define GL_PIXEL_UNPACK_BUFFER            0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING      0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING    0x88EF
#define GL_FLOAT_MAT2x3                   0x8B65
#define GL_FLOAT_MAT2x4                   0x8B66
#define GL_FLOAT_MAT3x2                   0x8B67
#define GL_FLOAT_MAT3x4                   0x8B68
#define GL_FLOAT_MAT4x2                   0x8B69
#define GL_FLOAT_MAT4x3                   0x8B6A
#define GL_SRGB                           0x8C40
#define GL_SRGB8                          0x8C41
#define GL_SRGB_ALPHA                     0x8C42
#define GL_SRGB8_ALPHA8                   0x8C43
#define GL_COMPRESSED_SRGB                0x8C48
#define GL_COMPRESSED_SRGB_ALPHA          0x8C49
    typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glUniformMatrix2x3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    GLAPI void APIENTRY glUniformMatrix3x2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    GLAPI void APIENTRY glUniformMatrix2x4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    GLAPI void APIENTRY glUniformMatrix4x2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    GLAPI void APIENTRY glUniformMatrix3x4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    GLAPI void APIENTRY glUniformMatrix4x3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#endif
#endif /* GL_VERSION_2_1 */
    
#ifndef GL_VERSION_3_0
#define GL_VERSION_3_0 1
    typedef unsigned short GLhalf;
#define GL_COMPARE_REF_TO_TEXTURE         0x884E
#define GL_CLIP_DISTANCE0                 0x3000
#define GL_CLIP_DISTANCE1                 0x3001
#define GL_CLIP_DISTANCE2                 0x3002
#define GL_CLIP_DISTANCE3                 0x3003
#define GL_CLIP_DISTANCE4                 0x3004
#define GL_CLIP_DISTANCE5                 0x3005
#define GL_CLIP_DISTANCE6                 0x3006
#define GL_CLIP_DISTANCE7                 0x3007
#define GL_MAX_CLIP_DISTANCES             0x0D32
#define GL_MAJOR_VERSION                  0x821B
#define GL_MINOR_VERSION                  0x821C
#define GL_NUM_EXTENSIONS                 0x821D
#define GL_CONTEXT_FLAGS                  0x821E
#define GL_COMPRESSED_RED                 0x8225
#define GL_COMPRESSED_RG                  0x8226
#define GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT 0x00000001
#define GL_RGBA32F                        0x8814
#define GL_RGB32F                         0x8815
#define GL_RGBA16F                        0x881A
#define GL_RGB16F                         0x881B
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER    0x88FD
#define GL_MAX_ARRAY_TEXTURE_LAYERS       0x88FF
#define GL_MIN_PROGRAM_TEXEL_OFFSET       0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET       0x8905
#define GL_CLAMP_READ_COLOR               0x891C
#define GL_FIXED_ONLY                     0x891D
#define GL_MAX_VARYING_COMPONENTS         0x8B4B
#define GL_TEXTURE_1D_ARRAY               0x8C18
#define GL_PROXY_TEXTURE_1D_ARRAY         0x8C19
#define GL_TEXTURE_2D_ARRAY               0x8C1A
#define GL_PROXY_TEXTURE_2D_ARRAY         0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY       0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY       0x8C1D
#define GL_R11F_G11F_B10F                 0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV   0x8C3B
#define GL_RGB9_E5                        0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV       0x8C3E
#define GL_TEXTURE_SHARED_SIZE            0x8C3F
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH 0x8C76
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE 0x8C7F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS 0x8C80
#define GL_TRANSFORM_FEEDBACK_VARYINGS    0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_START 0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE 0x8C85
#define GL_PRIMITIVES_GENERATED           0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN 0x8C88
#define GL_RASTERIZER_DISCARD             0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS 0x8C8B
#define GL_INTERLEAVED_ATTRIBS            0x8C8C
#define GL_SEPARATE_ATTRIBS               0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER      0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING 0x8C8F
#define GL_RGBA32UI                       0x8D70
#define GL_RGB32UI                        0x8D71
#define GL_RGBA16UI                       0x8D76
#define GL_RGB16UI                        0x8D77
#define GL_RGBA8UI                        0x8D7C
#define GL_RGB8UI                         0x8D7D
#define GL_RGBA32I                        0x8D82
#define GL_RGB32I                         0x8D83
#define GL_RGBA16I                        0x8D88
#define GL_RGB16I                         0x8D89
#define GL_RGBA8I                         0x8D8E
#define GL_RGB8I                          0x8D8F
#define GL_RED_INTEGER                    0x8D94
#define GL_GREEN_INTEGER                  0x8D95
#define GL_BLUE_INTEGER                   0x8D96
#define GL_RGB_INTEGER                    0x8D98
#define GL_RGBA_INTEGER                   0x8D99
#define GL_BGR_INTEGER                    0x8D9A
#define GL_BGRA_INTEGER                   0x8D9B
#define GL_SAMPLER_1D_ARRAY               0x8DC0
#define GL_SAMPLER_2D_ARRAY               0x8DC1
#define GL_SAMPLER_1D_ARRAY_SHADOW        0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW        0x8DC4
#define GL_SAMPLER_CUBE_SHADOW            0x8DC5
#define GL_UNSIGNED_INT_VEC2              0x8DC6
#define GL_UNSIGNED_INT_VEC3              0x8DC7
#define GL_UNSIGNED_INT_VEC4              0x8DC8
#define GL_INT_SAMPLER_1D                 0x8DC9
#define GL_INT_SAMPLER_2D                 0x8DCA
#define GL_INT_SAMPLER_3D                 0x8DCB
#define GL_INT_SAMPLER_CUBE               0x8DCC
#define GL_INT_SAMPLER_1D_ARRAY           0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY           0x8DCF
#define GL_UNSIGNED_INT_SAMPLER_1D        0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D        0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D        0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE      0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY  0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY  0x8DD7
#define GL_QUERY_WAIT                     0x8E13
#define GL_QUERY_NO_WAIT                  0x8E14
#define GL_QUERY_BY_REGION_WAIT           0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT        0x8E16
#define GL_BUFFER_ACCESS_FLAGS            0x911F
#define GL_BUFFER_MAP_LENGTH              0x9120
#define GL_BUFFER_MAP_OFFSET              0x9121
#define GL_DEPTH_COMPONENT32F             0x8CAC
#define GL_DEPTH32F_STENCIL8              0x8CAD
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV 0x8DAD
#define GL_INVALID_FRAMEBUFFER_OPERATION  0x0506
#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING 0x8210
#define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE 0x8211
#define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE 0x8212
#define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE 0x8213
#define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE 0x8214
#define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE 0x8215
#define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE 0x8216
#define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE 0x8217
#define GL_FRAMEBUFFER_DEFAULT            0x8218
#define GL_FRAMEBUFFER_UNDEFINED          0x8219
#define GL_DEPTH_STENCIL_ATTACHMENT       0x821A
#define GL_MAX_RENDERBUFFER_SIZE          0x84E8
#define GL_DEPTH_STENCIL                  0x84F9
#define GL_UNSIGNED_INT_24_8              0x84FA
#define GL_DEPTH24_STENCIL8               0x88F0
#define GL_TEXTURE_STENCIL_SIZE           0x88F1
#define GL_TEXTURE_RED_TYPE               0x8C10
#define GL_TEXTURE_GREEN_TYPE             0x8C11
#define GL_TEXTURE_BLUE_TYPE              0x8C12
#define GL_TEXTURE_ALPHA_TYPE             0x8C13
#define GL_TEXTURE_DEPTH_TYPE             0x8C16
#define GL_UNSIGNED_NORMALIZED            0x8C17
#define GL_FRAMEBUFFER_BINDING            0x8CA6
#define GL_DRAW_FRAMEBUFFER_BINDING       0x8CA6
#define GL_RENDERBUFFER_BINDING           0x8CA7
#define GL_READ_FRAMEBUFFER               0x8CA8
#define GL_DRAW_FRAMEBUFFER               0x8CA9
#define GL_READ_FRAMEBUFFER_BINDING       0x8CAA
#define GL_RENDERBUFFER_SAMPLES           0x8CAB
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE 0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME 0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL 0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER 0x8CD4
#define GL_FRAMEBUFFER_COMPLETE           0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT 0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER 0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER 0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED        0x8CDD
#define GL_MAX_COLOR_ATTACHMENTS          0x8CDF
#define GL_COLOR_ATTACHMENT0              0x8CE0
#define GL_COLOR_ATTACHMENT1              0x8CE1
#define GL_COLOR_ATTACHMENT2              0x8CE2
#define GL_COLOR_ATTACHMENT3              0x8CE3
#define GL_COLOR_ATTACHMENT4              0x8CE4
#define GL_COLOR_ATTACHMENT5              0x8CE5
#define GL_COLOR_ATTACHMENT6              0x8CE6
#define GL_COLOR_ATTACHMENT7              0x8CE7
#define GL_COLOR_ATTACHMENT8              0x8CE8
#define GL_COLOR_ATTACHMENT9              0x8CE9
#define GL_COLOR_ATTACHMENT10             0x8CEA
#define GL_COLOR_ATTACHMENT11             0x8CEB
#define GL_COLOR_ATTACHMENT12             0x8CEC
#define GL_COLOR_ATTACHMENT13             0x8CED
#define GL_COLOR_ATTACHMENT14             0x8CEE
#define GL_COLOR_ATTACHMENT15             0x8CEF
#define GL_COLOR_ATTACHMENT16             0x8CF0
#define GL_COLOR_ATTACHMENT17             0x8CF1
#define GL_COLOR_ATTACHMENT18             0x8CF2
#define GL_COLOR_ATTACHMENT19             0x8CF3
#define GL_COLOR_ATTACHMENT20             0x8CF4
#define GL_COLOR_ATTACHMENT21             0x8CF5
#define GL_COLOR_ATTACHMENT22             0x8CF6
#define GL_COLOR_ATTACHMENT23             0x8CF7
#define GL_COLOR_ATTACHMENT24             0x8CF8
#define GL_COLOR_ATTACHMENT25             0x8CF9
#define GL_COLOR_ATTACHMENT26             0x8CFA
#define GL_COLOR_ATTACHMENT27             0x8CFB
#define GL_COLOR_ATTACHMENT28             0x8CFC
#define GL_COLOR_ATTACHMENT29             0x8CFD
#define GL_COLOR_ATTACHMENT30             0x8CFE
#define GL_COLOR_ATTACHMENT31             0x8CFF
#define GL_DEPTH_ATTACHMENT               0x8D00
#define GL_STENCIL_ATTACHMENT             0x8D20
#define GL_FRAMEBUFFER                    0x8D40
#define GL_RENDERBUFFER                   0x8D41
#define GL_RENDERBUFFER_WIDTH             0x8D42
#define GL_RENDERBUFFER_HEIGHT            0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT   0x8D44
#define GL_STENCIL_INDEX1                 0x8D46
#define GL_STENCIL_INDEX4                 0x8D47
#define GL_STENCIL_INDEX8                 0x8D48
#define GL_STENCIL_INDEX16                0x8D49
#define GL_RENDERBUFFER_RED_SIZE          0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE        0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE         0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE        0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE        0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE      0x8D55
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE 0x8D56
#define GL_MAX_SAMPLES                    0x8D57
#define GL_FRAMEBUFFER_SRGB               0x8DB9
#define GL_HALF_FLOAT                     0x140B
#define GL_MAP_READ_BIT                   0x0001
#define GL_MAP_WRITE_BIT                  0x0002
#define GL_MAP_INVALIDATE_RANGE_BIT       0x0004
#define GL_MAP_INVALIDATE_BUFFER_BIT      0x0008
#define GL_MAP_FLUSH_EXPLICIT_BIT         0x0010
#define GL_MAP_UNSYNCHRONIZED_BIT         0x0020
#define GL_COMPRESSED_RED_RGTC1           0x8DBB
#define GL_COMPRESSED_SIGNED_RED_RGTC1    0x8DBC
#define GL_COMPRESSED_RG_RGTC2            0x8DBD
#define GL_COMPRESSED_SIGNED_RG_RGTC2     0x8DBE
#define GL_RG                             0x8227
#define GL_RG_INTEGER                     0x8228
#define GL_R8                             0x8229
#define GL_R16                            0x822A
#define GL_RG8                            0x822B
#define GL_RG16                           0x822C
#define GL_R16F                           0x822D
#define GL_R32F                           0x822E
#define GL_RG16F                          0x822F
#define GL_RG32F                          0x8230
#define GL_R8I                            0x8231
#define GL_R8UI                           0x8232
#define GL_R16I                           0x8233
#define GL_R16UI                          0x8234
#define GL_R32I                           0x8235
#define GL_R32UI                          0x8236
#define GL_RG8I                           0x8237
#define GL_RG8UI                          0x8238
#define GL_RG16I                          0x8239
#define GL_RG16UI                         0x823A
#define GL_RG32I                          0x823B
#define GL_RG32UI                         0x823C
#define GL_VERTEX_ARRAY_BINDING           0x85B5
    typedef void (APIENTRYP PFNGLCOLORMASKIPROC) (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
    typedef void (APIENTRYP PFNGLGETBOOLEANI_VPROC) (GLenum target, GLuint index, GLboolean *data);
    typedef void (APIENTRYP PFNGLGETINTEGERI_VPROC) (GLenum target, GLuint index, GLint *data);
    typedef void (APIENTRYP PFNGLENABLEIPROC) (GLenum target, GLuint index);
    typedef void (APIENTRYP PFNGLDISABLEIPROC) (GLenum target, GLuint index);
    typedef GLboolean (APIENTRYP PFNGLISENABLEDIPROC) (GLenum target, GLuint index);
    typedef void (APIENTRYP PFNGLBEGINTRANSFORMFEEDBACKPROC) (GLenum primitiveMode);
    typedef void (APIENTRYP PFNGLENDTRANSFORMFEEDBACKPROC) (void);
    typedef void (APIENTRYP PFNGLBINDBUFFERRANGEPROC) (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
    typedef void (APIENTRYP PFNGLBINDBUFFERBASEPROC) (GLenum target, GLuint index, GLuint buffer);
    typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKVARYINGSPROC) (GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
    typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKVARYINGPROC) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
    typedef void (APIENTRYP PFNGLCLAMPCOLORPROC) (GLenum target, GLenum clamp);
    typedef void (APIENTRYP PFNGLBEGINCONDITIONALRENDERPROC) (GLuint id, GLenum mode);
    typedef void (APIENTRYP PFNGLENDCONDITIONALRENDERPROC) (void);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBIPOINTERPROC) (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
    typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIIVPROC) (GLuint index, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIUIVPROC) (GLuint index, GLenum pname, GLuint *params);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IPROC) (GLuint index, GLint x);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IPROC) (GLuint index, GLint x, GLint y);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IPROC) (GLuint index, GLint x, GLint y, GLint z);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IPROC) (GLuint index, GLint x, GLint y, GLint z, GLint w);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIPROC) (GLuint index, GLuint x);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIPROC) (GLuint index, GLuint x, GLuint y);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIPROC) (GLuint index, GLuint x, GLuint y, GLuint z);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIPROC) (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IVPROC) (GLuint index, const GLint *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IVPROC) (GLuint index, const GLint *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IVPROC) (GLuint index, const GLint *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IVPROC) (GLuint index, const GLint *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIVPROC) (GLuint index, const GLuint *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIVPROC) (GLuint index, const GLuint *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIVPROC) (GLuint index, const GLuint *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIVPROC) (GLuint index, const GLuint *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBI4BVPROC) (GLuint index, const GLbyte *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBI4SVPROC) (GLuint index, const GLshort *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UBVPROC) (GLuint index, const GLubyte *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBI4USVPROC) (GLuint index, const GLushort *v);
    typedef void (APIENTRYP PFNGLGETUNIFORMUIVPROC) (GLuint program, GLint location, GLuint *params);
    typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONPROC) (GLuint program, GLuint color, const GLchar *name);
    typedef GLint (APIENTRYP PFNGLGETFRAGDATALOCATIONPROC) (GLuint program, const GLchar *name);
    typedef void (APIENTRYP PFNGLUNIFORM1UIPROC) (GLint location, GLuint v0);
    typedef void (APIENTRYP PFNGLUNIFORM2UIPROC) (GLint location, GLuint v0, GLuint v1);
    typedef void (APIENTRYP PFNGLUNIFORM3UIPROC) (GLint location, GLuint v0, GLuint v1, GLuint v2);
    typedef void (APIENTRYP PFNGLUNIFORM4UIPROC) (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
    typedef void (APIENTRYP PFNGLUNIFORM1UIVPROC) (GLint location, GLsizei count, const GLuint *value);
    typedef void (APIENTRYP PFNGLUNIFORM2UIVPROC) (GLint location, GLsizei count, const GLuint *value);
    typedef void (APIENTRYP PFNGLUNIFORM3UIVPROC) (GLint location, GLsizei count, const GLuint *value);
    typedef void (APIENTRYP PFNGLUNIFORM4UIVPROC) (GLint location, GLsizei count, const GLuint *value);
    typedef void (APIENTRYP PFNGLTEXPARAMETERIIVPROC) (GLenum target, GLenum pname, const GLint *params);
    typedef void (APIENTRYP PFNGLTEXPARAMETERIUIVPROC) (GLenum target, GLenum pname, const GLuint *params);
    typedef void (APIENTRYP PFNGLGETTEXPARAMETERIIVPROC) (GLenum target, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLGETTEXPARAMETERIUIVPROC) (GLenum target, GLenum pname, GLuint *params);
    typedef void (APIENTRYP PFNGLCLEARBUFFERIVPROC) (GLenum buffer, GLint drawbuffer, const GLint *value);
    typedef void (APIENTRYP PFNGLCLEARBUFFERUIVPROC) (GLenum buffer, GLint drawbuffer, const GLuint *value);
    typedef void (APIENTRYP PFNGLCLEARBUFFERFVPROC) (GLenum buffer, GLint drawbuffer, const GLfloat *value);
    typedef void (APIENTRYP PFNGLCLEARBUFFERFIPROC) (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
    typedef const GLubyte *(APIENTRYP PFNGLGETSTRINGIPROC) (GLenum name, GLuint index);
    typedef GLboolean (APIENTRYP PFNGLISRENDERBUFFERPROC) (GLuint renderbuffer);
    typedef void (APIENTRYP PFNGLBINDRENDERBUFFERPROC) (GLenum target, GLuint renderbuffer);
    typedef void (APIENTRYP PFNGLDELETERENDERBUFFERSPROC) (GLsizei n, const GLuint *renderbuffers);
    typedef void (APIENTRYP PFNGLGENRENDERBUFFERSPROC) (GLsizei n, GLuint *renderbuffers);
    typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEPROC) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
    typedef void (APIENTRYP PFNGLGETRENDERBUFFERPARAMETERIVPROC) (GLenum target, GLenum pname, GLint *params);
    typedef GLboolean (APIENTRYP PFNGLISFRAMEBUFFERPROC) (GLuint framebuffer);
    typedef void (APIENTRYP PFNGLBINDFRAMEBUFFERPROC) (GLenum target, GLuint framebuffer);
    typedef void (APIENTRYP PFNGLDELETEFRAMEBUFFERSPROC) (GLsizei n, const GLuint *framebuffers);
    typedef void (APIENTRYP PFNGLGENFRAMEBUFFERSPROC) (GLsizei n, GLuint *framebuffers);
    typedef GLenum (APIENTRYP PFNGLCHECKFRAMEBUFFERSTATUSPROC) (GLenum target);
    typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE1DPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
    typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE2DPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
    typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE3DPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
    typedef void (APIENTRYP PFNGLFRAMEBUFFERRENDERBUFFERPROC) (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
    typedef void (APIENTRYP PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC) (GLenum target, GLenum attachment, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLGENERATEMIPMAPPROC) (GLenum target);
    typedef void (APIENTRYP PFNGLBLITFRAMEBUFFERPROC) (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
    typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
    typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURELAYERPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
    typedef void *(APIENTRYP PFNGLMAPBUFFERRANGEPROC) (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
    typedef void (APIENTRYP PFNGLFLUSHMAPPEDBUFFERRANGEPROC) (GLenum target, GLintptr offset, GLsizeiptr length);
    typedef void (APIENTRYP PFNGLBINDVERTEXARRAYPROC) (GLuint array);
    typedef void (APIENTRYP PFNGLDELETEVERTEXARRAYSPROC) (GLsizei n, const GLuint *arrays);
    typedef void (APIENTRYP PFNGLGENVERTEXARRAYSPROC) (GLsizei n, GLuint *arrays);
    typedef GLboolean (APIENTRYP PFNGLISVERTEXARRAYPROC) (GLuint array);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glColorMaski (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
    GLAPI void APIENTRY glGetBooleani_v (GLenum target, GLuint index, GLboolean *data);
    GLAPI void APIENTRY glGetIntegeri_v (GLenum target, GLuint index, GLint *data);
    GLAPI void APIENTRY glEnablei (GLenum target, GLuint index);
    GLAPI void APIENTRY glDisablei (GLenum target, GLuint index);
    GLAPI GLboolean APIENTRY glIsEnabledi (GLenum target, GLuint index);
    GLAPI void APIENTRY glBeginTransformFeedback (GLenum primitiveMode);
    GLAPI void APIENTRY glEndTransformFeedback (void);
    GLAPI void APIENTRY glBindBufferRange (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
    GLAPI void APIENTRY glBindBufferBase (GLenum target, GLuint index, GLuint buffer);
    GLAPI void APIENTRY glTransformFeedbackVaryings (GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
    GLAPI void APIENTRY glGetTransformFeedbackVarying (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
    GLAPI void APIENTRY glClampColor (GLenum target, GLenum clamp);
    GLAPI void APIENTRY glBeginConditionalRender (GLuint id, GLenum mode);
    GLAPI void APIENTRY glEndConditionalRender (void);
    GLAPI void APIENTRY glVertexAttribIPointer (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
    GLAPI void APIENTRY glGetVertexAttribIiv (GLuint index, GLenum pname, GLint *params);
    GLAPI void APIENTRY glGetVertexAttribIuiv (GLuint index, GLenum pname, GLuint *params);
    GLAPI void APIENTRY glVertexAttribI1i (GLuint index, GLint x);
    GLAPI void APIENTRY glVertexAttribI2i (GLuint index, GLint x, GLint y);
    GLAPI void APIENTRY glVertexAttribI3i (GLuint index, GLint x, GLint y, GLint z);
    GLAPI void APIENTRY glVertexAttribI4i (GLuint index, GLint x, GLint y, GLint z, GLint w);
    GLAPI void APIENTRY glVertexAttribI1ui (GLuint index, GLuint x);
    GLAPI void APIENTRY glVertexAttribI2ui (GLuint index, GLuint x, GLuint y);
    GLAPI void APIENTRY glVertexAttribI3ui (GLuint index, GLuint x, GLuint y, GLuint z);
    GLAPI void APIENTRY glVertexAttribI4ui (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
    GLAPI void APIENTRY glVertexAttribI1iv (GLuint index, const GLint *v);
    GLAPI void APIENTRY glVertexAttribI2iv (GLuint index, const GLint *v);
    GLAPI void APIENTRY glVertexAttribI3iv (GLuint index, const GLint *v);
    GLAPI void APIENTRY glVertexAttribI4iv (GLuint index, const GLint *v);
    GLAPI void APIENTRY glVertexAttribI1uiv (GLuint index, const GLuint *v);
    GLAPI void APIENTRY glVertexAttribI2uiv (GLuint index, const GLuint *v);
    GLAPI void APIENTRY glVertexAttribI3uiv (GLuint index, const GLuint *v);
    GLAPI void APIENTRY glVertexAttribI4uiv (GLuint index, const GLuint *v);
    GLAPI void APIENTRY glVertexAttribI4bv (GLuint index, const GLbyte *v);
    GLAPI void APIENTRY glVertexAttribI4sv (GLuint index, const GLshort *v);
    GLAPI void APIENTRY glVertexAttribI4ubv (GLuint index, const GLubyte *v);
    GLAPI void APIENTRY glVertexAttribI4usv (GLuint index, const GLushort *v);
    GLAPI void APIENTRY glGetUniformuiv (GLuint program, GLint location, GLuint *params);
    GLAPI void APIENTRY glBindFragDataLocation (GLuint program, GLuint color, const GLchar *name);
    GLAPI GLint APIENTRY glGetFragDataLocation (GLuint program, const GLchar *name);
    GLAPI void APIENTRY glUniform1ui (GLint location, GLuint v0);
    GLAPI void APIENTRY glUniform2ui (GLint location, GLuint v0, GLuint v1);
    GLAPI void APIENTRY glUniform3ui (GLint location, GLuint v0, GLuint v1, GLuint v2);
    GLAPI void APIENTRY glUniform4ui (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
    GLAPI void APIENTRY glUniform1uiv (GLint location, GLsizei count, const GLuint *value);
    GLAPI void APIENTRY glUniform2uiv (GLint location, GLsizei count, const GLuint *value);
    GLAPI void APIENTRY glUniform3uiv (GLint location, GLsizei count, const GLuint *value);
    GLAPI void APIENTRY glUniform4uiv (GLint location, GLsizei count, const GLuint *value);
    GLAPI void APIENTRY glTexParameterIiv (GLenum target, GLenum pname, const GLint *params);
    GLAPI void APIENTRY glTexParameterIuiv (GLenum target, GLenum pname, const GLuint *params);
    GLAPI void APIENTRY glGetTexParameterIiv (GLenum target, GLenum pname, GLint *params);
    GLAPI void APIENTRY glGetTexParameterIuiv (GLenum target, GLenum pname, GLuint *params);
    GLAPI void APIENTRY glClearBufferiv (GLenum buffer, GLint drawbuffer, const GLint *value);
    GLAPI void APIENTRY glClearBufferuiv (GLenum buffer, GLint drawbuffer, const GLuint *value);
    GLAPI void APIENTRY glClearBufferfv (GLenum buffer, GLint drawbuffer, const GLfloat *value);
    GLAPI void APIENTRY glClearBufferfi (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
    GLAPI const GLubyte *APIENTRY glGetStringi (GLenum name, GLuint index);
    GLAPI GLboolean APIENTRY glIsRenderbuffer (GLuint renderbuffer);
    GLAPI void APIENTRY glBindRenderbuffer (GLenum target, GLuint renderbuffer);
    GLAPI void APIENTRY glDeleteRenderbuffers (GLsizei n, const GLuint *renderbuffers);
    GLAPI void APIENTRY glGenRenderbuffers (GLsizei n, GLuint *renderbuffers);
    GLAPI void APIENTRY glRenderbufferStorage (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
    GLAPI void APIENTRY glGetRenderbufferParameteriv (GLenum target, GLenum pname, GLint *params);
    GLAPI GLboolean APIENTRY glIsFramebuffer (GLuint framebuffer);
    GLAPI void APIENTRY glBindFramebuffer (GLenum target, GLuint framebuffer);
    GLAPI void APIENTRY glDeleteFramebuffers (GLsizei n, const GLuint *framebuffers);
    GLAPI void APIENTRY glGenFramebuffers (GLsizei n, GLuint *framebuffers);
    GLAPI GLenum APIENTRY glCheckFramebufferStatus (GLenum target);
    GLAPI void APIENTRY glFramebufferTexture1D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
    GLAPI void APIENTRY glFramebufferTexture2D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
    GLAPI void APIENTRY glFramebufferTexture3D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
    GLAPI void APIENTRY glFramebufferRenderbuffer (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
    GLAPI void APIENTRY glGetFramebufferAttachmentParameteriv (GLenum target, GLenum attachment, GLenum pname, GLint *params);
    GLAPI void APIENTRY glGenerateMipmap (GLenum target);
    GLAPI void APIENTRY glBlitFramebuffer (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
    GLAPI void APIENTRY glRenderbufferStorageMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
    GLAPI void APIENTRY glFramebufferTextureLayer (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
    GLAPI void *APIENTRY glMapBufferRange (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
    GLAPI void APIENTRY glFlushMappedBufferRange (GLenum target, GLintptr offset, GLsizeiptr length);
    GLAPI void APIENTRY glBindVertexArray (GLuint array);
    GLAPI void APIENTRY glDeleteVertexArrays (GLsizei n, const GLuint *arrays);
    GLAPI void APIENTRY glGenVertexArrays (GLsizei n, GLuint *arrays);
    GLAPI GLboolean APIENTRY glIsVertexArray (GLuint array);
#endif
#endif /* GL_VERSION_3_0 */
    
#ifndef GL_VERSION_3_1
#define GL_VERSION_3_1 1
#define GL_SAMPLER_2D_RECT                0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW         0x8B64
#define GL_SAMPLER_BUFFER                 0x8DC2
#define GL_INT_SAMPLER_2D_RECT            0x8DCD
#define GL_INT_SAMPLER_BUFFER             0x8DD0
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT   0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_BUFFER    0x8DD8
#define GL_TEXTURE_BUFFER                 0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE        0x8C2B
#define GL_TEXTURE_BINDING_BUFFER         0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING 0x8C2D
#define GL_TEXTURE_RECTANGLE              0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE      0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE        0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE     0x84F8
#define GL_R8_SNORM                       0x8F94
#define GL_RG8_SNORM                      0x8F95
#define GL_RGB8_SNORM                     0x8F96
#define GL_RGBA8_SNORM                    0x8F97
#define GL_R16_SNORM                      0x8F98
#define GL_RG16_SNORM                     0x8F99
#define GL_RGB16_SNORM                    0x8F9A
#define GL_RGBA16_SNORM                   0x8F9B
#define GL_SIGNED_NORMALIZED              0x8F9C
#define GL_PRIMITIVE_RESTART              0x8F9D
#define GL_PRIMITIVE_RESTART_INDEX        0x8F9E
#define GL_COPY_READ_BUFFER               0x8F36
#define GL_COPY_WRITE_BUFFER              0x8F37
#define GL_UNIFORM_BUFFER                 0x8A11
#define GL_UNIFORM_BUFFER_BINDING         0x8A28
#define GL_UNIFORM_BUFFER_START           0x8A29
#define GL_UNIFORM_BUFFER_SIZE            0x8A2A
#define GL_MAX_VERTEX_UNIFORM_BLOCKS      0x8A2B
#define GL_MAX_GEOMETRY_UNIFORM_BLOCKS    0x8A2C
#define GL_MAX_FRAGMENT_UNIFORM_BLOCKS    0x8A2D
#define GL_MAX_COMBINED_UNIFORM_BLOCKS    0x8A2E
#define GL_MAX_UNIFORM_BUFFER_BINDINGS    0x8A2F
#define GL_MAX_UNIFORM_BLOCK_SIZE         0x8A30
#define GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS 0x8A31
#define GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS 0x8A32
#define GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS 0x8A33
#define GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT 0x8A34
#define GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH 0x8A35
#define GL_ACTIVE_UNIFORM_BLOCKS          0x8A36
#define GL_UNIFORM_TYPE                   0x8A37
#define GL_UNIFORM_SIZE                   0x8A38
#define GL_UNIFORM_NAME_LENGTH            0x8A39
#define GL_UNIFORM_BLOCK_INDEX            0x8A3A
#define GL_UNIFORM_OFFSET                 0x8A3B
#define GL_UNIFORM_ARRAY_STRIDE           0x8A3C
#define GL_UNIFORM_MATRIX_STRIDE          0x8A3D
#define GL_UNIFORM_IS_ROW_MAJOR           0x8A3E
#define GL_UNIFORM_BLOCK_BINDING          0x8A3F
#define GL_UNIFORM_BLOCK_DATA_SIZE        0x8A40
#define GL_UNIFORM_BLOCK_NAME_LENGTH      0x8A41
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS  0x8A42
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES 0x8A43
#define GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER 0x8A44
#define GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER 0x8A45
#define GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER 0x8A46
#define GL_INVALID_INDEX                  0xFFFFFFFFu
    typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDPROC) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
    typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount);
    typedef void (APIENTRYP PFNGLTEXBUFFERPROC) (GLenum target, GLenum internalformat, GLuint buffer);
    typedef void (APIENTRYP PFNGLPRIMITIVERESTARTINDEXPROC) (GLuint index);
    typedef void (APIENTRYP PFNGLCOPYBUFFERSUBDATAPROC) (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
    typedef void (APIENTRYP PFNGLGETUNIFORMINDICESPROC) (GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices);
    typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMSIVPROC) (GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMNAMEPROC) (GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
    typedef GLuint (APIENTRYP PFNGLGETUNIFORMBLOCKINDEXPROC) (GLuint program, const GLchar *uniformBlockName);
    typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKIVPROC) (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC) (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
    typedef void (APIENTRYP PFNGLUNIFORMBLOCKBINDINGPROC) (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glDrawArraysInstanced (GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
    GLAPI void APIENTRY glDrawElementsInstanced (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount);
    GLAPI void APIENTRY glTexBuffer (GLenum target, GLenum internalformat, GLuint buffer);
    GLAPI void APIENTRY glPrimitiveRestartIndex (GLuint index);
    GLAPI void APIENTRY glCopyBufferSubData (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
    GLAPI void APIENTRY glGetUniformIndices (GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices);
    GLAPI void APIENTRY glGetActiveUniformsiv (GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
    GLAPI void APIENTRY glGetActiveUniformName (GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
    GLAPI GLuint APIENTRY glGetUniformBlockIndex (GLuint program, const GLchar *uniformBlockName);
    GLAPI void APIENTRY glGetActiveUniformBlockiv (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
    GLAPI void APIENTRY glGetActiveUniformBlockName (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
    GLAPI void APIENTRY glUniformBlockBinding (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
#endif
#endif /* GL_VERSION_3_1 */
    
#ifndef GL_VERSION_3_2
#define GL_VERSION_3_2 1
    typedef struct __GLsync *GLsync;
#ifndef GLEXT_64_TYPES_DEFINED
    /* This code block is duplicated in glxext.h, so must be protected */
#define GLEXT_64_TYPES_DEFINED
    /* Define int32_t, int64_t, and uint64_t types for UST/MSC */
    /* (as used in the GL_EXT_timer_query extension). */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#include <inttypes.h>
#elif defined(__sun__) || defined(__digital__)
#include <inttypes.h>
#if defined(__STDC__)
#if defined(__arch64__) || defined(_LP64)
    typedef long int int64_t;
    typedef unsigned long int uint64_t;
#else
    typedef long long int int64_t;
    typedef unsigned long long int uint64_t;
#endif /* __arch64__ */
#endif /* __STDC__ */
#elif defined( __VMS ) || defined(__sgi)
#include <inttypes.h>
#elif defined(__SCO__) || defined(__USLC__)
#include <stdint.h>
#elif defined(__UNIXOS2__) || defined(__SOL64__)
    typedef long int int32_t;
    typedef long long int int64_t;
    typedef unsigned long long int uint64_t;
#elif defined(_WIN32) && defined(__GNUC__)
#include <stdint.h>
#elif defined(_WIN32)
    typedef __int32 int32_t;
    typedef __int64 int64_t;
    typedef unsigned __int64 uint64_t;
#else
    /* Fallback if nothing above works */
#include <inttypes.h>
#endif
#endif
    typedef uint64_t GLuint64;
    typedef int64_t GLint64;
#define GL_CONTEXT_CORE_PROFILE_BIT       0x00000001
#define GL_CONTEXT_COMPATIBILITY_PROFILE_BIT 0x00000002
#define GL_LINES_ADJACENCY                0x000A
#define GL_LINE_STRIP_ADJACENCY           0x000B
#define GL_TRIANGLES_ADJACENCY            0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY       0x000D
#define GL_PROGRAM_POINT_SIZE             0x8642
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS 0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED 0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS 0x8DA8
#define GL_GEOMETRY_SHADER                0x8DD9
#define GL_GEOMETRY_VERTICES_OUT          0x8916
#define GL_GEOMETRY_INPUT_TYPE            0x8917
#define GL_GEOMETRY_OUTPUT_TYPE           0x8918
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS 0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES   0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS 0x8DE1
#define GL_MAX_VERTEX_OUTPUT_COMPONENTS   0x9122
#define GL_MAX_GEOMETRY_INPUT_COMPONENTS  0x9123
#define GL_MAX_GEOMETRY_OUTPUT_COMPONENTS 0x9124
#define GL_MAX_FRAGMENT_INPUT_COMPONENTS  0x9125
#define GL_CONTEXT_PROFILE_MASK           0x9126
#define GL_DEPTH_CLAMP                    0x864F
#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION 0x8E4C
#define GL_FIRST_VERTEX_CONVENTION        0x8E4D
#define GL_LAST_VERTEX_CONVENTION         0x8E4E
#define GL_PROVOKING_VERTEX               0x8E4F
#define GL_TEXTURE_CUBE_MAP_SEAMLESS      0x884F
#define GL_MAX_SERVER_WAIT_TIMEOUT        0x9111
#define GL_OBJECT_TYPE                    0x9112
#define GL_SYNC_CONDITION                 0x9113
#define GL_SYNC_STATUS                    0x9114
#define GL_SYNC_FLAGS                     0x9115
#define GL_SYNC_FENCE                     0x9116
#define GL_SYNC_GPU_COMMANDS_COMPLETE     0x9117
#define GL_UNSIGNALED                     0x9118
#define GL_SIGNALED                       0x9119
#define GL_ALREADY_SIGNALED               0x911A
#define GL_TIMEOUT_EXPIRED                0x911B
#define GL_CONDITION_SATISFIED            0x911C
#define GL_WAIT_FAILED                    0x911D
#define GL_TIMEOUT_IGNORED                0xFFFFFFFFFFFFFFFFull
#define GL_SYNC_FLUSH_COMMANDS_BIT        0x00000001
#define GL_SAMPLE_POSITION                0x8E50
#define GL_SAMPLE_MASK                    0x8E51
#define GL_SAMPLE_MASK_VALUE              0x8E52
#define GL_MAX_SAMPLE_MASK_WORDS          0x8E59
#define GL_TEXTURE_2D_MULTISAMPLE         0x9100
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE   0x9101
#define GL_TEXTURE_2D_MULTISAMPLE_ARRAY   0x9102
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9103
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE 0x9104
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY 0x9105
#define GL_TEXTURE_SAMPLES                0x9106
#define GL_TEXTURE_FIXED_SAMPLE_LOCATIONS 0x9107
#define GL_SAMPLER_2D_MULTISAMPLE         0x9108
#define GL_INT_SAMPLER_2D_MULTISAMPLE     0x9109
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE 0x910A
#define GL_SAMPLER_2D_MULTISAMPLE_ARRAY   0x910B
#define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910C
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910D
#define GL_MAX_COLOR_TEXTURE_SAMPLES      0x910E
#define GL_MAX_DEPTH_TEXTURE_SAMPLES      0x910F
#define GL_MAX_INTEGER_SAMPLES            0x9110
    typedef void (APIENTRYP PFNGLDRAWELEMENTSBASEVERTEXPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
    typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
    typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
    typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC) (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex);
    typedef void (APIENTRYP PFNGLPROVOKINGVERTEXPROC) (GLenum mode);
    typedef GLsync (APIENTRYP PFNGLFENCESYNCPROC) (GLenum condition, GLbitfield flags);
    typedef GLboolean (APIENTRYP PFNGLISSYNCPROC) (GLsync sync);
    typedef void (APIENTRYP PFNGLDELETESYNCPROC) (GLsync sync);
    typedef GLenum (APIENTRYP PFNGLCLIENTWAITSYNCPROC) (GLsync sync, GLbitfield flags, GLuint64 timeout);
    typedef void (APIENTRYP PFNGLWAITSYNCPROC) (GLsync sync, GLbitfield flags, GLuint64 timeout);
    typedef void (APIENTRYP PFNGLGETINTEGER64VPROC) (GLenum pname, GLint64 *data);
    typedef void (APIENTRYP PFNGLGETSYNCIVPROC) (GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
    typedef void (APIENTRYP PFNGLGETINTEGER64I_VPROC) (GLenum target, GLuint index, GLint64 *data);
    typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERI64VPROC) (GLenum target, GLenum pname, GLint64 *params);
    typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level);
    typedef void (APIENTRYP PFNGLTEXIMAGE2DMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
    typedef void (APIENTRYP PFNGLTEXIMAGE3DMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
    typedef void (APIENTRYP PFNGLGETMULTISAMPLEFVPROC) (GLenum pname, GLuint index, GLfloat *val);
    typedef void (APIENTRYP PFNGLSAMPLEMASKIPROC) (GLuint maskNumber, GLbitfield mask);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glDrawElementsBaseVertex (GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
    GLAPI void APIENTRY glDrawRangeElementsBaseVertex (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
    GLAPI void APIENTRY glDrawElementsInstancedBaseVertex (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
    GLAPI void APIENTRY glMultiDrawElementsBaseVertex (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex);
    GLAPI void APIENTRY glProvokingVertex (GLenum mode);
    GLAPI GLsync APIENTRY glFenceSync (GLenum condition, GLbitfield flags);
    GLAPI GLboolean APIENTRY glIsSync (GLsync sync);
    GLAPI void APIENTRY glDeleteSync (GLsync sync);
    GLAPI GLenum APIENTRY glClientWaitSync (GLsync sync, GLbitfield flags, GLuint64 timeout);
    GLAPI void APIENTRY glWaitSync (GLsync sync, GLbitfield flags, GLuint64 timeout);
    GLAPI void APIENTRY glGetInteger64v (GLenum pname, GLint64 *data);
    GLAPI void APIENTRY glGetSynciv (GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
    GLAPI void APIENTRY glGetInteger64i_v (GLenum target, GLuint index, GLint64 *data);
    GLAPI void APIENTRY glGetBufferParameteri64v (GLenum target, GLenum pname, GLint64 *params);
    GLAPI void APIENTRY glFramebufferTexture (GLenum target, GLenum attachment, GLuint texture, GLint level);
    GLAPI void APIENTRY glTexImage2DMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
    GLAPI void APIENTRY glTexImage3DMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
    GLAPI void APIENTRY glGetMultisamplefv (GLenum pname, GLuint index, GLfloat *val);
    GLAPI void APIENTRY glSampleMaski (GLuint maskNumber, GLbitfield mask);
#endif
#endif /* GL_VERSION_3_2 */
    
#ifndef GL_VERSION_3_3
#define GL_VERSION_3_3 1
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR    0x88FE
#define GL_SRC1_COLOR                     0x88F9
#define GL_ONE_MINUS_SRC1_COLOR           0x88FA
#define GL_ONE_MINUS_SRC1_ALPHA           0x88FB
#define GL_MAX_DUAL_SOURCE_DRAW_BUFFERS   0x88FC
#define GL_ANY_SAMPLES_PASSED             0x8C2F
#define GL_SAMPLER_BINDING                0x8919
#define GL_RGB10_A2UI                     0x906F
#define GL_TEXTURE_SWIZZLE_R              0x8E42
#define GL_TEXTURE_SWIZZLE_G              0x8E43
#define GL_TEXTURE_SWIZZLE_B              0x8E44
#define GL_TEXTURE_SWIZZLE_A              0x8E45
#define GL_TEXTURE_SWIZZLE_RGBA           0x8E46
#define GL_TIME_ELAPSED                   0x88BF
#define GL_TIMESTAMP                      0x8E28
#define GL_INT_2_10_10_10_REV             0x8D9F
    typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONINDEXEDPROC) (GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
    typedef GLint (APIENTRYP PFNGLGETFRAGDATAINDEXPROC) (GLuint program, const GLchar *name);
    typedef void (APIENTRYP PFNGLGENSAMPLERSPROC) (GLsizei count, GLuint *samplers);
    typedef void (APIENTRYP PFNGLDELETESAMPLERSPROC) (GLsizei count, const GLuint *samplers);
    typedef GLboolean (APIENTRYP PFNGLISSAMPLERPROC) (GLuint sampler);
    typedef void (APIENTRYP PFNGLBINDSAMPLERPROC) (GLuint unit, GLuint sampler);
    typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIPROC) (GLuint sampler, GLenum pname, GLint param);
    typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIVPROC) (GLuint sampler, GLenum pname, const GLint *param);
    typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFPROC) (GLuint sampler, GLenum pname, GLfloat param);
    typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFVPROC) (GLuint sampler, GLenum pname, const GLfloat *param);
    typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIIVPROC) (GLuint sampler, GLenum pname, const GLint *param);
    typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIUIVPROC) (GLuint sampler, GLenum pname, const GLuint *param);
    typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIVPROC) (GLuint sampler, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIIVPROC) (GLuint sampler, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERFVPROC) (GLuint sampler, GLenum pname, GLfloat *params);
    typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIUIVPROC) (GLuint sampler, GLenum pname, GLuint *params);
    typedef void (APIENTRYP PFNGLQUERYCOUNTERPROC) (GLuint id, GLenum target);
    typedef void (APIENTRYP PFNGLGETQUERYOBJECTI64VPROC) (GLuint id, GLenum pname, GLint64 *params);
    typedef void (APIENTRYP PFNGLGETQUERYOBJECTUI64VPROC) (GLuint id, GLenum pname, GLuint64 *params);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBDIVISORPROC) (GLuint index, GLuint divisor);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBP1UIPROC) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBP1UIVPROC) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBP2UIPROC) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBP2UIVPROC) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBP3UIPROC) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBP3UIVPROC) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBP4UIPROC) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBP4UIVPROC) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glBindFragDataLocationIndexed (GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
    GLAPI GLint APIENTRY glGetFragDataIndex (GLuint program, const GLchar *name);
    GLAPI void APIENTRY glGenSamplers (GLsizei count, GLuint *samplers);
    GLAPI void APIENTRY glDeleteSamplers (GLsizei count, const GLuint *samplers);
    GLAPI GLboolean APIENTRY glIsSampler (GLuint sampler);
    GLAPI void APIENTRY glBindSampler (GLuint unit, GLuint sampler);
    GLAPI void APIENTRY glSamplerParameteri (GLuint sampler, GLenum pname, GLint param);
    GLAPI void APIENTRY glSamplerParameteriv (GLuint sampler, GLenum pname, const GLint *param);
    GLAPI void APIENTRY glSamplerParameterf (GLuint sampler, GLenum pname, GLfloat param);
    GLAPI void APIENTRY glSamplerParameterfv (GLuint sampler, GLenum pname, const GLfloat *param);
    GLAPI void APIENTRY glSamplerParameterIiv (GLuint sampler, GLenum pname, const GLint *param);
    GLAPI void APIENTRY glSamplerParameterIuiv (GLuint sampler, GLenum pname, const GLuint *param);
    GLAPI void APIENTRY glGetSamplerParameteriv (GLuint sampler, GLenum pname, GLint *params);
    GLAPI void APIENTRY glGetSamplerParameterIiv (GLuint sampler, GLenum pname, GLint *params);
    GLAPI void APIENTRY glGetSamplerParameterfv (GLuint sampler, GLenum pname, GLfloat *params);
    GLAPI void APIENTRY glGetSamplerParameterIuiv (GLuint sampler, GLenum pname, GLuint *params);
    GLAPI void APIENTRY glQueryCounter (GLuint id, GLenum target);
    GLAPI void APIENTRY glGetQueryObjecti64v (GLuint id, GLenum pname, GLint64 *params);
    GLAPI void APIENTRY glGetQueryObjectui64v (GLuint id, GLenum pname, GLuint64 *params);
    GLAPI void APIENTRY glVertexAttribDivisor (GLuint index, GLuint divisor);
    GLAPI void APIENTRY glVertexAttribP1ui (GLuint index, GLenum type, GLboolean normalized, GLuint value);
    GLAPI void APIENTRY glVertexAttribP1uiv (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
    GLAPI void APIENTRY glVertexAttribP2ui (GLuint index, GLenum type, GLboolean normalized, GLuint value);
    GLAPI void APIENTRY glVertexAttribP2uiv (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
    GLAPI void APIENTRY glVertexAttribP3ui (GLuint index, GLenum type, GLboolean normalized, GLuint value);
    GLAPI void APIENTRY glVertexAttribP3uiv (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
    GLAPI void APIENTRY glVertexAttribP4ui (GLuint index, GLenum type, GLboolean normalized, GLuint value);
    GLAPI void APIENTRY glVertexAttribP4uiv (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
#endif
#endif /* GL_VERSION_3_3 */
    
#ifndef GL_VERSION_4_0
#define GL_VERSION_4_0 1
#define GL_SAMPLE_SHADING                 0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE       0x8C37
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5F
#define GL_TEXTURE_CUBE_MAP_ARRAY         0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY 0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY   0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY         0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW  0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY     0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY 0x900F
#define GL_DRAW_INDIRECT_BUFFER           0x8F3F
#define GL_DRAW_INDIRECT_BUFFER_BINDING   0x8F43
#define GL_GEOMETRY_SHADER_INVOCATIONS    0x887F
#define GL_MAX_GEOMETRY_SHADER_INVOCATIONS 0x8E5A
#define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET 0x8E5B
#define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET 0x8E5C
#define GL_FRAGMENT_INTERPOLATION_OFFSET_BITS 0x8E5D
#define GL_MAX_VERTEX_STREAMS             0x8E71
#define GL_DOUBLE_VEC2                    0x8FFC
#define GL_DOUBLE_VEC3                    0x8FFD
#define GL_DOUBLE_VEC4                    0x8FFE
#define GL_DOUBLE_MAT2                    0x8F46
#define GL_DOUBLE_MAT3                    0x8F47
#define GL_DOUBLE_MAT4                    0x8F48
#define GL_DOUBLE_MAT2x3                  0x8F49
#define GL_DOUBLE_MAT2x4                  0x8F4A
#define GL_DOUBLE_MAT3x2                  0x8F4B
#define GL_DOUBLE_MAT3x4                  0x8F4C
#define GL_DOUBLE_MAT4x2                  0x8F4D
#define GL_DOUBLE_MAT4x3                  0x8F4E
#define GL_ACTIVE_SUBROUTINES             0x8DE5
#define GL_ACTIVE_SUBROUTINE_UNIFORMS     0x8DE6
#define GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS 0x8E47
#define GL_ACTIVE_SUBROUTINE_MAX_LENGTH   0x8E48
#define GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH 0x8E49
#define GL_MAX_SUBROUTINES                0x8DE7
#define GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS 0x8DE8
#define GL_NUM_COMPATIBLE_SUBROUTINES     0x8E4A
#define GL_COMPATIBLE_SUBROUTINES         0x8E4B
#define GL_PATCHES                        0x000E
#define GL_PATCH_VERTICES                 0x8E72
#define GL_PATCH_DEFAULT_INNER_LEVEL      0x8E73
#define GL_PATCH_DEFAULT_OUTER_LEVEL      0x8E74
#define GL_TESS_CONTROL_OUTPUT_VERTICES   0x8E75
#define GL_TESS_GEN_MODE                  0x8E76
#define GL_TESS_GEN_SPACING               0x8E77
#define GL_TESS_GEN_VERTEX_ORDER          0x8E78
#define GL_TESS_GEN_POINT_MODE            0x8E79
#define GL_ISOLINES                       0x8E7A
#define GL_FRACTIONAL_ODD                 0x8E7B
#define GL_FRACTIONAL_EVEN                0x8E7C
#define GL_MAX_PATCH_VERTICES             0x8E7D
#define GL_MAX_TESS_GEN_LEVEL             0x8E7E
#define GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E7F
#define GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E80
#define GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS 0x8E81
#define GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS 0x8E82
#define GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS 0x8E83
#define GL_MAX_TESS_PATCH_COMPONENTS      0x8E84
#define GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS 0x8E85
#define GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS 0x8E86
#define GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS 0x8E89
#define GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS 0x8E8A
#define GL_MAX_TESS_CONTROL_INPUT_COMPONENTS 0x886C
#define GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS 0x886D
#define GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E1E
#define GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E1F
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER 0x84F0
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER 0x84F1
#define GL_TESS_EVALUATION_SHADER         0x8E87
#define GL_TESS_CONTROL_SHADER            0x8E88
#define GL_TRANSFORM_FEEDBACK             0x8E22
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED 0x8E23
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE 0x8E24
#define GL_TRANSFORM_FEEDBACK_BINDING     0x8E25
#define GL_MAX_TRANSFORM_FEEDBACK_BUFFERS 0x8E70
    typedef void (APIENTRYP PFNGLMINSAMPLESHADINGPROC) (GLfloat value);
    typedef void (APIENTRYP PFNGLBLENDEQUATIONIPROC) (GLuint buf, GLenum mode);
    typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEIPROC) (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
    typedef void (APIENTRYP PFNGLBLENDFUNCIPROC) (GLuint buf, GLenum src, GLenum dst);
    typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEIPROC) (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
    typedef void (APIENTRYP PFNGLDRAWARRAYSINDIRECTPROC) (GLenum mode, const void *indirect);
    typedef void (APIENTRYP PFNGLDRAWELEMENTSINDIRECTPROC) (GLenum mode, GLenum type, const void *indirect);
    typedef void (APIENTRYP PFNGLUNIFORM1DPROC) (GLint location, GLdouble x);
    typedef void (APIENTRYP PFNGLUNIFORM2DPROC) (GLint location, GLdouble x, GLdouble y);
    typedef void (APIENTRYP PFNGLUNIFORM3DPROC) (GLint location, GLdouble x, GLdouble y, GLdouble z);
    typedef void (APIENTRYP PFNGLUNIFORM4DPROC) (GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    typedef void (APIENTRYP PFNGLUNIFORM1DVPROC) (GLint location, GLsizei count, const GLdouble *value);
    typedef void (APIENTRYP PFNGLUNIFORM2DVPROC) (GLint location, GLsizei count, const GLdouble *value);
    typedef void (APIENTRYP PFNGLUNIFORM3DVPROC) (GLint location, GLsizei count, const GLdouble *value);
    typedef void (APIENTRYP PFNGLUNIFORM4DVPROC) (GLint location, GLsizei count, const GLdouble *value);
    typedef void (APIENTRYP PFNGLUNIFORMMATRIX2DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    typedef void (APIENTRYP PFNGLUNIFORMMATRIX3DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    typedef void (APIENTRYP PFNGLUNIFORMMATRIX4DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X3DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X4DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X2DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X4DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X2DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X3DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    typedef void (APIENTRYP PFNGLGETUNIFORMDVPROC) (GLuint program, GLint location, GLdouble *params);
    typedef GLint (APIENTRYP PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC) (GLuint program, GLenum shadertype, const GLchar *name);
    typedef GLuint (APIENTRYP PFNGLGETSUBROUTINEINDEXPROC) (GLuint program, GLenum shadertype, const GLchar *name);
    typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC) (GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
    typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC) (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
    typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINENAMEPROC) (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
    typedef void (APIENTRYP PFNGLUNIFORMSUBROUTINESUIVPROC) (GLenum shadertype, GLsizei count, const GLuint *indices);
    typedef void (APIENTRYP PFNGLGETUNIFORMSUBROUTINEUIVPROC) (GLenum shadertype, GLint location, GLuint *params);
    typedef void (APIENTRYP PFNGLGETPROGRAMSTAGEIVPROC) (GLuint program, GLenum shadertype, GLenum pname, GLint *values);
    typedef void (APIENTRYP PFNGLPATCHPARAMETERIPROC) (GLenum pname, GLint value);
    typedef void (APIENTRYP PFNGLPATCHPARAMETERFVPROC) (GLenum pname, const GLfloat *values);
    typedef void (APIENTRYP PFNGLBINDTRANSFORMFEEDBACKPROC) (GLenum target, GLuint id);
    typedef void (APIENTRYP PFNGLDELETETRANSFORMFEEDBACKSPROC) (GLsizei n, const GLuint *ids);
    typedef void (APIENTRYP PFNGLGENTRANSFORMFEEDBACKSPROC) (GLsizei n, GLuint *ids);
    typedef GLboolean (APIENTRYP PFNGLISTRANSFORMFEEDBACKPROC) (GLuint id);
    typedef void (APIENTRYP PFNGLPAUSETRANSFORMFEEDBACKPROC) (void);
    typedef void (APIENTRYP PFNGLRESUMETRANSFORMFEEDBACKPROC) (void);
    typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKPROC) (GLenum mode, GLuint id);
    typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC) (GLenum mode, GLuint id, GLuint stream);
    typedef void (APIENTRYP PFNGLBEGINQUERYINDEXEDPROC) (GLenum target, GLuint index, GLuint id);
    typedef void (APIENTRYP PFNGLENDQUERYINDEXEDPROC) (GLenum target, GLuint index);
    typedef void (APIENTRYP PFNGLGETQUERYINDEXEDIVPROC) (GLenum target, GLuint index, GLenum pname, GLint *params);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glMinSampleShading (GLfloat value);
    GLAPI void APIENTRY glBlendEquationi (GLuint buf, GLenum mode);
    GLAPI void APIENTRY glBlendEquationSeparatei (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
    GLAPI void APIENTRY glBlendFunci (GLuint buf, GLenum src, GLenum dst);
    GLAPI void APIENTRY glBlendFuncSeparatei (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
    GLAPI void APIENTRY glDrawArraysIndirect (GLenum mode, const void *indirect);
    GLAPI void APIENTRY glDrawElementsIndirect (GLenum mode, GLenum type, const void *indirect);
    GLAPI void APIENTRY glUniform1d (GLint location, GLdouble x);
    GLAPI void APIENTRY glUniform2d (GLint location, GLdouble x, GLdouble y);
    GLAPI void APIENTRY glUniform3d (GLint location, GLdouble x, GLdouble y, GLdouble z);
    GLAPI void APIENTRY glUniform4d (GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    GLAPI void APIENTRY glUniform1dv (GLint location, GLsizei count, const GLdouble *value);
    GLAPI void APIENTRY glUniform2dv (GLint location, GLsizei count, const GLdouble *value);
    GLAPI void APIENTRY glUniform3dv (GLint location, GLsizei count, const GLdouble *value);
    GLAPI void APIENTRY glUniform4dv (GLint location, GLsizei count, const GLdouble *value);
    GLAPI void APIENTRY glUniformMatrix2dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    GLAPI void APIENTRY glUniformMatrix3dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    GLAPI void APIENTRY glUniformMatrix4dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    GLAPI void APIENTRY glUniformMatrix2x3dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    GLAPI void APIENTRY glUniformMatrix2x4dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    GLAPI void APIENTRY glUniformMatrix3x2dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    GLAPI void APIENTRY glUniformMatrix3x4dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    GLAPI void APIENTRY glUniformMatrix4x2dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    GLAPI void APIENTRY glUniformMatrix4x3dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    GLAPI void APIENTRY glGetUniformdv (GLuint program, GLint location, GLdouble *params);
    GLAPI GLint APIENTRY glGetSubroutineUniformLocation (GLuint program, GLenum shadertype, const GLchar *name);
    GLAPI GLuint APIENTRY glGetSubroutineIndex (GLuint program, GLenum shadertype, const GLchar *name);
    GLAPI void APIENTRY glGetActiveSubroutineUniformiv (GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
    GLAPI void APIENTRY glGetActiveSubroutineUniformName (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
    GLAPI void APIENTRY glGetActiveSubroutineName (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
    GLAPI void APIENTRY glUniformSubroutinesuiv (GLenum shadertype, GLsizei count, const GLuint *indices);
    GLAPI void APIENTRY glGetUniformSubroutineuiv (GLenum shadertype, GLint location, GLuint *params);
    GLAPI void APIENTRY glGetProgramStageiv (GLuint program, GLenum shadertype, GLenum pname, GLint *values);
    GLAPI void APIENTRY glPatchParameteri (GLenum pname, GLint value);
    GLAPI void APIENTRY glPatchParameterfv (GLenum pname, const GLfloat *values);
    GLAPI void APIENTRY glBindTransformFeedback (GLenum target, GLuint id);
    GLAPI void APIENTRY glDeleteTransformFeedbacks (GLsizei n, const GLuint *ids);
    GLAPI void APIENTRY glGenTransformFeedbacks (GLsizei n, GLuint *ids);
    GLAPI GLboolean APIENTRY glIsTransformFeedback (GLuint id);
    GLAPI void APIENTRY glPauseTransformFeedback (void);
    GLAPI void APIENTRY glResumeTransformFeedback (void);
    GLAPI void APIENTRY glDrawTransformFeedback (GLenum mode, GLuint id);
    GLAPI void APIENTRY glDrawTransformFeedbackStream (GLenum mode, GLuint id, GLuint stream);
    GLAPI void APIENTRY glBeginQueryIndexed (GLenum target, GLuint index, GLuint id);
    GLAPI void APIENTRY glEndQueryIndexed (GLenum target, GLuint index);
    GLAPI void APIENTRY glGetQueryIndexediv (GLenum target, GLuint index, GLenum pname, GLint *params);
#endif
#endif /* GL_VERSION_4_0 */
    
#ifndef GL_VERSION_4_1
#define GL_VERSION_4_1 1
#define GL_FIXED                          0x140C
#define GL_IMPLEMENTATION_COLOR_READ_TYPE 0x8B9A
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT 0x8B9B
#define GL_LOW_FLOAT                      0x8DF0
#define GL_MEDIUM_FLOAT                   0x8DF1
#define GL_HIGH_FLOAT                     0x8DF2
#define GL_LOW_INT                        0x8DF3
#define GL_MEDIUM_INT                     0x8DF4
#define GL_HIGH_INT                       0x8DF5
#define GL_SHADER_COMPILER                0x8DFA
#define GL_SHADER_BINARY_FORMATS          0x8DF8
#define GL_NUM_SHADER_BINARY_FORMATS      0x8DF9
#define GL_MAX_VERTEX_UNIFORM_VECTORS     0x8DFB
#define GL_MAX_VARYING_VECTORS            0x8DFC
#define GL_MAX_FRAGMENT_UNIFORM_VECTORS   0x8DFD
#define GL_RGB565                         0x8D62
#define GL_PROGRAM_BINARY_RETRIEVABLE_HINT 0x8257
#define GL_PROGRAM_BINARY_LENGTH          0x8741
#define GL_NUM_PROGRAM_BINARY_FORMATS     0x87FE
#define GL_PROGRAM_BINARY_FORMATS         0x87FF
#define GL_VERTEX_SHADER_BIT              0x00000001
#define GL_FRAGMENT_SHADER_BIT            0x00000002
#define GL_GEOMETRY_SHADER_BIT            0x00000004
#define GL_TESS_CONTROL_SHADER_BIT        0x00000008
#define GL_TESS_EVALUATION_SHADER_BIT     0x00000010
#define GL_ALL_SHADER_BITS                0xFFFFFFFF
#define GL_PROGRAM_SEPARABLE              0x8258
#define GL_ACTIVE_PROGRAM                 0x8259
#define GL_PROGRAM_PIPELINE_BINDING       0x825A
#define GL_MAX_VIEWPORTS                  0x825B
#define GL_VIEWPORT_SUBPIXEL_BITS         0x825C
#define GL_VIEWPORT_BOUNDS_RANGE          0x825D
#define GL_LAYER_PROVOKING_VERTEX         0x825E
#define GL_VIEWPORT_INDEX_PROVOKING_VERTEX 0x825F
#define GL_UNDEFINED_VERTEX               0x8260
    typedef void (APIENTRYP PFNGLRELEASESHADERCOMPILERPROC) (void);
    typedef void (APIENTRYP PFNGLSHADERBINARYPROC) (GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length);
    typedef void (APIENTRYP PFNGLGETSHADERPRECISIONFORMATPROC) (GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
    typedef void (APIENTRYP PFNGLDEPTHRANGEFPROC) (GLfloat n, GLfloat f);
    typedef void (APIENTRYP PFNGLCLEARDEPTHFPROC) (GLfloat d);
    typedef void (APIENTRYP PFNGLGETPROGRAMBINARYPROC) (GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary);
    typedef void (APIENTRYP PFNGLPROGRAMBINARYPROC) (GLuint program, GLenum binaryFormat, const void *binary, GLsizei length);
    typedef void (APIENTRYP PFNGLPROGRAMPARAMETERIPROC) (GLuint program, GLenum pname, GLint value);
    typedef void (APIENTRYP PFNGLUSEPROGRAMSTAGESPROC) (GLuint pipeline, GLbitfield stages, GLuint program);
    typedef void (APIENTRYP PFNGLACTIVESHADERPROGRAMPROC) (GLuint pipeline, GLuint program);
    typedef GLuint (APIENTRYP PFNGLCREATESHADERPROGRAMVPROC) (GLenum type, GLsizei count, const GLchar *const*strings);
    typedef void (APIENTRYP PFNGLBINDPROGRAMPIPELINEPROC) (GLuint pipeline);
    typedef void (APIENTRYP PFNGLDELETEPROGRAMPIPELINESPROC) (GLsizei n, const GLuint *pipelines);
    typedef void (APIENTRYP PFNGLGENPROGRAMPIPELINESPROC) (GLsizei n, GLuint *pipelines);
    typedef GLboolean (APIENTRYP PFNGLISPROGRAMPIPELINEPROC) (GLuint pipeline);
    typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEIVPROC) (GLuint pipeline, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IPROC) (GLuint program, GLint location, GLint v0);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IVPROC) (GLuint program, GLint location, GLsizei count, const GLint *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FPROC) (GLuint program, GLint location, GLfloat v0);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DPROC) (GLuint program, GLint location, GLdouble v0);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIPROC) (GLuint program, GLint location, GLuint v0);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IPROC) (GLuint program, GLint location, GLint v0, GLint v1);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IVPROC) (GLuint program, GLint location, GLsizei count, const GLint *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DPROC) (GLuint program, GLint location, GLdouble v0, GLdouble v1);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIPROC) (GLuint program, GLint location, GLuint v0, GLuint v1);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IPROC) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IVPROC) (GLuint program, GLint location, GLsizei count, const GLint *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DPROC) (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIPROC) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IPROC) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IVPROC) (GLuint program, GLint location, GLsizei count, const GLint *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DPROC) (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIPROC) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPIPELINEPROC) (GLuint pipeline);
    typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEINFOLOGPROC) (GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DPROC) (GLuint index, GLdouble x);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DPROC) (GLuint index, GLdouble x, GLdouble y);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DVPROC) (GLuint index, const GLdouble *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DVPROC) (GLuint index, const GLdouble *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DVPROC) (GLuint index, const GLdouble *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DVPROC) (GLuint index, const GLdouble *v);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBLPOINTERPROC) (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
    typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLDVPROC) (GLuint index, GLenum pname, GLdouble *params);
    typedef void (APIENTRYP PFNGLVIEWPORTARRAYVPROC) (GLuint first, GLsizei count, const GLfloat *v);
    typedef void (APIENTRYP PFNGLVIEWPORTINDEXEDFPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
    typedef void (APIENTRYP PFNGLVIEWPORTINDEXEDFVPROC) (GLuint index, const GLfloat *v);
    typedef void (APIENTRYP PFNGLSCISSORARRAYVPROC) (GLuint first, GLsizei count, const GLint *v);
    typedef void (APIENTRYP PFNGLSCISSORINDEXEDPROC) (GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
    typedef void (APIENTRYP PFNGLSCISSORINDEXEDVPROC) (GLuint index, const GLint *v);
    typedef void (APIENTRYP PFNGLDEPTHRANGEARRAYVPROC) (GLuint first, GLsizei count, const GLdouble *v);
    typedef void (APIENTRYP PFNGLDEPTHRANGEINDEXEDPROC) (GLuint index, GLdouble n, GLdouble f);
    typedef void (APIENTRYP PFNGLGETFLOATI_VPROC) (GLenum target, GLuint index, GLfloat *data);
    typedef void (APIENTRYP PFNGLGETDOUBLEI_VPROC) (GLenum target, GLuint index, GLdouble *data);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glReleaseShaderCompiler (void);
    GLAPI void APIENTRY glShaderBinary (GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length);
    GLAPI void APIENTRY glGetShaderPrecisionFormat (GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
    GLAPI void APIENTRY glDepthRangef (GLfloat n, GLfloat f);
    GLAPI void APIENTRY glClearDepthf (GLfloat d);
    GLAPI void APIENTRY glGetProgramBinary (GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary);
    GLAPI void APIENTRY glProgramBinary (GLuint program, GLenum binaryFormat, const void *binary, GLsizei length);
    GLAPI void APIENTRY glProgramParameteri (GLuint program, GLenum pname, GLint value);
    GLAPI void APIENTRY glUseProgramStages (GLuint pipeline, GLbitfield stages, GLuint program);
    GLAPI void APIENTRY glActiveShaderProgram (GLuint pipeline, GLuint program);
    GLAPI GLuint APIENTRY glCreateShaderProgramv (GLenum type, GLsizei count, const GLchar *const*strings);
    GLAPI void APIENTRY glBindProgramPipeline (GLuint pipeline);
    GLAPI void APIENTRY glDeleteProgramPipelines (GLsizei n, const GLuint *pipelines);
    GLAPI void APIENTRY glGenProgramPipelines (GLsizei n, GLuint *pipelines);
    GLAPI GLboolean APIENTRY glIsProgramPipeline (GLuint pipeline);
    GLAPI void APIENTRY glGetProgramPipelineiv (GLuint pipeline, GLenum pname, GLint *params);
    GLAPI void APIENTRY glProgramUniform1i (GLuint program, GLint location, GLint v0);
    GLAPI void APIENTRY glProgramUniform1iv (GLuint program, GLint location, GLsizei count, const GLint *value);
    GLAPI void APIENTRY glProgramUniform1f (GLuint program, GLint location, GLfloat v0);
    GLAPI void APIENTRY glProgramUniform1fv (GLuint program, GLint location, GLsizei count, const GLfloat *value);
    GLAPI void APIENTRY glProgramUniform1d (GLuint program, GLint location, GLdouble v0);
    GLAPI void APIENTRY glProgramUniform1dv (GLuint program, GLint location, GLsizei count, const GLdouble *value);
    GLAPI void APIENTRY glProgramUniform1ui (GLuint program, GLint location, GLuint v0);
    GLAPI void APIENTRY glProgramUniform1uiv (GLuint program, GLint location, GLsizei count, const GLuint *value);
    GLAPI void APIENTRY glProgramUniform2i (GLuint program, GLint location, GLint v0, GLint v1);
    GLAPI void APIENTRY glProgramUniform2iv (GLuint program, GLint location, GLsizei count, const GLint *value);
    GLAPI void APIENTRY glProgramUniform2f (GLuint program, GLint location, GLfloat v0, GLfloat v1);
    GLAPI void APIENTRY glProgramUniform2fv (GLuint program, GLint location, GLsizei count, const GLfloat *value);
    GLAPI void APIENTRY glProgramUniform2d (GLuint program, GLint location, GLdouble v0, GLdouble v1);
    GLAPI void APIENTRY glProgramUniform2dv (GLuint program, GLint location, GLsizei count, const GLdouble *value);
    GLAPI void APIENTRY glProgramUniform2ui (GLuint program, GLint location, GLuint v0, GLuint v1);
    GLAPI void APIENTRY glProgramUniform2uiv (GLuint program, GLint location, GLsizei count, const GLuint *value);
    GLAPI void APIENTRY glProgramUniform3i (GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
    GLAPI void APIENTRY glProgramUniform3iv (GLuint program, GLint location, GLsizei count, const GLint *value);
    GLAPI void APIENTRY glProgramUniform3f (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
    GLAPI void APIENTRY glProgramUniform3fv (GLuint program, GLint location, GLsizei count, const GLfloat *value);
    GLAPI void APIENTRY glProgramUniform3d (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
    GLAPI void APIENTRY glProgramUniform3dv (GLuint program, GLint location, GLsizei count, const GLdouble *value);
    GLAPI void APIENTRY glProgramUniform3ui (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
    GLAPI void APIENTRY glProgramUniform3uiv (GLuint program, GLint location, GLsizei count, const GLuint *value);
    GLAPI void APIENTRY glProgramUniform4i (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
    GLAPI void APIENTRY glProgramUniform4iv (GLuint program, GLint location, GLsizei count, const GLint *value);
    GLAPI void APIENTRY glProgramUniform4f (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
    GLAPI void APIENTRY glProgramUniform4fv (GLuint program, GLint location, GLsizei count, const GLfloat *value);
    GLAPI void APIENTRY glProgramUniform4d (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
    GLAPI void APIENTRY glProgramUniform4dv (GLuint program, GLint location, GLsizei count, const GLdouble *value);
    GLAPI void APIENTRY glProgramUniform4ui (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
    GLAPI void APIENTRY glProgramUniform4uiv (GLuint program, GLint location, GLsizei count, const GLuint *value);
    GLAPI void APIENTRY glProgramUniformMatrix2fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    GLAPI void APIENTRY glProgramUniformMatrix3fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    GLAPI void APIENTRY glProgramUniformMatrix4fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    GLAPI void APIENTRY glProgramUniformMatrix2dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    GLAPI void APIENTRY glProgramUniformMatrix3dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    GLAPI void APIENTRY glProgramUniformMatrix4dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    GLAPI void APIENTRY glProgramUniformMatrix2x3fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    GLAPI void APIENTRY glProgramUniformMatrix3x2fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    GLAPI void APIENTRY glProgramUniformMatrix2x4fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    GLAPI void APIENTRY glProgramUniformMatrix4x2fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    GLAPI void APIENTRY glProgramUniformMatrix3x4fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    GLAPI void APIENTRY glProgramUniformMatrix4x3fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    GLAPI void APIENTRY glProgramUniformMatrix2x3dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    GLAPI void APIENTRY glProgramUniformMatrix3x2dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    GLAPI void APIENTRY glProgramUniformMatrix2x4dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    GLAPI void APIENTRY glProgramUniformMatrix4x2dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    GLAPI void APIENTRY glProgramUniformMatrix3x4dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    GLAPI void APIENTRY glProgramUniformMatrix4x3dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    GLAPI void APIENTRY glValidateProgramPipeline (GLuint pipeline);
    GLAPI void APIENTRY glGetProgramPipelineInfoLog (GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
    GLAPI void APIENTRY glVertexAttribL1d (GLuint index, GLdouble x);
    GLAPI void APIENTRY glVertexAttribL2d (GLuint index, GLdouble x, GLdouble y);
    GLAPI void APIENTRY glVertexAttribL3d (GLuint index, GLdouble x, GLdouble y, GLdouble z);
    GLAPI void APIENTRY glVertexAttribL4d (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    GLAPI void APIENTRY glVertexAttribL1dv (GLuint index, const GLdouble *v);
    GLAPI void APIENTRY glVertexAttribL2dv (GLuint index, const GLdouble *v);
    GLAPI void APIENTRY glVertexAttribL3dv (GLuint index, const GLdouble *v);
    GLAPI void APIENTRY glVertexAttribL4dv (GLuint index, const GLdouble *v);
    GLAPI void APIENTRY glVertexAttribLPointer (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
    GLAPI void APIENTRY glGetVertexAttribLdv (GLuint index, GLenum pname, GLdouble *params);
    GLAPI void APIENTRY glViewportArrayv (GLuint first, GLsizei count, const GLfloat *v);
    GLAPI void APIENTRY glViewportIndexedf (GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
    GLAPI void APIENTRY glViewportIndexedfv (GLuint index, const GLfloat *v);
    GLAPI void APIENTRY glScissorArrayv (GLuint first, GLsizei count, const GLint *v);
    GLAPI void APIENTRY glScissorIndexed (GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
    GLAPI void APIENTRY glScissorIndexedv (GLuint index, const GLint *v);
    GLAPI void APIENTRY glDepthRangeArrayv (GLuint first, GLsizei count, const GLdouble *v);
    GLAPI void APIENTRY glDepthRangeIndexed (GLuint index, GLdouble n, GLdouble f);
    GLAPI void APIENTRY glGetFloati_v (GLenum target, GLuint index, GLfloat *data);
    GLAPI void APIENTRY glGetDoublei_v (GLenum target, GLuint index, GLdouble *data);
#endif
#endif /* GL_VERSION_4_1 */
    
#ifndef GL_VERSION_4_2
#define GL_VERSION_4_2 1
#define GL_COPY_READ_BUFFER_BINDING       0x8F36
#define GL_COPY_WRITE_BUFFER_BINDING      0x8F37
#define GL_TRANSFORM_FEEDBACK_ACTIVE      0x8E24
#define GL_TRANSFORM_FEEDBACK_PAUSED      0x8E23
#define GL_UNPACK_COMPRESSED_BLOCK_WIDTH  0x9127
#define GL_UNPACK_COMPRESSED_BLOCK_HEIGHT 0x9128
#define GL_UNPACK_COMPRESSED_BLOCK_DEPTH  0x9129
#define GL_UNPACK_COMPRESSED_BLOCK_SIZE   0x912A
#define GL_PACK_COMPRESSED_BLOCK_WIDTH    0x912B
#define GL_PACK_COMPRESSED_BLOCK_HEIGHT   0x912C
#define GL_PACK_COMPRESSED_BLOCK_DEPTH    0x912D
#define GL_PACK_COMPRESSED_BLOCK_SIZE     0x912E
#define GL_NUM_SAMPLE_COUNTS              0x9380
#define GL_MIN_MAP_BUFFER_ALIGNMENT       0x90BC
#define GL_ATOMIC_COUNTER_BUFFER          0x92C0
#define GL_ATOMIC_COUNTER_BUFFER_BINDING  0x92C1
#define GL_ATOMIC_COUNTER_BUFFER_START    0x92C2
#define GL_ATOMIC_COUNTER_BUFFER_SIZE     0x92C3
#define GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE 0x92C4
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS 0x92C5
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES 0x92C6
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER 0x92C7
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER 0x92C8
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER 0x92C9
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER 0x92CA
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER 0x92CB
#define GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS 0x92CC
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS 0x92CD
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS 0x92CE
#define GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS 0x92CF
#define GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS 0x92D0
#define GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS 0x92D1
#define GL_MAX_VERTEX_ATOMIC_COUNTERS     0x92D2
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS 0x92D3
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS 0x92D4
#define GL_MAX_GEOMETRY_ATOMIC_COUNTERS   0x92D5
#define GL_MAX_FRAGMENT_ATOMIC_COUNTERS   0x92D6
#define GL_MAX_COMBINED_ATOMIC_COUNTERS   0x92D7
#define GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE 0x92D8
#define GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS 0x92DC
#define GL_ACTIVE_ATOMIC_COUNTER_BUFFERS  0x92D9
#define GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX 0x92DA
#define GL_UNSIGNED_INT_ATOMIC_COUNTER    0x92DB
#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT 0x00000001
#define GL_ELEMENT_ARRAY_BARRIER_BIT      0x00000002
#define GL_UNIFORM_BARRIER_BIT            0x00000004
#define GL_TEXTURE_FETCH_BARRIER_BIT      0x00000008
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT 0x00000020
#define GL_COMMAND_BARRIER_BIT            0x00000040
#define GL_PIXEL_BUFFER_BARRIER_BIT       0x00000080
#define GL_TEXTURE_UPDATE_BARRIER_BIT     0x00000100
#define GL_BUFFER_UPDATE_BARRIER_BIT      0x00000200
#define GL_FRAMEBUFFER_BARRIER_BIT        0x00000400
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT 0x00000800
#define GL_ATOMIC_COUNTER_BARRIER_BIT     0x00001000
#define GL_ALL_BARRIER_BITS               0xFFFFFFFF
#define GL_MAX_IMAGE_UNITS                0x8F38
#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS 0x8F39
#define GL_IMAGE_BINDING_NAME             0x8F3A
#define GL_IMAGE_BINDING_LEVEL            0x8F3B
#define GL_IMAGE_BINDING_LAYERED          0x8F3C
#define GL_IMAGE_BINDING_LAYER            0x8F3D
#define GL_IMAGE_BINDING_ACCESS           0x8F3E
#define GL_IMAGE_1D                       0x904C
#define GL_IMAGE_2D                       0x904D
#define GL_IMAGE_3D                       0x904E
#define GL_IMAGE_2D_RECT                  0x904F
#define GL_IMAGE_CUBE                     0x9050
#define GL_IMAGE_BUFFER                   0x9051
#define GL_IMAGE_1D_ARRAY                 0x9052
#define GL_IMAGE_2D_ARRAY                 0x9053
#define GL_IMAGE_CUBE_MAP_ARRAY           0x9054
#define GL_IMAGE_2D_MULTISAMPLE           0x9055
#define GL_IMAGE_2D_MULTISAMPLE_ARRAY     0x9056
#define GL_INT_IMAGE_1D                   0x9057
#define GL_INT_IMAGE_2D                   0x9058
#define GL_INT_IMAGE_3D                   0x9059
#define GL_INT_IMAGE_2D_RECT              0x905A
#define GL_INT_IMAGE_CUBE                 0x905B
#define GL_INT_IMAGE_BUFFER               0x905C
#define GL_INT_IMAGE_1D_ARRAY             0x905D
#define GL_INT_IMAGE_2D_ARRAY             0x905E
#define GL_INT_IMAGE_CUBE_MAP_ARRAY       0x905F
#define GL_INT_IMAGE_2D_MULTISAMPLE       0x9060
#define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x9061
#define GL_UNSIGNED_INT_IMAGE_1D          0x9062
#define GL_UNSIGNED_INT_IMAGE_2D          0x9063
#define GL_UNSIGNED_INT_IMAGE_3D          0x9064
#define GL_UNSIGNED_INT_IMAGE_2D_RECT     0x9065
#define GL_UNSIGNED_INT_IMAGE_CUBE        0x9066
#define GL_UNSIGNED_INT_IMAGE_BUFFER      0x9067
#define GL_UNSIGNED_INT_IMAGE_1D_ARRAY    0x9068
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY    0x9069
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY 0x906A
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE 0x906B
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x906C
#define GL_MAX_IMAGE_SAMPLES              0x906D
#define GL_IMAGE_BINDING_FORMAT           0x906E
#define GL_IMAGE_FORMAT_COMPATIBILITY_TYPE 0x90C7
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE 0x90C8
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS 0x90C9
#define GL_MAX_VERTEX_IMAGE_UNIFORMS      0x90CA
#define GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS 0x90CB
#define GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS 0x90CC
#define GL_MAX_GEOMETRY_IMAGE_UNIFORMS    0x90CD
#define GL_MAX_FRAGMENT_IMAGE_UNIFORMS    0x90CE
#define GL_MAX_COMBINED_IMAGE_UNIFORMS    0x90CF
#define GL_COMPRESSED_RGBA_BPTC_UNORM     0x8E8C
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM 0x8E8D
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT 0x8E8E
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT 0x8E8F
#define GL_TEXTURE_IMMUTABLE_FORMAT       0x912F
    typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
    typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance);
    typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
    typedef void (APIENTRYP PFNGLGETINTERNALFORMATIVPROC) (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params);
    typedef void (APIENTRYP PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC) (GLuint program, GLuint bufferIndex, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLBINDIMAGETEXTUREPROC) (GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
    typedef void (APIENTRYP PFNGLMEMORYBARRIERPROC) (GLbitfield barriers);
    typedef void (APIENTRYP PFNGLTEXSTORAGE1DPROC) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
    typedef void (APIENTRYP PFNGLTEXSTORAGE2DPROC) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
    typedef void (APIENTRYP PFNGLTEXSTORAGE3DPROC) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
    typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC) (GLenum mode, GLuint id, GLsizei instancecount);
    typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC) (GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glDrawArraysInstancedBaseInstance (GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
    GLAPI void APIENTRY glDrawElementsInstancedBaseInstance (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance);
    GLAPI void APIENTRY glDrawElementsInstancedBaseVertexBaseInstance (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
    GLAPI void APIENTRY glGetInternalformativ (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params);
    GLAPI void APIENTRY glGetActiveAtomicCounterBufferiv (GLuint program, GLuint bufferIndex, GLenum pname, GLint *params);
    GLAPI void APIENTRY glBindImageTexture (GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
    GLAPI void APIENTRY glMemoryBarrier (GLbitfield barriers);
    GLAPI void APIENTRY glTexStorage1D (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
    GLAPI void APIENTRY glTexStorage2D (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
    GLAPI void APIENTRY glTexStorage3D (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
    GLAPI void APIENTRY glDrawTransformFeedbackInstanced (GLenum mode, GLuint id, GLsizei instancecount);
    GLAPI void APIENTRY glDrawTransformFeedbackStreamInstanced (GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
#endif
#endif /* GL_VERSION_4_2 */
    
#ifndef GL_VERSION_4_3
#define GL_VERSION_4_3 1
    typedef void (APIENTRY  *GLDEBUGPROC)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
#define GL_NUM_SHADING_LANGUAGE_VERSIONS  0x82E9
#define GL_VERTEX_ATTRIB_ARRAY_LONG       0x874E
#define GL_COMPRESSED_RGB8_ETC2           0x9274
#define GL_COMPRESSED_SRGB8_ETC2          0x9275
#define GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9276
#define GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9277
#define GL_COMPRESSED_RGBA8_ETC2_EAC      0x9278
#define GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC 0x9279
#define GL_COMPRESSED_R11_EAC             0x9270
#define GL_COMPRESSED_SIGNED_R11_EAC      0x9271
#define GL_COMPRESSED_RG11_EAC            0x9272
#define GL_COMPRESSED_SIGNED_RG11_EAC     0x9273
#define GL_PRIMITIVE_RESTART_FIXED_INDEX  0x8D69
#define GL_ANY_SAMPLES_PASSED_CONSERVATIVE 0x8D6A
#define GL_MAX_ELEMENT_INDEX              0x8D6B
#define GL_COMPUTE_SHADER                 0x91B9
#define GL_MAX_COMPUTE_UNIFORM_BLOCKS     0x91BB
#define GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS 0x91BC
#define GL_MAX_COMPUTE_IMAGE_UNIFORMS     0x91BD
#define GL_MAX_COMPUTE_SHARED_MEMORY_SIZE 0x8262
#define GL_MAX_COMPUTE_UNIFORM_COMPONENTS 0x8263
#define GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS 0x8264
#define GL_MAX_COMPUTE_ATOMIC_COUNTERS    0x8265
#define GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS 0x8266
#define GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS 0x90EB
#define GL_MAX_COMPUTE_WORK_GROUP_COUNT   0x91BE
#define GL_MAX_COMPUTE_WORK_GROUP_SIZE    0x91BF
#define GL_COMPUTE_WORK_GROUP_SIZE        0x8267
#define GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER 0x90EC
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER 0x90ED
#define GL_DISPATCH_INDIRECT_BUFFER       0x90EE
#define GL_DISPATCH_INDIRECT_BUFFER_BINDING 0x90EF
#define GL_COMPUTE_SHADER_BIT             0x00000020
#define GL_DEBUG_OUTPUT_SYNCHRONOUS       0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH 0x8243
#define GL_DEBUG_CALLBACK_FUNCTION        0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM      0x8245
#define GL_DEBUG_SOURCE_API               0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM     0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER   0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY       0x8249
#define GL_DEBUG_SOURCE_APPLICATION       0x824A
#define GL_DEBUG_SOURCE_OTHER             0x824B
#define GL_DEBUG_TYPE_ERROR               0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR 0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR  0x824E
#define GL_DEBUG_TYPE_PORTABILITY         0x824F
#define GL_DEBUG_TYPE_PERFORMANCE         0x8250
#define GL_DEBUG_TYPE_OTHER               0x8251
#define GL_MAX_DEBUG_MESSAGE_LENGTH       0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES      0x9144
#define GL_DEBUG_LOGGED_MESSAGES          0x9145
#define GL_DEBUG_SEVERITY_HIGH            0x9146
#define GL_DEBUG_SEVERITY_MEDIUM          0x9147
#define GL_DEBUG_SEVERITY_LOW             0x9148
#define GL_DEBUG_TYPE_MARKER              0x8268
#define GL_DEBUG_TYPE_PUSH_GROUP          0x8269
#define GL_DEBUG_TYPE_POP_GROUP           0x826A
#define GL_DEBUG_SEVERITY_NOTIFICATION    0x826B
#define GL_MAX_DEBUG_GROUP_STACK_DEPTH    0x826C
#define GL_DEBUG_GROUP_STACK_DEPTH        0x826D
#define GL_BUFFER                         0x82E0
#define GL_SHADER                         0x82E1
#define GL_PROGRAM                        0x82E2
#define GL_QUERY                          0x82E3
#define GL_PROGRAM_PIPELINE               0x82E4
#define GL_SAMPLER                        0x82E6
#define GL_MAX_LABEL_LENGTH               0x82E8
#define GL_DEBUG_OUTPUT                   0x92E0
#define GL_CONTEXT_FLAG_DEBUG_BIT         0x00000002
#define GL_MAX_UNIFORM_LOCATIONS          0x826E
#define GL_FRAMEBUFFER_DEFAULT_WIDTH      0x9310
#define GL_FRAMEBUFFER_DEFAULT_HEIGHT     0x9311
#define GL_FRAMEBUFFER_DEFAULT_LAYERS     0x9312
#define GL_FRAMEBUFFER_DEFAULT_SAMPLES    0x9313
#define GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS 0x9314
#define GL_MAX_FRAMEBUFFER_WIDTH          0x9315
#define GL_MAX_FRAMEBUFFER_HEIGHT         0x9316
#define GL_MAX_FRAMEBUFFER_LAYERS         0x9317
#define GL_MAX_FRAMEBUFFER_SAMPLES        0x9318
#define GL_INTERNALFORMAT_SUPPORTED       0x826F
#define GL_INTERNALFORMAT_PREFERRED       0x8270
#define GL_INTERNALFORMAT_RED_SIZE        0x8271
#define GL_INTERNALFORMAT_GREEN_SIZE      0x8272
#define GL_INTERNALFORMAT_BLUE_SIZE       0x8273
#define GL_INTERNALFORMAT_ALPHA_SIZE      0x8274
#define GL_INTERNALFORMAT_DEPTH_SIZE      0x8275
#define GL_INTERNALFORMAT_STENCIL_SIZE    0x8276
#define GL_INTERNALFORMAT_SHARED_SIZE     0x8277
#define GL_INTERNALFORMAT_RED_TYPE        0x8278
#define GL_INTERNALFORMAT_GREEN_TYPE      0x8279
#define GL_INTERNALFORMAT_BLUE_TYPE       0x827A
#define GL_INTERNALFORMAT_ALPHA_TYPE      0x827B
#define GL_INTERNALFORMAT_DEPTH_TYPE      0x827C
#define GL_INTERNALFORMAT_STENCIL_TYPE    0x827D
#define GL_MAX_WIDTH                      0x827E
#define GL_MAX_HEIGHT                     0x827F
#define GL_MAX_DEPTH                      0x8280
#define GL_MAX_LAYERS                     0x8281
#define GL_MAX_COMBINED_DIMENSIONS        0x8282
#define GL_COLOR_COMPONENTS               0x8283
#define GL_DEPTH_COMPONENTS               0x8284
#define GL_STENCIL_COMPONENTS             0x8285
#define GL_COLOR_RENDERABLE               0x8286
#define GL_DEPTH_RENDERABLE               0x8287
#define GL_STENCIL_RENDERABLE             0x8288
#define GL_FRAMEBUFFER_RENDERABLE         0x8289
#define GL_FRAMEBUFFER_RENDERABLE_LAYERED 0x828A
#define GL_FRAMEBUFFER_BLEND              0x828B
#define GL_READ_PIXELS                    0x828C
#define GL_READ_PIXELS_FORMAT             0x828D
#define GL_READ_PIXELS_TYPE               0x828E
#define GL_TEXTURE_IMAGE_FORMAT           0x828F
#define GL_TEXTURE_IMAGE_TYPE             0x8290
#define GL_GET_TEXTURE_IMAGE_FORMAT       0x8291
#define GL_GET_TEXTURE_IMAGE_TYPE         0x8292
#define GL_MIPMAP                         0x8293
#define GL_MANUAL_GENERATE_MIPMAP         0x8294
#define GL_AUTO_GENERATE_MIPMAP           0x8295
#define GL_COLOR_ENCODING                 0x8296
#define GL_SRGB_READ                      0x8297
#define GL_SRGB_WRITE                     0x8298
#define GL_FILTER                         0x829A
#define GL_VERTEX_TEXTURE                 0x829B
#define GL_TESS_CONTROL_TEXTURE           0x829C
#define GL_TESS_EVALUATION_TEXTURE        0x829D
#define GL_GEOMETRY_TEXTURE               0x829E
#define GL_FRAGMENT_TEXTURE               0x829F
#define GL_COMPUTE_TEXTURE                0x82A0
#define GL_TEXTURE_SHADOW                 0x82A1
#define GL_TEXTURE_GATHER                 0x82A2
#define GL_TEXTURE_GATHER_SHADOW          0x82A3
#define GL_SHADER_IMAGE_LOAD              0x82A4
#define GL_SHADER_IMAGE_STORE             0x82A5
#define GL_SHADER_IMAGE_ATOMIC            0x82A6
#define GL_IMAGE_TEXEL_SIZE               0x82A7
#define GL_IMAGE_COMPATIBILITY_CLASS      0x82A8
#define GL_IMAGE_PIXEL_FORMAT             0x82A9
#define GL_IMAGE_PIXEL_TYPE               0x82AA
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST 0x82AC
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST 0x82AD
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE 0x82AE
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE 0x82AF
#define GL_TEXTURE_COMPRESSED_BLOCK_WIDTH 0x82B1
#define GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT 0x82B2
#define GL_TEXTURE_COMPRESSED_BLOCK_SIZE  0x82B3
#define GL_CLEAR_BUFFER                   0x82B4
#define GL_TEXTURE_VIEW                   0x82B5
#define GL_VIEW_COMPATIBILITY_CLASS       0x82B6
#define GL_FULL_SUPPORT                   0x82B7
#define GL_CAVEAT_SUPPORT                 0x82B8
#define GL_IMAGE_CLASS_4_X_32             0x82B9
#define GL_IMAGE_CLASS_2_X_32             0x82BA
#define GL_IMAGE_CLASS_1_X_32             0x82BB
#define GL_IMAGE_CLASS_4_X_16             0x82BC
#define GL_IMAGE_CLASS_2_X_16             0x82BD
#define GL_IMAGE_CLASS_1_X_16             0x82BE
#define GL_IMAGE_CLASS_4_X_8              0x82BF
#define GL_IMAGE_CLASS_2_X_8              0x82C0
#define GL_IMAGE_CLASS_1_X_8              0x82C1
#define GL_IMAGE_CLASS_11_11_10           0x82C2
#define GL_IMAGE_CLASS_10_10_10_2         0x82C3
#define GL_VIEW_CLASS_128_BITS            0x82C4
#define GL_VIEW_CLASS_96_BITS             0x82C5
#define GL_VIEW_CLASS_64_BITS             0x82C6
#define GL_VIEW_CLASS_48_BITS             0x82C7
#define GL_VIEW_CLASS_32_BITS             0x82C8
#define GL_VIEW_CLASS_24_BITS             0x82C9
#define GL_VIEW_CLASS_16_BITS             0x82CA
#define GL_VIEW_CLASS_8_BITS              0x82CB
#define GL_VIEW_CLASS_S3TC_DXT1_RGB       0x82CC
#define GL_VIEW_CLASS_S3TC_DXT1_RGBA      0x82CD
#define GL_VIEW_CLASS_S3TC_DXT3_RGBA      0x82CE
#define GL_VIEW_CLASS_S3TC_DXT5_RGBA      0x82CF
#define GL_VIEW_CLASS_RGTC1_RED           0x82D0
#define GL_VIEW_CLASS_RGTC2_RG            0x82D1
#define GL_VIEW_CLASS_BPTC_UNORM          0x82D2
#define GL_VIEW_CLASS_BPTC_FLOAT          0x82D3
#define GL_UNIFORM                        0x92E1
#define GL_UNIFORM_BLOCK                  0x92E2
#define GL_PROGRAM_INPUT                  0x92E3
#define GL_PROGRAM_OUTPUT                 0x92E4
#define GL_BUFFER_VARIABLE                0x92E5
#define GL_SHADER_STORAGE_BLOCK           0x92E6
#define GL_VERTEX_SUBROUTINE              0x92E8
#define GL_TESS_CONTROL_SUBROUTINE        0x92E9
#define GL_TESS_EVALUATION_SUBROUTINE     0x92EA
#define GL_GEOMETRY_SUBROUTINE            0x92EB
#define GL_FRAGMENT_SUBROUTINE            0x92EC
#define GL_COMPUTE_SUBROUTINE             0x92ED
#define GL_VERTEX_SUBROUTINE_UNIFORM      0x92EE
#define GL_TESS_CONTROL_SUBROUTINE_UNIFORM 0x92EF
#define GL_TESS_EVALUATION_SUBROUTINE_UNIFORM 0x92F0
#define GL_GEOMETRY_SUBROUTINE_UNIFORM    0x92F1
#define GL_FRAGMENT_SUBROUTINE_UNIFORM    0x92F2
#define GL_COMPUTE_SUBROUTINE_UNIFORM     0x92F3
#define GL_TRANSFORM_FEEDBACK_VARYING     0x92F4
#define GL_ACTIVE_RESOURCES               0x92F5
#define GL_MAX_NAME_LENGTH                0x92F6
#define GL_MAX_NUM_ACTIVE_VARIABLES       0x92F7
#define GL_MAX_NUM_COMPATIBLE_SUBROUTINES 0x92F8
#define GL_NAME_LENGTH                    0x92F9
#define GL_TYPE                           0x92FA
#define GL_ARRAY_SIZE                     0x92FB
#define GL_OFFSET                         0x92FC
#define GL_BLOCK_INDEX                    0x92FD
#define GL_ARRAY_STRIDE                   0x92FE
#define GL_MATRIX_STRIDE                  0x92FF
#define GL_IS_ROW_MAJOR                   0x9300
#define GL_ATOMIC_COUNTER_BUFFER_INDEX    0x9301
#define GL_BUFFER_BINDING                 0x9302
#define GL_BUFFER_DATA_SIZE               0x9303
#define GL_NUM_ACTIVE_VARIABLES           0x9304
#define GL_ACTIVE_VARIABLES               0x9305
#define GL_REFERENCED_BY_VERTEX_SHADER    0x9306
#define GL_REFERENCED_BY_TESS_CONTROL_SHADER 0x9307
#define GL_REFERENCED_BY_TESS_EVALUATION_SHADER 0x9308
#define GL_REFERENCED_BY_GEOMETRY_SHADER  0x9309
#define GL_REFERENCED_BY_FRAGMENT_SHADER  0x930A
#define GL_REFERENCED_BY_COMPUTE_SHADER   0x930B
#define GL_TOP_LEVEL_ARRAY_SIZE           0x930C
#define GL_TOP_LEVEL_ARRAY_STRIDE         0x930D
#define GL_LOCATION                       0x930E
#define GL_LOCATION_INDEX                 0x930F
#define GL_IS_PER_PATCH                   0x92E7
#define GL_SHADER_STORAGE_BUFFER          0x90D2
#define GL_SHADER_STORAGE_BUFFER_BINDING  0x90D3
#define GL_SHADER_STORAGE_BUFFER_START    0x90D4
#define GL_SHADER_STORAGE_BUFFER_SIZE     0x90D5
#define GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS 0x90D6
#define GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS 0x90D7
#define GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS 0x90D8
#define GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS 0x90D9
#define GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS 0x90DA
#define GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS 0x90DB
#define GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS 0x90DC
#define GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS 0x90DD
#define GL_MAX_SHADER_STORAGE_BLOCK_SIZE  0x90DE
#define GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT 0x90DF
#define GL_SHADER_STORAGE_BARRIER_BIT     0x00002000
#define GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES 0x8F39
#define GL_DEPTH_STENCIL_TEXTURE_MODE     0x90EA
#define GL_TEXTURE_BUFFER_OFFSET          0x919D
#define GL_TEXTURE_BUFFER_SIZE            0x919E
#define GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT 0x919F
#define GL_TEXTURE_VIEW_MIN_LEVEL         0x82DB
#define GL_TEXTURE_VIEW_NUM_LEVELS        0x82DC
#define GL_TEXTURE_VIEW_MIN_LAYER         0x82DD
#define GL_TEXTURE_VIEW_NUM_LAYERS        0x82DE
#define GL_TEXTURE_IMMUTABLE_LEVELS       0x82DF
#define GL_VERTEX_ATTRIB_BINDING          0x82D4
#define GL_VERTEX_ATTRIB_RELATIVE_OFFSET  0x82D5
#define GL_VERTEX_BINDING_DIVISOR         0x82D6
#define GL_VERTEX_BINDING_OFFSET          0x82D7
#define GL_VERTEX_BINDING_STRIDE          0x82D8
#define GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET 0x82D9
#define GL_MAX_VERTEX_ATTRIB_BINDINGS     0x82DA
#define GL_VERTEX_BINDING_BUFFER          0x8F4F
    typedef void (APIENTRYP PFNGLCLEARBUFFERDATAPROC) (GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data);
    typedef void (APIENTRYP PFNGLCLEARBUFFERSUBDATAPROC) (GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
    typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEPROC) (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
    typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEINDIRECTPROC) (GLintptr indirect);
    typedef void (APIENTRYP PFNGLCOPYIMAGESUBDATAPROC) (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
    typedef void (APIENTRYP PFNGLFRAMEBUFFERPARAMETERIPROC) (GLenum target, GLenum pname, GLint param);
    typedef void (APIENTRYP PFNGLGETFRAMEBUFFERPARAMETERIVPROC) (GLenum target, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLGETINTERNALFORMATI64VPROC) (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 *params);
    typedef void (APIENTRYP PFNGLINVALIDATETEXSUBIMAGEPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
    typedef void (APIENTRYP PFNGLINVALIDATETEXIMAGEPROC) (GLuint texture, GLint level);
    typedef void (APIENTRYP PFNGLINVALIDATEBUFFERSUBDATAPROC) (GLuint buffer, GLintptr offset, GLsizeiptr length);
    typedef void (APIENTRYP PFNGLINVALIDATEBUFFERDATAPROC) (GLuint buffer);
    typedef void (APIENTRYP PFNGLINVALIDATEFRAMEBUFFERPROC) (GLenum target, GLsizei numAttachments, const GLenum *attachments);
    typedef void (APIENTRYP PFNGLINVALIDATESUBFRAMEBUFFERPROC) (GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
    typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTPROC) (GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride);
    typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTPROC) (GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride);
    typedef void (APIENTRYP PFNGLGETPROGRAMINTERFACEIVPROC) (GLuint program, GLenum programInterface, GLenum pname, GLint *params);
    typedef GLuint (APIENTRYP PFNGLGETPROGRAMRESOURCEINDEXPROC) (GLuint program, GLenum programInterface, const GLchar *name);
    typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCENAMEPROC) (GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
    typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCEIVPROC) (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLint *params);
    typedef GLint (APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONPROC) (GLuint program, GLenum programInterface, const GLchar *name);
    typedef GLint (APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC) (GLuint program, GLenum programInterface, const GLchar *name);
    typedef void (APIENTRYP PFNGLSHADERSTORAGEBLOCKBINDINGPROC) (GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
    typedef void (APIENTRYP PFNGLTEXBUFFERRANGEPROC) (GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
    typedef void (APIENTRYP PFNGLTEXSTORAGE2DMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
    typedef void (APIENTRYP PFNGLTEXSTORAGE3DMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
    typedef void (APIENTRYP PFNGLTEXTUREVIEWPROC) (GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
    typedef void (APIENTRYP PFNGLBINDVERTEXBUFFERPROC) (GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBFORMATPROC) (GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBIFORMATPROC) (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBLFORMATPROC) (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBBINDINGPROC) (GLuint attribindex, GLuint bindingindex);
    typedef void (APIENTRYP PFNGLVERTEXBINDINGDIVISORPROC) (GLuint bindingindex, GLuint divisor);
    typedef void (APIENTRYP PFNGLDEBUGMESSAGECONTROLPROC) (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
    typedef void (APIENTRYP PFNGLDEBUGMESSAGEINSERTPROC) (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
    typedef void (APIENTRYP PFNGLDEBUGMESSAGECALLBACKPROC) (GLDEBUGPROC callback, const void *userParam);
    typedef GLuint (APIENTRYP PFNGLGETDEBUGMESSAGELOGPROC) (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
    typedef void (APIENTRYP PFNGLPUSHDEBUGGROUPPROC) (GLenum source, GLuint id, GLsizei length, const GLchar *message);
    typedef void (APIENTRYP PFNGLPOPDEBUGGROUPPROC) (void);
    typedef void (APIENTRYP PFNGLOBJECTLABELPROC) (GLenum identifier, GLuint name, GLsizei length, const GLchar *label);
    typedef void (APIENTRYP PFNGLGETOBJECTLABELPROC) (GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label);
    typedef void (APIENTRYP PFNGLOBJECTPTRLABELPROC) (const void *ptr, GLsizei length, const GLchar *label);
    typedef void (APIENTRYP PFNGLGETOBJECTPTRLABELPROC) (const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glClearBufferData (GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data);
    GLAPI void APIENTRY glClearBufferSubData (GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
    GLAPI void APIENTRY glDispatchCompute (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
    GLAPI void APIENTRY glDispatchComputeIndirect (GLintptr indirect);
    GLAPI void APIENTRY glCopyImageSubData (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
    GLAPI void APIENTRY glFramebufferParameteri (GLenum target, GLenum pname, GLint param);
    GLAPI void APIENTRY glGetFramebufferParameteriv (GLenum target, GLenum pname, GLint *params);
    GLAPI void APIENTRY glGetInternalformati64v (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 *params);
    GLAPI void APIENTRY glInvalidateTexSubImage (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
    GLAPI void APIENTRY glInvalidateTexImage (GLuint texture, GLint level);
    GLAPI void APIENTRY glInvalidateBufferSubData (GLuint buffer, GLintptr offset, GLsizeiptr length);
    GLAPI void APIENTRY glInvalidateBufferData (GLuint buffer);
    GLAPI void APIENTRY glInvalidateFramebuffer (GLenum target, GLsizei numAttachments, const GLenum *attachments);
    GLAPI void APIENTRY glInvalidateSubFramebuffer (GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
    GLAPI void APIENTRY glMultiDrawArraysIndirect (GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride);
    GLAPI void APIENTRY glMultiDrawElementsIndirect (GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride);
    GLAPI void APIENTRY glGetProgramInterfaceiv (GLuint program, GLenum programInterface, GLenum pname, GLint *params);
    GLAPI GLuint APIENTRY glGetProgramResourceIndex (GLuint program, GLenum programInterface, const GLchar *name);
    GLAPI void APIENTRY glGetProgramResourceName (GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
    GLAPI void APIENTRY glGetProgramResourceiv (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLint *params);
    GLAPI GLint APIENTRY glGetProgramResourceLocation (GLuint program, GLenum programInterface, const GLchar *name);
    GLAPI GLint APIENTRY glGetProgramResourceLocationIndex (GLuint program, GLenum programInterface, const GLchar *name);
    GLAPI void APIENTRY glShaderStorageBlockBinding (GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
    GLAPI void APIENTRY glTexBufferRange (GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
    GLAPI void APIENTRY glTexStorage2DMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
    GLAPI void APIENTRY glTexStorage3DMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
    GLAPI void APIENTRY glTextureView (GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
    GLAPI void APIENTRY glBindVertexBuffer (GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
    GLAPI void APIENTRY glVertexAttribFormat (GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
    GLAPI void APIENTRY glVertexAttribIFormat (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
    GLAPI void APIENTRY glVertexAttribLFormat (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
    GLAPI void APIENTRY glVertexAttribBinding (GLuint attribindex, GLuint bindingindex);
    GLAPI void APIENTRY glVertexBindingDivisor (GLuint bindingindex, GLuint divisor);
    GLAPI void APIENTRY glDebugMessageControl (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
    GLAPI void APIENTRY glDebugMessageInsert (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
    GLAPI void APIENTRY glDebugMessageCallback (GLDEBUGPROC callback, const void *userParam);
    GLAPI GLuint APIENTRY glGetDebugMessageLog (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
    GLAPI void APIENTRY glPushDebugGroup (GLenum source, GLuint id, GLsizei length, const GLchar *message);
    GLAPI void APIENTRY glPopDebugGroup (void);
    GLAPI void APIENTRY glObjectLabel (GLenum identifier, GLuint name, GLsizei length, const GLchar *label);
    GLAPI void APIENTRY glGetObjectLabel (GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label);
    GLAPI void APIENTRY glObjectPtrLabel (const void *ptr, GLsizei length, const GLchar *label);
    GLAPI void APIENTRY glGetObjectPtrLabel (const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label);
#endif
#endif /* GL_VERSION_4_3 */
    
#ifndef GL_VERSION_4_4
#define GL_VERSION_4_4 1
#define GL_MAX_VERTEX_ATTRIB_STRIDE       0x82E5
#define GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED 0x8221
#define GL_TEXTURE_BUFFER_BINDING         0x8C2A
#define GL_MAP_PERSISTENT_BIT             0x0040
#define GL_MAP_COHERENT_BIT               0x0080
#define GL_DYNAMIC_STORAGE_BIT            0x0100
#define GL_CLIENT_STORAGE_BIT             0x0200
#define GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT 0x00004000
#define GL_BUFFER_IMMUTABLE_STORAGE       0x821F
#define GL_BUFFER_STORAGE_FLAGS           0x8220
#define GL_CLEAR_TEXTURE                  0x9365
#define GL_LOCATION_COMPONENT             0x934A
#define GL_TRANSFORM_FEEDBACK_BUFFER_INDEX 0x934B
#define GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE 0x934C
#define GL_QUERY_BUFFER                   0x9192
#define GL_QUERY_BUFFER_BARRIER_BIT       0x00008000
#define GL_QUERY_BUFFER_BINDING           0x9193
#define GL_QUERY_RESULT_NO_WAIT           0x9194
#define GL_MIRROR_CLAMP_TO_EDGE           0x8743
    typedef void (APIENTRYP PFNGLBUFFERSTORAGEPROC) (GLenum target, GLsizeiptr size, const void *data, GLbitfield flags);
    typedef void (APIENTRYP PFNGLCLEARTEXIMAGEPROC) (GLuint texture, GLint level, GLenum format, GLenum type, const void *data);
    typedef void (APIENTRYP PFNGLCLEARTEXSUBIMAGEPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data);
    typedef void (APIENTRYP PFNGLBINDBUFFERSBASEPROC) (GLenum target, GLuint first, GLsizei count, const GLuint *buffers);
    typedef void (APIENTRYP PFNGLBINDBUFFERSRANGEPROC) (GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes);
    typedef void (APIENTRYP PFNGLBINDTEXTURESPROC) (GLuint first, GLsizei count, const GLuint *textures);
    typedef void (APIENTRYP PFNGLBINDSAMPLERSPROC) (GLuint first, GLsizei count, const GLuint *samplers);
    typedef void (APIENTRYP PFNGLBINDIMAGETEXTURESPROC) (GLuint first, GLsizei count, const GLuint *textures);
    typedef void (APIENTRYP PFNGLBINDVERTEXBUFFERSPROC) (GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glBufferStorage (GLenum target, GLsizeiptr size, const void *data, GLbitfield flags);
    GLAPI void APIENTRY glClearTexImage (GLuint texture, GLint level, GLenum format, GLenum type, const void *data);
    GLAPI void APIENTRY glClearTexSubImage (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data);
    GLAPI void APIENTRY glBindBuffersBase (GLenum target, GLuint first, GLsizei count, const GLuint *buffers);
    GLAPI void APIENTRY glBindBuffersRange (GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes);
    GLAPI void APIENTRY glBindTextures (GLuint first, GLsizei count, const GLuint *textures);
    GLAPI void APIENTRY glBindSamplers (GLuint first, GLsizei count, const GLuint *samplers);
    GLAPI void APIENTRY glBindImageTextures (GLuint first, GLsizei count, const GLuint *textures);
    GLAPI void APIENTRY glBindVertexBuffers (GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
#endif
#endif /* GL_VERSION_4_4 */
    
#ifndef GL_VERSION_4_5
#define GL_VERSION_4_5 1
#define GL_CONTEXT_LOST                   0x0507
#define GL_NEGATIVE_ONE_TO_ONE            0x935E
#define GL_ZERO_TO_ONE                    0x935F
#define GL_CLIP_ORIGIN                    0x935C
#define GL_CLIP_DEPTH_MODE                0x935D
#define GL_QUERY_WAIT_INVERTED            0x8E17
#define GL_QUERY_NO_WAIT_INVERTED         0x8E18
#define GL_QUERY_BY_REGION_WAIT_INVERTED  0x8E19
#define GL_QUERY_BY_REGION_NO_WAIT_INVERTED 0x8E1A
#define GL_MAX_CULL_DISTANCES             0x82F9
#define GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES 0x82FA
#define GL_TEXTURE_TARGET                 0x1006
#define GL_QUERY_TARGET                   0x82EA
#define GL_GUILTY_CONTEXT_RESET           0x8253
#define GL_INNOCENT_CONTEXT_RESET         0x8254
#define GL_UNKNOWN_CONTEXT_RESET          0x8255
#define GL_RESET_NOTIFICATION_STRATEGY    0x8256
#define GL_LOSE_CONTEXT_ON_RESET          0x8252
#define GL_NO_RESET_NOTIFICATION          0x8261
#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT 0x00000004
#define GL_CONTEXT_RELEASE_BEHAVIOR       0x82FB
#define GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH 0x82FC
    typedef void (APIENTRYP PFNGLCLIPCONTROLPROC) (GLenum origin, GLenum depth);
    typedef void (APIENTRYP PFNGLCREATETRANSFORMFEEDBACKSPROC) (GLsizei n, GLuint *ids);
    typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC) (GLuint xfb, GLuint index, GLuint buffer);
    typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC) (GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
    typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKIVPROC) (GLuint xfb, GLenum pname, GLint *param);
    typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKI_VPROC) (GLuint xfb, GLenum pname, GLuint index, GLint *param);
    typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKI64_VPROC) (GLuint xfb, GLenum pname, GLuint index, GLint64 *param);
    typedef void (APIENTRYP PFNGLCREATEBUFFERSPROC) (GLsizei n, GLuint *buffers);
    typedef void (APIENTRYP PFNGLNAMEDBUFFERSTORAGEPROC) (GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
    typedef void (APIENTRYP PFNGLNAMEDBUFFERDATAPROC) (GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
    typedef void (APIENTRYP PFNGLNAMEDBUFFERSUBDATAPROC) (GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
    typedef void (APIENTRYP PFNGLCOPYNAMEDBUFFERSUBDATAPROC) (GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
    typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERDATAPROC) (GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
    typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERSUBDATAPROC) (GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
    typedef void *(APIENTRYP PFNGLMAPNAMEDBUFFERPROC) (GLuint buffer, GLenum access);
    typedef void *(APIENTRYP PFNGLMAPNAMEDBUFFERRANGEPROC) (GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
    typedef GLboolean (APIENTRYP PFNGLUNMAPNAMEDBUFFERPROC) (GLuint buffer);
    typedef void (APIENTRYP PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC) (GLuint buffer, GLintptr offset, GLsizeiptr length);
    typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERIVPROC) (GLuint buffer, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERI64VPROC) (GLuint buffer, GLenum pname, GLint64 *params);
    typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPOINTERVPROC) (GLuint buffer, GLenum pname, void **params);
    typedef void (APIENTRYP PFNGLGETNAMEDBUFFERSUBDATAPROC) (GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
    typedef void (APIENTRYP PFNGLCREATEFRAMEBUFFERSPROC) (GLsizei n, GLuint *framebuffers);
    typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC) (GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
    typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC) (GLuint framebuffer, GLenum pname, GLint param);
    typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREPROC) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
    typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
    typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC) (GLuint framebuffer, GLenum buf);
    typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC) (GLuint framebuffer, GLsizei n, const GLenum *bufs);
    typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC) (GLuint framebuffer, GLenum src);
    typedef void (APIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC) (GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments);
    typedef void (APIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC) (GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
    typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERIVPROC) (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value);
    typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC) (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value);
    typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFVPROC) (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value);
    typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFIPROC) (GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
    typedef void (APIENTRYP PFNGLBLITNAMEDFRAMEBUFFERPROC) (GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
    typedef GLenum (APIENTRYP PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC) (GLuint framebuffer, GLenum target);
    typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC) (GLuint framebuffer, GLenum pname, GLint *param);
    typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC) (GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLCREATERENDERBUFFERSPROC) (GLsizei n, GLuint *renderbuffers);
    typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEPROC) (GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
    typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC) (GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
    typedef void (APIENTRYP PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC) (GLuint renderbuffer, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLCREATETEXTURESPROC) (GLenum target, GLsizei n, GLuint *textures);
    typedef void (APIENTRYP PFNGLTEXTUREBUFFERPROC) (GLuint texture, GLenum internalformat, GLuint buffer);
    typedef void (APIENTRYP PFNGLTEXTUREBUFFERRANGEPROC) (GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
    typedef void (APIENTRYP PFNGLTEXTURESTORAGE1DPROC) (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
    typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DPROC) (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
    typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DPROC) (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
    typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC) (GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
    typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC) (GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
    typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE1DPROC) (GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
    typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE2DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
    typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE3DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
    typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC) (GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
    typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
    typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
    typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE1DPROC) (GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
    typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE2DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE3DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFPROC) (GLuint texture, GLenum pname, GLfloat param);
    typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFVPROC) (GLuint texture, GLenum pname, const GLfloat *param);
    typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIPROC) (GLuint texture, GLenum pname, GLint param);
    typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIIVPROC) (GLuint texture, GLenum pname, const GLint *params);
    typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIUIVPROC) (GLuint texture, GLenum pname, const GLuint *params);
    typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIVPROC) (GLuint texture, GLenum pname, const GLint *param);
    typedef void (APIENTRYP PFNGLGENERATETEXTUREMIPMAPPROC) (GLuint texture);
    typedef void (APIENTRYP PFNGLBINDTEXTUREUNITPROC) (GLuint unit, GLuint texture);
    typedef void (APIENTRYP PFNGLGETTEXTUREIMAGEPROC) (GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
    typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC) (GLuint texture, GLint level, GLsizei bufSize, void *pixels);
    typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERFVPROC) (GLuint texture, GLint level, GLenum pname, GLfloat *params);
    typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERIVPROC) (GLuint texture, GLint level, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERFVPROC) (GLuint texture, GLenum pname, GLfloat *params);
    typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIIVPROC) (GLuint texture, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIUIVPROC) (GLuint texture, GLenum pname, GLuint *params);
    typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIVPROC) (GLuint texture, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLCREATEVERTEXARRAYSPROC) (GLsizei n, GLuint *arrays);
    typedef void (APIENTRYP PFNGLDISABLEVERTEXARRAYATTRIBPROC) (GLuint vaobj, GLuint index);
    typedef void (APIENTRYP PFNGLENABLEVERTEXARRAYATTRIBPROC) (GLuint vaobj, GLuint index);
    typedef void (APIENTRYP PFNGLVERTEXARRAYELEMENTBUFFERPROC) (GLuint vaobj, GLuint buffer);
    typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERPROC) (GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
    typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERSPROC) (GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
    typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBBINDINGPROC) (GLuint vaobj, GLuint attribindex, GLuint bindingindex);
    typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBFORMATPROC) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
    typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBIFORMATPROC) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
    typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBLFORMATPROC) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
    typedef void (APIENTRYP PFNGLVERTEXARRAYBINDINGDIVISORPROC) (GLuint vaobj, GLuint bindingindex, GLuint divisor);
    typedef void (APIENTRYP PFNGLGETVERTEXARRAYIVPROC) (GLuint vaobj, GLenum pname, GLint *param);
    typedef void (APIENTRYP PFNGLGETVERTEXARRAYINDEXEDIVPROC) (GLuint vaobj, GLuint index, GLenum pname, GLint *param);
    typedef void (APIENTRYP PFNGLGETVERTEXARRAYINDEXED64IVPROC) (GLuint vaobj, GLuint index, GLenum pname, GLint64 *param);
    typedef void (APIENTRYP PFNGLCREATESAMPLERSPROC) (GLsizei n, GLuint *samplers);
    typedef void (APIENTRYP PFNGLCREATEPROGRAMPIPELINESPROC) (GLsizei n, GLuint *pipelines);
    typedef void (APIENTRYP PFNGLCREATEQUERIESPROC) (GLenum target, GLsizei n, GLuint *ids);
    typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTI64VPROC) (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
    typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTIVPROC) (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
    typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTUI64VPROC) (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
    typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTUIVPROC) (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
    typedef void (APIENTRYP PFNGLMEMORYBARRIERBYREGIONPROC) (GLbitfield barriers);
    typedef void (APIENTRYP PFNGLGETTEXTURESUBIMAGEPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
    typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels);
    typedef GLenum (APIENTRYP PFNGLGETGRAPHICSRESETSTATUSPROC) (void);
    typedef void (APIENTRYP PFNGLGETNCOMPRESSEDTEXIMAGEPROC) (GLenum target, GLint lod, GLsizei bufSize, void *pixels);
    typedef void (APIENTRYP PFNGLGETNTEXIMAGEPROC) (GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
    typedef void (APIENTRYP PFNGLGETNUNIFORMDVPROC) (GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
    typedef void (APIENTRYP PFNGLGETNUNIFORMFVPROC) (GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
    typedef void (APIENTRYP PFNGLGETNUNIFORMIVPROC) (GLuint program, GLint location, GLsizei bufSize, GLint *params);
    typedef void (APIENTRYP PFNGLGETNUNIFORMUIVPROC) (GLuint program, GLint location, GLsizei bufSize, GLuint *params);
    typedef void (APIENTRYP PFNGLREADNPIXELSPROC) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
    typedef void (APIENTRYP PFNGLTEXTUREBARRIERPROC) (void);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glClipControl (GLenum origin, GLenum depth);
    GLAPI void APIENTRY glCreateTransformFeedbacks (GLsizei n, GLuint *ids);
    GLAPI void APIENTRY glTransformFeedbackBufferBase (GLuint xfb, GLuint index, GLuint buffer);
    GLAPI void APIENTRY glTransformFeedbackBufferRange (GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
    GLAPI void APIENTRY glGetTransformFeedbackiv (GLuint xfb, GLenum pname, GLint *param);
    GLAPI void APIENTRY glGetTransformFeedbacki_v (GLuint xfb, GLenum pname, GLuint index, GLint *param);
    GLAPI void APIENTRY glGetTransformFeedbacki64_v (GLuint xfb, GLenum pname, GLuint index, GLint64 *param);
    GLAPI void APIENTRY glCreateBuffers (GLsizei n, GLuint *buffers);
    GLAPI void APIENTRY glNamedBufferStorage (GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
    GLAPI void APIENTRY glNamedBufferData (GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
    GLAPI void APIENTRY glNamedBufferSubData (GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
    GLAPI void APIENTRY glCopyNamedBufferSubData (GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
    GLAPI void APIENTRY glClearNamedBufferData (GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
    GLAPI void APIENTRY glClearNamedBufferSubData (GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
    GLAPI void *APIENTRY glMapNamedBuffer (GLuint buffer, GLenum access);
    GLAPI void *APIENTRY glMapNamedBufferRange (GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
    GLAPI GLboolean APIENTRY glUnmapNamedBuffer (GLuint buffer);
    GLAPI void APIENTRY glFlushMappedNamedBufferRange (GLuint buffer, GLintptr offset, GLsizeiptr length);
    GLAPI void APIENTRY glGetNamedBufferParameteriv (GLuint buffer, GLenum pname, GLint *params);
    GLAPI void APIENTRY glGetNamedBufferParameteri64v (GLuint buffer, GLenum pname, GLint64 *params);
    GLAPI void APIENTRY glGetNamedBufferPointerv (GLuint buffer, GLenum pname, void **params);
    GLAPI void APIENTRY glGetNamedBufferSubData (GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
    GLAPI void APIENTRY glCreateFramebuffers (GLsizei n, GLuint *framebuffers);
    GLAPI void APIENTRY glNamedFramebufferRenderbuffer (GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
    GLAPI void APIENTRY glNamedFramebufferParameteri (GLuint framebuffer, GLenum pname, GLint param);
    GLAPI void APIENTRY glNamedFramebufferTexture (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
    GLAPI void APIENTRY glNamedFramebufferTextureLayer (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
    GLAPI void APIENTRY glNamedFramebufferDrawBuffer (GLuint framebuffer, GLenum buf);
    GLAPI void APIENTRY glNamedFramebufferDrawBuffers (GLuint framebuffer, GLsizei n, const GLenum *bufs);
    GLAPI void APIENTRY glNamedFramebufferReadBuffer (GLuint framebuffer, GLenum src);
    GLAPI void APIENTRY glInvalidateNamedFramebufferData (GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments);
    GLAPI void APIENTRY glInvalidateNamedFramebufferSubData (GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
    GLAPI void APIENTRY glClearNamedFramebufferiv (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value);
    GLAPI void APIENTRY glClearNamedFramebufferuiv (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value);
    GLAPI void APIENTRY glClearNamedFramebufferfv (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value);
    GLAPI void APIENTRY glClearNamedFramebufferfi (GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
    GLAPI void APIENTRY glBlitNamedFramebuffer (GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
    GLAPI GLenum APIENTRY glCheckNamedFramebufferStatus (GLuint framebuffer, GLenum target);
    GLAPI void APIENTRY glGetNamedFramebufferParameteriv (GLuint framebuffer, GLenum pname, GLint *param);
    GLAPI void APIENTRY glGetNamedFramebufferAttachmentParameteriv (GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
    GLAPI void APIENTRY glCreateRenderbuffers (GLsizei n, GLuint *renderbuffers);
    GLAPI void APIENTRY glNamedRenderbufferStorage (GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
    GLAPI void APIENTRY glNamedRenderbufferStorageMultisample (GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
    GLAPI void APIENTRY glGetNamedRenderbufferParameteriv (GLuint renderbuffer, GLenum pname, GLint *params);
    GLAPI void APIENTRY glCreateTextures (GLenum target, GLsizei n, GLuint *textures);
    GLAPI void APIENTRY glTextureBuffer (GLuint texture, GLenum internalformat, GLuint buffer);
    GLAPI void APIENTRY glTextureBufferRange (GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
    GLAPI void APIENTRY glTextureStorage1D (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
    GLAPI void APIENTRY glTextureStorage2D (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
    GLAPI void APIENTRY glTextureStorage3D (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
    GLAPI void APIENTRY glTextureStorage2DMultisample (GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
    GLAPI void APIENTRY glTextureStorage3DMultisample (GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
    GLAPI void APIENTRY glTextureSubImage1D (GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
    GLAPI void APIENTRY glTextureSubImage2D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
    GLAPI void APIENTRY glTextureSubImage3D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
    GLAPI void APIENTRY glCompressedTextureSubImage1D (GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
    GLAPI void APIENTRY glCompressedTextureSubImage2D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
    GLAPI void APIENTRY glCompressedTextureSubImage3D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
    GLAPI void APIENTRY glCopyTextureSubImage1D (GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
    GLAPI void APIENTRY glCopyTextureSubImage2D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    GLAPI void APIENTRY glCopyTextureSubImage3D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    GLAPI void APIENTRY glTextureParameterf (GLuint texture, GLenum pname, GLfloat param);
    GLAPI void APIENTRY glTextureParameterfv (GLuint texture, GLenum pname, const GLfloat *param);
    GLAPI void APIENTRY glTextureParameteri (GLuint texture, GLenum pname, GLint param);
    GLAPI void APIENTRY glTextureParameterIiv (GLuint texture, GLenum pname, const GLint *params);
    GLAPI void APIENTRY glTextureParameterIuiv (GLuint texture, GLenum pname, const GLuint *params);
    GLAPI void APIENTRY glTextureParameteriv (GLuint texture, GLenum pname, const GLint *param);
    GLAPI void APIENTRY glGenerateTextureMipmap (GLuint texture);
    GLAPI void APIENTRY glBindTextureUnit (GLuint unit, GLuint texture);
    GLAPI void APIENTRY glGetTextureImage (GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
    GLAPI void APIENTRY glGetCompressedTextureImage (GLuint texture, GLint level, GLsizei bufSize, void *pixels);
    GLAPI void APIENTRY glGetTextureLevelParameterfv (GLuint texture, GLint level, GLenum pname, GLfloat *params);
    GLAPI void APIENTRY glGetTextureLevelParameteriv (GLuint texture, GLint level, GLenum pname, GLint *params);
    GLAPI void APIENTRY glGetTextureParameterfv (GLuint texture, GLenum pname, GLfloat *params);
    GLAPI void APIENTRY glGetTextureParameterIiv (GLuint texture, GLenum pname, GLint *params);
    GLAPI void APIENTRY glGetTextureParameterIuiv (GLuint texture, GLenum pname, GLuint *params);
    GLAPI void APIENTRY glGetTextureParameteriv (GLuint texture, GLenum pname, GLint *params);
    GLAPI void APIENTRY glCreateVertexArrays (GLsizei n, GLuint *arrays);
    GLAPI void APIENTRY glDisableVertexArrayAttrib (GLuint vaobj, GLuint index);
    GLAPI void APIENTRY glEnableVertexArrayAttrib (GLuint vaobj, GLuint index);
    GLAPI void APIENTRY glVertexArrayElementBuffer (GLuint vaobj, GLuint buffer);
    GLAPI void APIENTRY glVertexArrayVertexBuffer (GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
    GLAPI void APIENTRY glVertexArrayVertexBuffers (GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
    GLAPI void APIENTRY glVertexArrayAttribBinding (GLuint vaobj, GLuint attribindex, GLuint bindingindex);
    GLAPI void APIENTRY glVertexArrayAttribFormat (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
    GLAPI void APIENTRY glVertexArrayAttribIFormat (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
    GLAPI void APIENTRY glVertexArrayAttribLFormat (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
    GLAPI void APIENTRY glVertexArrayBindingDivisor (GLuint vaobj, GLuint bindingindex, GLuint divisor);
    GLAPI void APIENTRY glGetVertexArrayiv (GLuint vaobj, GLenum pname, GLint *param);
    GLAPI void APIENTRY glGetVertexArrayIndexediv (GLuint vaobj, GLuint index, GLenum pname, GLint *param);
    GLAPI void APIENTRY glGetVertexArrayIndexed64iv (GLuint vaobj, GLuint index, GLenum pname, GLint64 *param);
    GLAPI void APIENTRY glCreateSamplers (GLsizei n, GLuint *samplers);
    GLAPI void APIENTRY glCreateProgramPipelines (GLsizei n, GLuint *pipelines);
    GLAPI void APIENTRY glCreateQueries (GLenum target, GLsizei n, GLuint *ids);
    GLAPI void APIENTRY glGetQueryBufferObjecti64v (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
    GLAPI void APIENTRY glGetQueryBufferObjectiv (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
    GLAPI void APIENTRY glGetQueryBufferObjectui64v (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
    GLAPI void APIENTRY glGetQueryBufferObjectuiv (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
    GLAPI void APIENTRY glMemoryBarrierByRegion (GLbitfield barriers);
    GLAPI void APIENTRY glGetTextureSubImage (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
    GLAPI void APIENTRY glGetCompressedTextureSubImage (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels);
    GLAPI GLenum APIENTRY glGetGraphicsResetStatus (void);
    GLAPI void APIENTRY glGetnCompressedTexImage (GLenum target, GLint lod, GLsizei bufSize, void *pixels);
    GLAPI void APIENTRY glGetnTexImage (GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
    GLAPI void APIENTRY glGetnUniformdv (GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
    GLAPI void APIENTRY glGetnUniformfv (GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
    GLAPI void APIENTRY glGetnUniformiv (GLuint program, GLint location, GLsizei bufSize, GLint *params);
    GLAPI void APIENTRY glGetnUniformuiv (GLuint program, GLint location, GLsizei bufSize, GLuint *params);
    GLAPI void APIENTRY glReadnPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
    GLAPI void APIENTRY glTextureBarrier (void);
#endif
#endif /* GL_VERSION_4_5 */
    
#ifndef GL_ARB_ES2_compatibility
#define GL_ARB_ES2_compatibility 1
#endif /* GL_ARB_ES2_compatibility */
    
#ifndef GL_ARB_ES3_1_compatibility
#define GL_ARB_ES3_1_compatibility 1
#endif /* GL_ARB_ES3_1_compatibility */
    
#ifndef GL_ARB_ES3_compatibility
#define GL_ARB_ES3_compatibility 1
#endif /* GL_ARB_ES3_compatibility */
    
#ifndef GL_ARB_arrays_of_arrays
#define GL_ARB_arrays_of_arrays 1
#endif /* GL_ARB_arrays_of_arrays */
    
#ifndef GL_ARB_base_instance
#define GL_ARB_base_instance 1
#endif /* GL_ARB_base_instance */
    
#ifndef GL_ARB_bindless_texture
#define GL_ARB_bindless_texture 1
    typedef uint64_t GLuint64EXT;
#define GL_UNSIGNED_INT64_ARB             0x140F
    typedef GLuint64 (APIENTRYP PFNGLGETTEXTUREHANDLEARBPROC) (GLuint texture);
    typedef GLuint64 (APIENTRYP PFNGLGETTEXTURESAMPLERHANDLEARBPROC) (GLuint texture, GLuint sampler);
    typedef void (APIENTRYP PFNGLMAKETEXTUREHANDLERESIDENTARBPROC) (GLuint64 handle);
    typedef void (APIENTRYP PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC) (GLuint64 handle);
    typedef GLuint64 (APIENTRYP PFNGLGETIMAGEHANDLEARBPROC) (GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
    typedef void (APIENTRYP PFNGLMAKEIMAGEHANDLERESIDENTARBPROC) (GLuint64 handle, GLenum access);
    typedef void (APIENTRYP PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC) (GLuint64 handle);
    typedef void (APIENTRYP PFNGLUNIFORMHANDLEUI64ARBPROC) (GLint location, GLuint64 value);
    typedef void (APIENTRYP PFNGLUNIFORMHANDLEUI64VARBPROC) (GLint location, GLsizei count, const GLuint64 *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC) (GLuint program, GLint location, GLuint64 value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC) (GLuint program, GLint location, GLsizei count, const GLuint64 *values);
    typedef GLboolean (APIENTRYP PFNGLISTEXTUREHANDLERESIDENTARBPROC) (GLuint64 handle);
    typedef GLboolean (APIENTRYP PFNGLISIMAGEHANDLERESIDENTARBPROC) (GLuint64 handle);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBL1UI64ARBPROC) (GLuint index, GLuint64EXT x);
    typedef void (APIENTRYP PFNGLVERTEXATTRIBL1UI64VARBPROC) (GLuint index, const GLuint64EXT *v);
    typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLUI64VARBPROC) (GLuint index, GLenum pname, GLuint64EXT *params);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI GLuint64 APIENTRY glGetTextureHandleARB (GLuint texture);
    GLAPI GLuint64 APIENTRY glGetTextureSamplerHandleARB (GLuint texture, GLuint sampler);
    GLAPI void APIENTRY glMakeTextureHandleResidentARB (GLuint64 handle);
    GLAPI void APIENTRY glMakeTextureHandleNonResidentARB (GLuint64 handle);
    GLAPI GLuint64 APIENTRY glGetImageHandleARB (GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
    GLAPI void APIENTRY glMakeImageHandleResidentARB (GLuint64 handle, GLenum access);
    GLAPI void APIENTRY glMakeImageHandleNonResidentARB (GLuint64 handle);
    GLAPI void APIENTRY glUniformHandleui64ARB (GLint location, GLuint64 value);
    GLAPI void APIENTRY glUniformHandleui64vARB (GLint location, GLsizei count, const GLuint64 *value);
    GLAPI void APIENTRY glProgramUniformHandleui64ARB (GLuint program, GLint location, GLuint64 value);
    GLAPI void APIENTRY glProgramUniformHandleui64vARB (GLuint program, GLint location, GLsizei count, const GLuint64 *values);
    GLAPI GLboolean APIENTRY glIsTextureHandleResidentARB (GLuint64 handle);
    GLAPI GLboolean APIENTRY glIsImageHandleResidentARB (GLuint64 handle);
    GLAPI void APIENTRY glVertexAttribL1ui64ARB (GLuint index, GLuint64EXT x);
    GLAPI void APIENTRY glVertexAttribL1ui64vARB (GLuint index, const GLuint64EXT *v);
    GLAPI void APIENTRY glGetVertexAttribLui64vARB (GLuint index, GLenum pname, GLuint64EXT *params);
#endif
#endif /* GL_ARB_bindless_texture */
    
#ifndef GL_ARB_blend_func_extended
#define GL_ARB_blend_func_extended 1
#endif /* GL_ARB_blend_func_extended */
    
#ifndef GL_ARB_buffer_storage
#define GL_ARB_buffer_storage 1
#endif /* GL_ARB_buffer_storage */
    
#ifndef GL_ARB_cl_event
#define GL_ARB_cl_event 1
    struct _cl_context;
    struct _cl_event;
#define GL_SYNC_CL_EVENT_ARB              0x8240
#define GL_SYNC_CL_EVENT_COMPLETE_ARB     0x8241
    typedef GLsync (APIENTRYP PFNGLCREATESYNCFROMCLEVENTARBPROC) (struct _cl_context *context, struct _cl_event *event, GLbitfield flags);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI GLsync APIENTRY glCreateSyncFromCLeventARB (struct _cl_context *context, struct _cl_event *event, GLbitfield flags);
#endif
#endif /* GL_ARB_cl_event */
    
#ifndef GL_ARB_clear_buffer_object
#define GL_ARB_clear_buffer_object 1
#endif /* GL_ARB_clear_buffer_object */
    
#ifndef GL_ARB_clear_texture
#define GL_ARB_clear_texture 1
#endif /* GL_ARB_clear_texture */
    
#ifndef GL_ARB_clip_control
#define GL_ARB_clip_control 1
#endif /* GL_ARB_clip_control */
    
#ifndef GL_ARB_compressed_texture_pixel_storage
#define GL_ARB_compressed_texture_pixel_storage 1
#endif /* GL_ARB_compressed_texture_pixel_storage */
    
#ifndef GL_ARB_compute_shader
#define GL_ARB_compute_shader 1
#endif /* GL_ARB_compute_shader */
    
#ifndef GL_ARB_compute_variable_group_size
#define GL_ARB_compute_variable_group_size 1
#define GL_MAX_COMPUTE_VARIABLE_GROUP_INVOCATIONS_ARB 0x9344
#define GL_MAX_COMPUTE_FIXED_GROUP_INVOCATIONS_ARB 0x90EB
#define GL_MAX_COMPUTE_VARIABLE_GROUP_SIZE_ARB 0x9345
#define GL_MAX_COMPUTE_FIXED_GROUP_SIZE_ARB 0x91BF
    typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEGROUPSIZEARBPROC) (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLuint group_size_x, GLuint group_size_y, GLuint group_size_z);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glDispatchComputeGroupSizeARB (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLuint group_size_x, GLuint group_size_y, GLuint group_size_z);
#endif
#endif /* GL_ARB_compute_variable_group_size */
    
#ifndef GL_ARB_conditional_render_inverted
#define GL_ARB_conditional_render_inverted 1
#endif /* GL_ARB_conditional_render_inverted */
    
#ifndef GL_ARB_conservative_depth
#define GL_ARB_conservative_depth 1
#endif /* GL_ARB_conservative_depth */
    
#ifndef GL_ARB_copy_buffer
#define GL_ARB_copy_buffer 1
#endif /* GL_ARB_copy_buffer */
    
#ifndef GL_ARB_copy_image
#define GL_ARB_copy_image 1
#endif /* GL_ARB_copy_image */
    
#ifndef GL_ARB_cull_distance
#define GL_ARB_cull_distance 1
#endif /* GL_ARB_cull_distance */
    
#ifndef GL_ARB_debug_output
#define GL_ARB_debug_output 1
    typedef void (APIENTRY  *GLDEBUGPROCARB)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
#define GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB   0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_ARB 0x8243
#define GL_DEBUG_CALLBACK_FUNCTION_ARB    0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM_ARB  0x8245
#define GL_DEBUG_SOURCE_API_ARB           0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB 0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER_ARB 0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY_ARB   0x8249
#define GL_DEBUG_SOURCE_APPLICATION_ARB   0x824A
#define GL_DEBUG_SOURCE_OTHER_ARB         0x824B
#define GL_DEBUG_TYPE_ERROR_ARB           0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB 0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB 0x824E
#define GL_DEBUG_TYPE_PORTABILITY_ARB     0x824F
#define GL_DEBUG_TYPE_PERFORMANCE_ARB     0x8250
#define GL_DEBUG_TYPE_OTHER_ARB           0x8251
#define GL_MAX_DEBUG_MESSAGE_LENGTH_ARB   0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES_ARB  0x9144
#define GL_DEBUG_LOGGED_MESSAGES_ARB      0x9145
#define GL_DEBUG_SEVERITY_HIGH_ARB        0x9146
#define GL_DEBUG_SEVERITY_MEDIUM_ARB      0x9147
#define GL_DEBUG_SEVERITY_LOW_ARB         0x9148
    typedef void (APIENTRYP PFNGLDEBUGMESSAGECONTROLARBPROC) (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
    typedef void (APIENTRYP PFNGLDEBUGMESSAGEINSERTARBPROC) (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
    typedef void (APIENTRYP PFNGLDEBUGMESSAGECALLBACKARBPROC) (GLDEBUGPROCARB callback, const void *userParam);
    typedef GLuint (APIENTRYP PFNGLGETDEBUGMESSAGELOGARBPROC) (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glDebugMessageControlARB (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
    GLAPI void APIENTRY glDebugMessageInsertARB (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
    GLAPI void APIENTRY glDebugMessageCallbackARB (GLDEBUGPROCARB callback, const void *userParam);
    GLAPI GLuint APIENTRY glGetDebugMessageLogARB (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
#endif
#endif /* GL_ARB_debug_output */
    
#ifndef GL_ARB_depth_buffer_float
#define GL_ARB_depth_buffer_float 1
#endif /* GL_ARB_depth_buffer_float */
    
#ifndef GL_ARB_depth_clamp
#define GL_ARB_depth_clamp 1
#endif /* GL_ARB_depth_clamp */
    
#ifndef GL_ARB_derivative_control
#define GL_ARB_derivative_control 1
#endif /* GL_ARB_derivative_control */
    
#ifndef GL_ARB_direct_state_access
#define GL_ARB_direct_state_access 1
#endif /* GL_ARB_direct_state_access */
    
#ifndef GL_ARB_draw_buffers_blend
#define GL_ARB_draw_buffers_blend 1
    typedef void (APIENTRYP PFNGLBLENDEQUATIONIARBPROC) (GLuint buf, GLenum mode);
    typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEIARBPROC) (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
    typedef void (APIENTRYP PFNGLBLENDFUNCIARBPROC) (GLuint buf, GLenum src, GLenum dst);
    typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEIARBPROC) (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glBlendEquationiARB (GLuint buf, GLenum mode);
    GLAPI void APIENTRY glBlendEquationSeparateiARB (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
    GLAPI void APIENTRY glBlendFunciARB (GLuint buf, GLenum src, GLenum dst);
    GLAPI void APIENTRY glBlendFuncSeparateiARB (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
#endif
#endif /* GL_ARB_draw_buffers_blend */
    
#ifndef GL_ARB_draw_elements_base_vertex
#define GL_ARB_draw_elements_base_vertex 1
#endif /* GL_ARB_draw_elements_base_vertex */
    
#ifndef GL_ARB_draw_indirect
#define GL_ARB_draw_indirect 1
#endif /* GL_ARB_draw_indirect */
    
#ifndef GL_ARB_enhanced_layouts
#define GL_ARB_enhanced_layouts 1
#endif /* GL_ARB_enhanced_layouts */
    
#ifndef GL_ARB_explicit_attrib_location
#define GL_ARB_explicit_attrib_location 1
#endif /* GL_ARB_explicit_attrib_location */
    
#ifndef GL_ARB_explicit_uniform_location
#define GL_ARB_explicit_uniform_location 1
#endif /* GL_ARB_explicit_uniform_location */
    
#ifndef GL_ARB_fragment_coord_conventions
#define GL_ARB_fragment_coord_conventions 1
#endif /* GL_ARB_fragment_coord_conventions */
    
#ifndef GL_ARB_fragment_layer_viewport
#define GL_ARB_fragment_layer_viewport 1
#endif /* GL_ARB_fragment_layer_viewport */
    
#ifndef GL_ARB_framebuffer_no_attachments
#define GL_ARB_framebuffer_no_attachments 1
#endif /* GL_ARB_framebuffer_no_attachments */
    
#ifndef GL_ARB_framebuffer_object
#define GL_ARB_framebuffer_object 1
#endif /* GL_ARB_framebuffer_object */
    
#ifndef GL_ARB_framebuffer_sRGB
#define GL_ARB_framebuffer_sRGB 1
#endif /* GL_ARB_framebuffer_sRGB */
    
#ifndef GL_ARB_get_program_binary
#define GL_ARB_get_program_binary 1
#endif /* GL_ARB_get_program_binary */
    
#ifndef GL_ARB_get_texture_sub_image
#define GL_ARB_get_texture_sub_image 1
#endif /* GL_ARB_get_texture_sub_image */
    
#ifndef GL_ARB_gpu_shader5
#define GL_ARB_gpu_shader5 1
#endif /* GL_ARB_gpu_shader5 */
    
#ifndef GL_ARB_gpu_shader_fp64
#define GL_ARB_gpu_shader_fp64 1
#endif /* GL_ARB_gpu_shader_fp64 */
    
#ifndef GL_ARB_half_float_vertex
#define GL_ARB_half_float_vertex 1
#endif /* GL_ARB_half_float_vertex */
    
#ifndef GL_ARB_imaging
#define GL_ARB_imaging 1
#define GL_BLEND_COLOR                    0x8005
#define GL_BLEND_EQUATION                 0x8009
#endif /* GL_ARB_imaging */
    
#ifndef GL_ARB_indirect_parameters
#define GL_ARB_indirect_parameters 1
#define GL_PARAMETER_BUFFER_ARB           0x80EE
#define GL_PARAMETER_BUFFER_BINDING_ARB   0x80EF
    typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTCOUNTARBPROC) (GLenum mode, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
    typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTARBPROC) (GLenum mode, GLenum type, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glMultiDrawArraysIndirectCountARB (GLenum mode, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
    GLAPI void APIENTRY glMultiDrawElementsIndirectCountARB (GLenum mode, GLenum type, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
#endif
#endif /* GL_ARB_indirect_parameters */
    
#ifndef GL_ARB_internalformat_query
#define GL_ARB_internalformat_query 1
#endif /* GL_ARB_internalformat_query */
    
#ifndef GL_ARB_internalformat_query2
#define GL_ARB_internalformat_query2 1
#define GL_SRGB_DECODE_ARB                0x8299
#endif /* GL_ARB_internalformat_query2 */
    
#ifndef GL_ARB_invalidate_subdata
#define GL_ARB_invalidate_subdata 1
#endif /* GL_ARB_invalidate_subdata */
    
#ifndef GL_ARB_map_buffer_alignment
#define GL_ARB_map_buffer_alignment 1
#endif /* GL_ARB_map_buffer_alignment */
    
#ifndef GL_ARB_map_buffer_range
#define GL_ARB_map_buffer_range 1
#endif /* GL_ARB_map_buffer_range */
    
#ifndef GL_ARB_multi_bind
#define GL_ARB_multi_bind 1
#endif /* GL_ARB_multi_bind */
    
#ifndef GL_ARB_multi_draw_indirect
#define GL_ARB_multi_draw_indirect 1
#endif /* GL_ARB_multi_draw_indirect */
    
#ifndef GL_ARB_occlusion_query2
#define GL_ARB_occlusion_query2 1
#endif /* GL_ARB_occlusion_query2 */
    
#ifndef GL_ARB_pipeline_statistics_query
#define GL_ARB_pipeline_statistics_query 1
#define GL_VERTICES_SUBMITTED_ARB         0x82EE
#define GL_PRIMITIVES_SUBMITTED_ARB       0x82EF
#define GL_VERTEX_SHADER_INVOCATIONS_ARB  0x82F0
#define GL_TESS_CONTROL_SHADER_PATCHES_ARB 0x82F1
#define GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB 0x82F2
#define GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB 0x82F3
#define GL_FRAGMENT_SHADER_INVOCATIONS_ARB 0x82F4
#define GL_COMPUTE_SHADER_INVOCATIONS_ARB 0x82F5
#define GL_CLIPPING_INPUT_PRIMITIVES_ARB  0x82F6
#define GL_CLIPPING_OUTPUT_PRIMITIVES_ARB 0x82F7
#endif /* GL_ARB_pipeline_statistics_query */
    
#ifndef GL_ARB_program_interface_query
#define GL_ARB_program_interface_query 1
#endif /* GL_ARB_program_interface_query */
    
#ifndef GL_ARB_provoking_vertex
#define GL_ARB_provoking_vertex 1
#endif /* GL_ARB_provoking_vertex */
    
#ifndef GL_ARB_query_buffer_object
#define GL_ARB_query_buffer_object 1
#endif /* GL_ARB_query_buffer_object */
    
#ifndef GL_ARB_robust_buffer_access_behavior
#define GL_ARB_robust_buffer_access_behavior 1
#endif /* GL_ARB_robust_buffer_access_behavior */
    
#ifndef GL_ARB_robustness
#define GL_ARB_robustness 1
#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB 0x00000004
#define GL_LOSE_CONTEXT_ON_RESET_ARB      0x8252
#define GL_GUILTY_CONTEXT_RESET_ARB       0x8253
#define GL_INNOCENT_CONTEXT_RESET_ARB     0x8254
#define GL_UNKNOWN_CONTEXT_RESET_ARB      0x8255
#define GL_RESET_NOTIFICATION_STRATEGY_ARB 0x8256
#define GL_NO_RESET_NOTIFICATION_ARB      0x8261
    typedef GLenum (APIENTRYP PFNGLGETGRAPHICSRESETSTATUSARBPROC) (void);
    typedef void (APIENTRYP PFNGLGETNTEXIMAGEARBPROC) (GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *img);
    typedef void (APIENTRYP PFNGLREADNPIXELSARBPROC) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
    typedef void (APIENTRYP PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC) (GLenum target, GLint lod, GLsizei bufSize, void *img);
    typedef void (APIENTRYP PFNGLGETNUNIFORMFVARBPROC) (GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
    typedef void (APIENTRYP PFNGLGETNUNIFORMIVARBPROC) (GLuint program, GLint location, GLsizei bufSize, GLint *params);
    typedef void (APIENTRYP PFNGLGETNUNIFORMUIVARBPROC) (GLuint program, GLint location, GLsizei bufSize, GLuint *params);
    typedef void (APIENTRYP PFNGLGETNUNIFORMDVARBPROC) (GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI GLenum APIENTRY glGetGraphicsResetStatusARB (void);
    GLAPI void APIENTRY glGetnTexImageARB (GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *img);
    GLAPI void APIENTRY glReadnPixelsARB (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
    GLAPI void APIENTRY glGetnCompressedTexImageARB (GLenum target, GLint lod, GLsizei bufSize, void *img);
    GLAPI void APIENTRY glGetnUniformfvARB (GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
    GLAPI void APIENTRY glGetnUniformivARB (GLuint program, GLint location, GLsizei bufSize, GLint *params);
    GLAPI void APIENTRY glGetnUniformuivARB (GLuint program, GLint location, GLsizei bufSize, GLuint *params);
    GLAPI void APIENTRY glGetnUniformdvARB (GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
#endif
#endif /* GL_ARB_robustness */
    
#ifndef GL_ARB_robustness_isolation
#define GL_ARB_robustness_isolation 1
#endif /* GL_ARB_robustness_isolation */
    
#ifndef GL_ARB_sample_shading
#define GL_ARB_sample_shading 1
#define GL_SAMPLE_SHADING_ARB             0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE_ARB   0x8C37
    typedef void (APIENTRYP PFNGLMINSAMPLESHADINGARBPROC) (GLfloat value);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glMinSampleShadingARB (GLfloat value);
#endif
#endif /* GL_ARB_sample_shading */
    
#ifndef GL_ARB_sampler_objects
#define GL_ARB_sampler_objects 1
#endif /* GL_ARB_sampler_objects */
    
#ifndef GL_ARB_seamless_cube_map
#define GL_ARB_seamless_cube_map 1
#endif /* GL_ARB_seamless_cube_map */
    
#ifndef GL_ARB_seamless_cubemap_per_texture
#define GL_ARB_seamless_cubemap_per_texture 1
#endif /* GL_ARB_seamless_cubemap_per_texture */
    
#ifndef GL_ARB_separate_shader_objects
#define GL_ARB_separate_shader_objects 1
#endif /* GL_ARB_separate_shader_objects */
    
#ifndef GL_ARB_shader_atomic_counters
#define GL_ARB_shader_atomic_counters 1
#endif /* GL_ARB_shader_atomic_counters */
    
#ifndef GL_ARB_shader_bit_encoding
#define GL_ARB_shader_bit_encoding 1
#endif /* GL_ARB_shader_bit_encoding */
    
#ifndef GL_ARB_shader_draw_parameters
#define GL_ARB_shader_draw_parameters 1
#endif /* GL_ARB_shader_draw_parameters */
    
#ifndef GL_ARB_shader_group_vote
#define GL_ARB_shader_group_vote 1
#endif /* GL_ARB_shader_group_vote */
    
#ifndef GL_ARB_shader_image_load_store
#define GL_ARB_shader_image_load_store 1
#endif /* GL_ARB_shader_image_load_store */
    
#ifndef GL_ARB_shader_image_size
#define GL_ARB_shader_image_size 1
#endif /* GL_ARB_shader_image_size */
    
#ifndef GL_ARB_shader_precision
#define GL_ARB_shader_precision 1
#endif /* GL_ARB_shader_precision */
    
#ifndef GL_ARB_shader_stencil_export
#define GL_ARB_shader_stencil_export 1
#endif /* GL_ARB_shader_stencil_export */
    
#ifndef GL_ARB_shader_storage_buffer_object
#define GL_ARB_shader_storage_buffer_object 1
#endif /* GL_ARB_shader_storage_buffer_object */
    
#ifndef GL_ARB_shader_subroutine
#define GL_ARB_shader_subroutine 1
#endif /* GL_ARB_shader_subroutine */
    
#ifndef GL_ARB_shader_texture_image_samples
#define GL_ARB_shader_texture_image_samples 1
#endif /* GL_ARB_shader_texture_image_samples */
    
#ifndef GL_ARB_shading_language_420pack
#define GL_ARB_shading_language_420pack 1
#endif /* GL_ARB_shading_language_420pack */
    
#ifndef GL_ARB_shading_language_include
#define GL_ARB_shading_language_include 1
#define GL_SHADER_INCLUDE_ARB             0x8DAE
#define GL_NAMED_STRING_LENGTH_ARB        0x8DE9
#define GL_NAMED_STRING_TYPE_ARB          0x8DEA
    typedef void (APIENTRYP PFNGLNAMEDSTRINGARBPROC) (GLenum type, GLint namelen, const GLchar *name, GLint stringlen, const GLchar *string);
    typedef void (APIENTRYP PFNGLDELETENAMEDSTRINGARBPROC) (GLint namelen, const GLchar *name);
    typedef void (APIENTRYP PFNGLCOMPILESHADERINCLUDEARBPROC) (GLuint shader, GLsizei count, const GLchar *const*path, const GLint *length);
    typedef GLboolean (APIENTRYP PFNGLISNAMEDSTRINGARBPROC) (GLint namelen, const GLchar *name);
    typedef void (APIENTRYP PFNGLGETNAMEDSTRINGARBPROC) (GLint namelen, const GLchar *name, GLsizei bufSize, GLint *stringlen, GLchar *string);
    typedef void (APIENTRYP PFNGLGETNAMEDSTRINGIVARBPROC) (GLint namelen, const GLchar *name, GLenum pname, GLint *params);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glNamedStringARB (GLenum type, GLint namelen, const GLchar *name, GLint stringlen, const GLchar *string);
    GLAPI void APIENTRY glDeleteNamedStringARB (GLint namelen, const GLchar *name);
    GLAPI void APIENTRY glCompileShaderIncludeARB (GLuint shader, GLsizei count, const GLchar *const*path, const GLint *length);
    GLAPI GLboolean APIENTRY glIsNamedStringARB (GLint namelen, const GLchar *name);
    GLAPI void APIENTRY glGetNamedStringARB (GLint namelen, const GLchar *name, GLsizei bufSize, GLint *stringlen, GLchar *string);
    GLAPI void APIENTRY glGetNamedStringivARB (GLint namelen, const GLchar *name, GLenum pname, GLint *params);
#endif
#endif /* GL_ARB_shading_language_include */
    
#ifndef GL_ARB_shading_language_packing
#define GL_ARB_shading_language_packing 1
#endif /* GL_ARB_shading_language_packing */
    
#ifndef GL_ARB_sparse_buffer
#define GL_ARB_sparse_buffer 1
#define GL_SPARSE_STORAGE_BIT_ARB         0x0400
#define GL_SPARSE_BUFFER_PAGE_SIZE_ARB    0x82F8
    typedef void (APIENTRYP PFNGLBUFFERPAGECOMMITMENTARBPROC) (GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit);
    typedef void (APIENTRYP PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC) (GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
    typedef void (APIENTRYP PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC) (GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glBufferPageCommitmentARB (GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit);
    GLAPI void APIENTRY glNamedBufferPageCommitmentEXT (GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
    GLAPI void APIENTRY glNamedBufferPageCommitmentARB (GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
#endif
#endif /* GL_ARB_sparse_buffer */
    
#ifndef GL_ARB_sparse_texture
#define GL_ARB_sparse_texture 1
#define GL_TEXTURE_SPARSE_ARB             0x91A6
#define GL_VIRTUAL_PAGE_SIZE_INDEX_ARB    0x91A7
#define GL_NUM_SPARSE_LEVELS_ARB          0x91AA
#define GL_NUM_VIRTUAL_PAGE_SIZES_ARB     0x91A8
#define GL_VIRTUAL_PAGE_SIZE_X_ARB        0x9195
#define GL_VIRTUAL_PAGE_SIZE_Y_ARB        0x9196
#define GL_VIRTUAL_PAGE_SIZE_Z_ARB        0x9197
#define GL_MAX_SPARSE_TEXTURE_SIZE_ARB    0x9198
#define GL_MAX_SPARSE_3D_TEXTURE_SIZE_ARB 0x9199
#define GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS_ARB 0x919A
#define GL_SPARSE_TEXTURE_FULL_ARRAY_CUBE_MIPMAPS_ARB 0x91A9
    typedef void (APIENTRYP PFNGLTEXPAGECOMMITMENTARBPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glTexPageCommitmentARB (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
#endif
#endif /* GL_ARB_sparse_texture */
    
#ifndef GL_ARB_sparse_texture2
#define GL_ARB_sparse_texture2 1
#endif /* GL_ARB_sparse_texture2 */
    
#ifndef GL_ARB_stencil_texturing
#define GL_ARB_stencil_texturing 1
#endif /* GL_ARB_stencil_texturing */
    
#ifndef GL_ARB_sync
#define GL_ARB_sync 1
#endif /* GL_ARB_sync */
    
#ifndef GL_ARB_tessellation_shader
#define GL_ARB_tessellation_shader 1
#endif /* GL_ARB_tessellation_shader */
    
#ifndef GL_ARB_texture_barrier
#define GL_ARB_texture_barrier 1
#endif /* GL_ARB_texture_barrier */
    
#ifndef GL_ARB_texture_buffer_object_rgb32
#define GL_ARB_texture_buffer_object_rgb32 1
#endif /* GL_ARB_texture_buffer_object_rgb32 */
    
#ifndef GL_ARB_texture_buffer_range
#define GL_ARB_texture_buffer_range 1
#endif /* GL_ARB_texture_buffer_range */
    
#ifndef GL_ARB_texture_compression_bptc
#define GL_ARB_texture_compression_bptc 1
#define GL_COMPRESSED_RGBA_BPTC_UNORM_ARB 0x8E8C
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB 0x8E8D
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB 0x8E8E
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB 0x8E8F
#endif /* GL_ARB_texture_compression_bptc */
    
#ifndef GL_ARB_texture_compression_rgtc
#define GL_ARB_texture_compression_rgtc 1
#endif /* GL_ARB_texture_compression_rgtc */
    
#ifndef GL_ARB_texture_cube_map_array
#define GL_ARB_texture_cube_map_array 1
#define GL_TEXTURE_CUBE_MAP_ARRAY_ARB     0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB 0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY_ARB 0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY_ARB     0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_ARB 0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900F
#endif /* GL_ARB_texture_cube_map_array */
    
#ifndef GL_ARB_texture_gather
#define GL_ARB_texture_gather 1
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_ARB 0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_ARB 0x8E5F
#define GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS_ARB 0x8F9F
#endif /* GL_ARB_texture_gather */
    
#ifndef GL_ARB_texture_mirror_clamp_to_edge
#define GL_ARB_texture_mirror_clamp_to_edge 1
#endif /* GL_ARB_texture_mirror_clamp_to_edge */
    
#ifndef GL_ARB_texture_multisample
#define GL_ARB_texture_multisample 1
#endif /* GL_ARB_texture_multisample */
    
#ifndef GL_ARB_texture_query_levels
#define GL_ARB_texture_query_levels 1
#endif /* GL_ARB_texture_query_levels */
    
#ifndef GL_ARB_texture_query_lod
#define GL_ARB_texture_query_lod 1
#endif /* GL_ARB_texture_query_lod */
    
#ifndef GL_ARB_texture_rg
#define GL_ARB_texture_rg 1
#endif /* GL_ARB_texture_rg */
    
#ifndef GL_ARB_texture_rgb10_a2ui
#define GL_ARB_texture_rgb10_a2ui 1
#endif /* GL_ARB_texture_rgb10_a2ui */
    
#ifndef GL_ARB_texture_stencil8
#define GL_ARB_texture_stencil8 1
#endif /* GL_ARB_texture_stencil8 */
    
#ifndef GL_ARB_texture_storage
#define GL_ARB_texture_storage 1
#endif /* GL_ARB_texture_storage */
    
#ifndef GL_ARB_texture_storage_multisample
#define GL_ARB_texture_storage_multisample 1
#endif /* GL_ARB_texture_storage_multisample */
    
#ifndef GL_ARB_texture_swizzle
#define GL_ARB_texture_swizzle 1
#endif /* GL_ARB_texture_swizzle */
    
#ifndef GL_ARB_texture_view
#define GL_ARB_texture_view 1
#endif /* GL_ARB_texture_view */
    
#ifndef GL_ARB_timer_query
#define GL_ARB_timer_query 1
#endif /* GL_ARB_timer_query */
    
#ifndef GL_ARB_transform_feedback2
#define GL_ARB_transform_feedback2 1
#endif /* GL_ARB_transform_feedback2 */
    
#ifndef GL_ARB_transform_feedback3
#define GL_ARB_transform_feedback3 1
#endif /* GL_ARB_transform_feedback3 */
    
#ifndef GL_ARB_transform_feedback_instanced
#define GL_ARB_transform_feedback_instanced 1
#endif /* GL_ARB_transform_feedback_instanced */
    
#ifndef GL_ARB_transform_feedback_overflow_query
#define GL_ARB_transform_feedback_overflow_query 1
#define GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB 0x82EC
#define GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB 0x82ED
#endif /* GL_ARB_transform_feedback_overflow_query */
    
#ifndef GL_ARB_uniform_buffer_object
#define GL_ARB_uniform_buffer_object 1
#endif /* GL_ARB_uniform_buffer_object */
    
#ifndef GL_ARB_vertex_array_bgra
#define GL_ARB_vertex_array_bgra 1
#endif /* GL_ARB_vertex_array_bgra */
    
#ifndef GL_ARB_vertex_array_object
#define GL_ARB_vertex_array_object 1
#endif /* GL_ARB_vertex_array_object */
    
#ifndef GL_ARB_vertex_attrib_64bit
#define GL_ARB_vertex_attrib_64bit 1
#endif /* GL_ARB_vertex_attrib_64bit */
    
#ifndef GL_ARB_vertex_attrib_binding
#define GL_ARB_vertex_attrib_binding 1
#endif /* GL_ARB_vertex_attrib_binding */
    
#ifndef GL_ARB_vertex_type_10f_11f_11f_rev
#define GL_ARB_vertex_type_10f_11f_11f_rev 1
#endif /* GL_ARB_vertex_type_10f_11f_11f_rev */
    
#ifndef GL_ARB_vertex_type_2_10_10_10_rev
#define GL_ARB_vertex_type_2_10_10_10_rev 1
#endif /* GL_ARB_vertex_type_2_10_10_10_rev */
    
#ifndef GL_ARB_viewport_array
#define GL_ARB_viewport_array 1
#endif /* GL_ARB_viewport_array */
    
#ifndef GL_KHR_blend_equation_advanced
#define GL_KHR_blend_equation_advanced 1
#define GL_MULTIPLY_KHR                   0x9294
#define GL_SCREEN_KHR                     0x9295
#define GL_OVERLAY_KHR                    0x9296
#define GL_DARKEN_KHR                     0x9297
#define GL_LIGHTEN_KHR                    0x9298
#define GL_COLORDODGE_KHR                 0x9299
#define GL_COLORBURN_KHR                  0x929A
#define GL_HARDLIGHT_KHR                  0x929B
#define GL_SOFTLIGHT_KHR                  0x929C
#define GL_DIFFERENCE_KHR                 0x929E
#define GL_EXCLUSION_KHR                  0x92A0
#define GL_HSL_HUE_KHR                    0x92AD
#define GL_HSL_SATURATION_KHR             0x92AE
#define GL_HSL_COLOR_KHR                  0x92AF
#define GL_HSL_LUMINOSITY_KHR             0x92B0
    typedef void (APIENTRYP PFNGLBLENDBARRIERKHRPROC) (void);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glBlendBarrierKHR (void);
#endif
#endif /* GL_KHR_blend_equation_advanced */
    
#ifndef GL_KHR_blend_equation_advanced_coherent
#define GL_KHR_blend_equation_advanced_coherent 1
#define GL_BLEND_ADVANCED_COHERENT_KHR    0x9285
#endif /* GL_KHR_blend_equation_advanced_coherent */
    
#ifndef GL_KHR_context_flush_control
#define GL_KHR_context_flush_control 1
#endif /* GL_KHR_context_flush_control */
    
#ifndef GL_KHR_debug
#define GL_KHR_debug 1
#endif /* GL_KHR_debug */
    
#ifndef GL_KHR_no_error
#define GL_KHR_no_error 1
#define GL_CONTEXT_FLAG_NO_ERROR_BIT_KHR  0x00000008
#endif /* GL_KHR_no_error */
    
#ifndef GL_KHR_robust_buffer_access_behavior
#define GL_KHR_robust_buffer_access_behavior 1
#endif /* GL_KHR_robust_buffer_access_behavior */
    
#ifndef GL_KHR_robustness
#define GL_KHR_robustness 1
#define GL_CONTEXT_ROBUST_ACCESS          0x90F3
#endif /* GL_KHR_robustness */
    
#ifndef GL_KHR_texture_compression_astc_hdr
#define GL_KHR_texture_compression_astc_hdr 1
#define GL_COMPRESSED_RGBA_ASTC_4x4_KHR   0x93B0
#define GL_COMPRESSED_RGBA_ASTC_5x4_KHR   0x93B1
#define GL_COMPRESSED_RGBA_ASTC_5x5_KHR   0x93B2
#define GL_COMPRESSED_RGBA_ASTC_6x5_KHR   0x93B3
#define GL_COMPRESSED_RGBA_ASTC_6x6_KHR   0x93B4
#define GL_COMPRESSED_RGBA_ASTC_8x5_KHR   0x93B5
#define GL_COMPRESSED_RGBA_ASTC_8x6_KHR   0x93B6
#define GL_COMPRESSED_RGBA_ASTC_8x8_KHR   0x93B7
#define GL_COMPRESSED_RGBA_ASTC_10x5_KHR  0x93B8
#define GL_COMPRESSED_RGBA_ASTC_10x6_KHR  0x93B9
#define GL_COMPRESSED_RGBA_ASTC_10x8_KHR  0x93BA
#define GL_COMPRESSED_RGBA_ASTC_10x10_KHR 0x93BB
#define GL_COMPRESSED_RGBA_ASTC_12x10_KHR 0x93BC
#define GL_COMPRESSED_RGBA_ASTC_12x12_KHR 0x93BD
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4_KHR 0x93D0
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4_KHR 0x93D1
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5_KHR 0x93D2
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5_KHR 0x93D3
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6_KHR 0x93D4
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5_KHR 0x93D5
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6_KHR 0x93D6
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8_KHR 0x93D7
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5_KHR 0x93D8
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR 0x93D9
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR 0x93DA
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR 0x93DB
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10_KHR 0x93DC
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12_KHR 0x93DD
#endif /* GL_KHR_texture_compression_astc_hdr */
    
#ifndef GL_KHR_texture_compression_astc_ldr
#define GL_KHR_texture_compression_astc_ldr 1
#endif /* GL_KHR_texture_compression_astc_ldr */
    
#ifndef GL_KHR_texture_compression_astc_sliced_3d
#define GL_KHR_texture_compression_astc_sliced_3d 1
#endif /* GL_KHR_texture_compression_astc_sliced_3d */
    
#ifndef GL_AMD_performance_monitor
#define GL_AMD_performance_monitor 1
#define GL_COUNTER_TYPE_AMD               0x8BC0
#define GL_COUNTER_RANGE_AMD              0x8BC1
#define GL_UNSIGNED_INT64_AMD             0x8BC2
#define GL_PERCENTAGE_AMD                 0x8BC3
#define GL_PERFMON_RESULT_AVAILABLE_AMD   0x8BC4
#define GL_PERFMON_RESULT_SIZE_AMD        0x8BC5
#define GL_PERFMON_RESULT_AMD             0x8BC6
    typedef void (APIENTRYP PFNGLGETPERFMONITORGROUPSAMDPROC) (GLint *numGroups, GLsizei groupsSize, GLuint *groups);
    typedef void (APIENTRYP PFNGLGETPERFMONITORCOUNTERSAMDPROC) (GLuint group, GLint *numCounters, GLint *maxActiveCounters, GLsizei counterSize, GLuint *counters);
    typedef void (APIENTRYP PFNGLGETPERFMONITORGROUPSTRINGAMDPROC) (GLuint group, GLsizei bufSize, GLsizei *length, GLchar *groupString);
    typedef void (APIENTRYP PFNGLGETPERFMONITORCOUNTERSTRINGAMDPROC) (GLuint group, GLuint counter, GLsizei bufSize, GLsizei *length, GLchar *counterString);
    typedef void (APIENTRYP PFNGLGETPERFMONITORCOUNTERINFOAMDPROC) (GLuint group, GLuint counter, GLenum pname, void *data);
    typedef void (APIENTRYP PFNGLGENPERFMONITORSAMDPROC) (GLsizei n, GLuint *monitors);
    typedef void (APIENTRYP PFNGLDELETEPERFMONITORSAMDPROC) (GLsizei n, GLuint *monitors);
    typedef void (APIENTRYP PFNGLSELECTPERFMONITORCOUNTERSAMDPROC) (GLuint monitor, GLboolean enable, GLuint group, GLint numCounters, GLuint *counterList);
    typedef void (APIENTRYP PFNGLBEGINPERFMONITORAMDPROC) (GLuint monitor);
    typedef void (APIENTRYP PFNGLENDPERFMONITORAMDPROC) (GLuint monitor);
    typedef void (APIENTRYP PFNGLGETPERFMONITORCOUNTERDATAAMDPROC) (GLuint monitor, GLenum pname, GLsizei dataSize, GLuint *data, GLint *bytesWritten);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glGetPerfMonitorGroupsAMD (GLint *numGroups, GLsizei groupsSize, GLuint *groups);
    GLAPI void APIENTRY glGetPerfMonitorCountersAMD (GLuint group, GLint *numCounters, GLint *maxActiveCounters, GLsizei counterSize, GLuint *counters);
    GLAPI void APIENTRY glGetPerfMonitorGroupStringAMD (GLuint group, GLsizei bufSize, GLsizei *length, GLchar *groupString);
    GLAPI void APIENTRY glGetPerfMonitorCounterStringAMD (GLuint group, GLuint counter, GLsizei bufSize, GLsizei *length, GLchar *counterString);
    GLAPI void APIENTRY glGetPerfMonitorCounterInfoAMD (GLuint group, GLuint counter, GLenum pname, void *data);
    GLAPI void APIENTRY glGenPerfMonitorsAMD (GLsizei n, GLuint *monitors);
    GLAPI void APIENTRY glDeletePerfMonitorsAMD (GLsizei n, GLuint *monitors);
    GLAPI void APIENTRY glSelectPerfMonitorCountersAMD (GLuint monitor, GLboolean enable, GLuint group, GLint numCounters, GLuint *counterList);
    GLAPI void APIENTRY glBeginPerfMonitorAMD (GLuint monitor);
    GLAPI void APIENTRY glEndPerfMonitorAMD (GLuint monitor);
    GLAPI void APIENTRY glGetPerfMonitorCounterDataAMD (GLuint monitor, GLenum pname, GLsizei dataSize, GLuint *data, GLint *bytesWritten);
#endif
#endif /* GL_AMD_performance_monitor */
    
#ifndef GL_APPLE_rgb_422
#define GL_APPLE_rgb_422 1
#define GL_RGB_422_APPLE                  0x8A1F
#define GL_UNSIGNED_SHORT_8_8_APPLE       0x85BA
#define GL_UNSIGNED_SHORT_8_8_REV_APPLE   0x85BB
#define GL_RGB_RAW_422_APPLE              0x8A51
#endif /* GL_APPLE_rgb_422 */
    
#ifndef GL_EXT_debug_label
#define GL_EXT_debug_label 1
#define GL_PROGRAM_PIPELINE_OBJECT_EXT    0x8A4F
#define GL_PROGRAM_OBJECT_EXT             0x8B40
#define GL_SHADER_OBJECT_EXT              0x8B48
#define GL_BUFFER_OBJECT_EXT              0x9151
#define GL_QUERY_OBJECT_EXT               0x9153
#define GL_VERTEX_ARRAY_OBJECT_EXT        0x9154
    typedef void (APIENTRYP PFNGLLABELOBJECTEXTPROC) (GLenum type, GLuint object, GLsizei length, const GLchar *label);
    typedef void (APIENTRYP PFNGLGETOBJECTLABELEXTPROC) (GLenum type, GLuint object, GLsizei bufSize, GLsizei *length, GLchar *label);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glLabelObjectEXT (GLenum type, GLuint object, GLsizei length, const GLchar *label);
    GLAPI void APIENTRY glGetObjectLabelEXT (GLenum type, GLuint object, GLsizei bufSize, GLsizei *length, GLchar *label);
#endif
#endif /* GL_EXT_debug_label */
    
#ifndef GL_EXT_debug_marker
#define GL_EXT_debug_marker 1
    typedef void (APIENTRYP PFNGLINSERTEVENTMARKEREXTPROC) (GLsizei length, const GLchar *marker);
    typedef void (APIENTRYP PFNGLPUSHGROUPMARKEREXTPROC) (GLsizei length, const GLchar *marker);
    typedef void (APIENTRYP PFNGLPOPGROUPMARKEREXTPROC) (void);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glInsertEventMarkerEXT (GLsizei length, const GLchar *marker);
    GLAPI void APIENTRY glPushGroupMarkerEXT (GLsizei length, const GLchar *marker);
    GLAPI void APIENTRY glPopGroupMarkerEXT (void);
#endif
#endif /* GL_EXT_debug_marker */
    
#ifndef GL_EXT_direct_state_access
#define GL_EXT_direct_state_access 1
#define GL_PROGRAM_MATRIX_EXT             0x8E2D
#define GL_TRANSPOSE_PROGRAM_MATRIX_EXT   0x8E2E
#define GL_PROGRAM_MATRIX_STACK_DEPTH_EXT 0x8E2F
    typedef void (APIENTRYP PFNGLMATRIXLOADFEXTPROC) (GLenum mode, const GLfloat *m);
    typedef void (APIENTRYP PFNGLMATRIXLOADDEXTPROC) (GLenum mode, const GLdouble *m);
    typedef void (APIENTRYP PFNGLMATRIXMULTFEXTPROC) (GLenum mode, const GLfloat *m);
    typedef void (APIENTRYP PFNGLMATRIXMULTDEXTPROC) (GLenum mode, const GLdouble *m);
    typedef void (APIENTRYP PFNGLMATRIXLOADIDENTITYEXTPROC) (GLenum mode);
    typedef void (APIENTRYP PFNGLMATRIXROTATEFEXTPROC) (GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
    typedef void (APIENTRYP PFNGLMATRIXROTATEDEXTPROC) (GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
    typedef void (APIENTRYP PFNGLMATRIXSCALEFEXTPROC) (GLenum mode, GLfloat x, GLfloat y, GLfloat z);
    typedef void (APIENTRYP PFNGLMATRIXSCALEDEXTPROC) (GLenum mode, GLdouble x, GLdouble y, GLdouble z);
    typedef void (APIENTRYP PFNGLMATRIXTRANSLATEFEXTPROC) (GLenum mode, GLfloat x, GLfloat y, GLfloat z);
    typedef void (APIENTRYP PFNGLMATRIXTRANSLATEDEXTPROC) (GLenum mode, GLdouble x, GLdouble y, GLdouble z);
    typedef void (APIENTRYP PFNGLMATRIXFRUSTUMEXTPROC) (GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
    typedef void (APIENTRYP PFNGLMATRIXORTHOEXTPROC) (GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
    typedef void (APIENTRYP PFNGLMATRIXPOPEXTPROC) (GLenum mode);
    typedef void (APIENTRYP PFNGLMATRIXPUSHEXTPROC) (GLenum mode);
    typedef void (APIENTRYP PFNGLCLIENTATTRIBDEFAULTEXTPROC) (GLbitfield mask);
    typedef void (APIENTRYP PFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC) (GLbitfield mask);
    typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFEXTPROC) (GLuint texture, GLenum target, GLenum pname, GLfloat param);
    typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFVEXTPROC) (GLuint texture, GLenum target, GLenum pname, const GLfloat *params);
    typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIEXTPROC) (GLuint texture, GLenum target, GLenum pname, GLint param);
    typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIVEXTPROC) (GLuint texture, GLenum target, GLenum pname, const GLint *params);
    typedef void (APIENTRYP PFNGLTEXTUREIMAGE1DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
    typedef void (APIENTRYP PFNGLTEXTUREIMAGE2DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
    typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE1DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
    typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE2DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
    typedef void (APIENTRYP PFNGLCOPYTEXTUREIMAGE1DEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
    typedef void (APIENTRYP PFNGLCOPYTEXTUREIMAGE2DEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
    typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
    typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    typedef void (APIENTRYP PFNGLGETTEXTUREIMAGEEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
    typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERFVEXTPROC) (GLuint texture, GLenum target, GLenum pname, GLfloat *params);
    typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIVEXTPROC) (GLuint texture, GLenum target, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat *params);
    typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLTEXTUREIMAGE3DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
    typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE3DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
    typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    typedef void (APIENTRYP PFNGLBINDMULTITEXTUREEXTPROC) (GLenum texunit, GLenum target, GLuint texture);
    typedef void (APIENTRYP PFNGLMULTITEXCOORDPOINTEREXTPROC) (GLenum texunit, GLint size, GLenum type, GLsizei stride, const void *pointer);
    typedef void (APIENTRYP PFNGLMULTITEXENVFEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLfloat param);
    typedef void (APIENTRYP PFNGLMULTITEXENVFVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, const GLfloat *params);
    typedef void (APIENTRYP PFNGLMULTITEXENVIEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLint param);
    typedef void (APIENTRYP PFNGLMULTITEXENVIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, const GLint *params);
    typedef void (APIENTRYP PFNGLMULTITEXGENDEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, GLdouble param);
    typedef void (APIENTRYP PFNGLMULTITEXGENDVEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, const GLdouble *params);
    typedef void (APIENTRYP PFNGLMULTITEXGENFEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, GLfloat param);
    typedef void (APIENTRYP PFNGLMULTITEXGENFVEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, const GLfloat *params);
    typedef void (APIENTRYP PFNGLMULTITEXGENIEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, GLint param);
    typedef void (APIENTRYP PFNGLMULTITEXGENIVEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, const GLint *params);
    typedef void (APIENTRYP PFNGLGETMULTITEXENVFVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLfloat *params);
    typedef void (APIENTRYP PFNGLGETMULTITEXENVIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLGETMULTITEXGENDVEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, GLdouble *params);
    typedef void (APIENTRYP PFNGLGETMULTITEXGENFVEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, GLfloat *params);
    typedef void (APIENTRYP PFNGLGETMULTITEXGENIVEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLMULTITEXPARAMETERIEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLint param);
    typedef void (APIENTRYP PFNGLMULTITEXPARAMETERIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, const GLint *params);
    typedef void (APIENTRYP PFNGLMULTITEXPARAMETERFEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLfloat param);
    typedef void (APIENTRYP PFNGLMULTITEXPARAMETERFVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, const GLfloat *params);
    typedef void (APIENTRYP PFNGLMULTITEXIMAGE1DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
    typedef void (APIENTRYP PFNGLMULTITEXIMAGE2DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
    typedef void (APIENTRYP PFNGLMULTITEXSUBIMAGE1DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
    typedef void (APIENTRYP PFNGLMULTITEXSUBIMAGE2DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
    typedef void (APIENTRYP PFNGLCOPYMULTITEXIMAGE1DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
    typedef void (APIENTRYP PFNGLCOPYMULTITEXIMAGE2DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
    typedef void (APIENTRYP PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
    typedef void (APIENTRYP PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    typedef void (APIENTRYP PFNGLGETMULTITEXIMAGEEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
    typedef void (APIENTRYP PFNGLGETMULTITEXPARAMETERFVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLfloat *params);
    typedef void (APIENTRYP PFNGLGETMULTITEXPARAMETERIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat *params);
    typedef void (APIENTRYP PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLMULTITEXIMAGE3DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
    typedef void (APIENTRYP PFNGLMULTITEXSUBIMAGE3DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
    typedef void (APIENTRYP PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    typedef void (APIENTRYP PFNGLENABLECLIENTSTATEINDEXEDEXTPROC) (GLenum array, GLuint index);
    typedef void (APIENTRYP PFNGLDISABLECLIENTSTATEINDEXEDEXTPROC) (GLenum array, GLuint index);
    typedef void (APIENTRYP PFNGLGETFLOATINDEXEDVEXTPROC) (GLenum target, GLuint index, GLfloat *data);
    typedef void (APIENTRYP PFNGLGETDOUBLEINDEXEDVEXTPROC) (GLenum target, GLuint index, GLdouble *data);
    typedef void (APIENTRYP PFNGLGETPOINTERINDEXEDVEXTPROC) (GLenum target, GLuint index, void **data);
    typedef void (APIENTRYP PFNGLENABLEINDEXEDEXTPROC) (GLenum target, GLuint index);
    typedef void (APIENTRYP PFNGLDISABLEINDEXEDEXTPROC) (GLenum target, GLuint index);
    typedef GLboolean (APIENTRYP PFNGLISENABLEDINDEXEDEXTPROC) (GLenum target, GLuint index);
    typedef void (APIENTRYP PFNGLGETINTEGERINDEXEDVEXTPROC) (GLenum target, GLuint index, GLint *data);
    typedef void (APIENTRYP PFNGLGETBOOLEANINDEXEDVEXTPROC) (GLenum target, GLuint index, GLboolean *data);
    typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *bits);
    typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *bits);
    typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *bits);
    typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *bits);
    typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *bits);
    typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *bits);
    typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC) (GLuint texture, GLenum target, GLint lod, void *img);
    typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *bits);
    typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *bits);
    typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *bits);
    typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *bits);
    typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *bits);
    typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *bits);
    typedef void (APIENTRYP PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC) (GLenum texunit, GLenum target, GLint lod, void *img);
    typedef void (APIENTRYP PFNGLMATRIXLOADTRANSPOSEFEXTPROC) (GLenum mode, const GLfloat *m);
    typedef void (APIENTRYP PFNGLMATRIXLOADTRANSPOSEDEXTPROC) (GLenum mode, const GLdouble *m);
    typedef void (APIENTRYP PFNGLMATRIXMULTTRANSPOSEFEXTPROC) (GLenum mode, const GLfloat *m);
    typedef void (APIENTRYP PFNGLMATRIXMULTTRANSPOSEDEXTPROC) (GLenum mode, const GLdouble *m);
    typedef void (APIENTRYP PFNGLNAMEDBUFFERDATAEXTPROC) (GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
    typedef void (APIENTRYP PFNGLNAMEDBUFFERSUBDATAEXTPROC) (GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
    typedef void *(APIENTRYP PFNGLMAPNAMEDBUFFEREXTPROC) (GLuint buffer, GLenum access);
    typedef GLboolean (APIENTRYP PFNGLUNMAPNAMEDBUFFEREXTPROC) (GLuint buffer);
    typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC) (GLuint buffer, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPOINTERVEXTPROC) (GLuint buffer, GLenum pname, void **params);
    typedef void (APIENTRYP PFNGLGETNAMEDBUFFERSUBDATAEXTPROC) (GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FEXTPROC) (GLuint program, GLint location, GLfloat v0);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FEXTPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FEXTPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FEXTPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IEXTPROC) (GLuint program, GLint location, GLint v0);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IEXTPROC) (GLuint program, GLint location, GLint v0, GLint v1);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IEXTPROC) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IEXTPROC) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLint *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLint *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLint *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLint *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    typedef void (APIENTRYP PFNGLTEXTUREBUFFEREXTPROC) (GLuint texture, GLenum target, GLenum internalformat, GLuint buffer);
    typedef void (APIENTRYP PFNGLMULTITEXBUFFEREXTPROC) (GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer);
    typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIIVEXTPROC) (GLuint texture, GLenum target, GLenum pname, const GLint *params);
    typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIUIVEXTPROC) (GLuint texture, GLenum target, GLenum pname, const GLuint *params);
    typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIIVEXTPROC) (GLuint texture, GLenum target, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIUIVEXTPROC) (GLuint texture, GLenum target, GLenum pname, GLuint *params);
    typedef void (APIENTRYP PFNGLMULTITEXPARAMETERIIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, const GLint *params);
    typedef void (APIENTRYP PFNGLMULTITEXPARAMETERIUIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, const GLuint *params);
    typedef void (APIENTRYP PFNGLGETMULTITEXPARAMETERIIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLGETMULTITEXPARAMETERIUIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLuint *params);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIEXTPROC) (GLuint program, GLint location, GLuint v0);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIEXTPROC) (GLuint program, GLint location, GLuint v0, GLuint v1);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIEXTPROC) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIEXTPROC) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLuint *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLuint *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLuint *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLuint *value);
    typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC) (GLuint program, GLenum target, GLuint index, GLsizei count, const GLfloat *params);
    typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC) (GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
    typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC) (GLuint program, GLenum target, GLuint index, const GLint *params);
    typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC) (GLuint program, GLenum target, GLuint index, GLsizei count, const GLint *params);
    typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC) (GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
    typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC) (GLuint program, GLenum target, GLuint index, const GLuint *params);
    typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC) (GLuint program, GLenum target, GLuint index, GLsizei count, const GLuint *params);
    typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC) (GLuint program, GLenum target, GLuint index, GLint *params);
    typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC) (GLuint program, GLenum target, GLuint index, GLuint *params);
    typedef void (APIENTRYP PFNGLENABLECLIENTSTATEIEXTPROC) (GLenum array, GLuint index);
    typedef void (APIENTRYP PFNGLDISABLECLIENTSTATEIEXTPROC) (GLenum array, GLuint index);
    typedef void (APIENTRYP PFNGLGETFLOATI_VEXTPROC) (GLenum pname, GLuint index, GLfloat *params);
    typedef void (APIENTRYP PFNGLGETDOUBLEI_VEXTPROC) (GLenum pname, GLuint index, GLdouble *params);
    typedef void (APIENTRYP PFNGLGETPOINTERI_VEXTPROC) (GLenum pname, GLuint index, void **params);
    typedef void (APIENTRYP PFNGLNAMEDPROGRAMSTRINGEXTPROC) (GLuint program, GLenum target, GLenum format, GLsizei len, const void *string);
    typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC) (GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC) (GLuint program, GLenum target, GLuint index, const GLdouble *params);
    typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC) (GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC) (GLuint program, GLenum target, GLuint index, const GLfloat *params);
    typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC) (GLuint program, GLenum target, GLuint index, GLdouble *params);
    typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC) (GLuint program, GLenum target, GLuint index, GLfloat *params);
    typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMIVEXTPROC) (GLuint program, GLenum target, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMSTRINGEXTPROC) (GLuint program, GLenum target, GLenum pname, void *string);
    typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC) (GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
    typedef void (APIENTRYP PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC) (GLuint renderbuffer, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC) (GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
    typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC) (GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
    typedef GLenum (APIENTRYP PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC) (GLuint framebuffer, GLenum target);
    typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC) (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
    typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC) (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
    typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC) (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
    typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC) (GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
    typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC) (GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLGENERATETEXTUREMIPMAPEXTPROC) (GLuint texture, GLenum target);
    typedef void (APIENTRYP PFNGLGENERATEMULTITEXMIPMAPEXTPROC) (GLenum texunit, GLenum target);
    typedef void (APIENTRYP PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC) (GLuint framebuffer, GLenum mode);
    typedef void (APIENTRYP PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC) (GLuint framebuffer, GLsizei n, const GLenum *bufs);
    typedef void (APIENTRYP PFNGLFRAMEBUFFERREADBUFFEREXTPROC) (GLuint framebuffer, GLenum mode);
    typedef void (APIENTRYP PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC) (GLuint framebuffer, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC) (GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
    typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
    typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
    typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face);
    typedef void (APIENTRYP PFNGLTEXTURERENDERBUFFEREXTPROC) (GLuint texture, GLenum target, GLuint renderbuffer);
    typedef void (APIENTRYP PFNGLMULTITEXRENDERBUFFEREXTPROC) (GLenum texunit, GLenum target, GLuint renderbuffer);
    typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXOFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
    typedef void (APIENTRYP PFNGLVERTEXARRAYCOLOROFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
    typedef void (APIENTRYP PFNGLVERTEXARRAYEDGEFLAGOFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset);
    typedef void (APIENTRYP PFNGLVERTEXARRAYINDEXOFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
    typedef void (APIENTRYP PFNGLVERTEXARRAYNORMALOFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
    typedef void (APIENTRYP PFNGLVERTEXARRAYTEXCOORDOFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
    typedef void (APIENTRYP PFNGLVERTEXARRAYMULTITEXCOORDOFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLenum texunit, GLint size, GLenum type, GLsizei stride, GLintptr offset);
    typedef void (APIENTRYP PFNGLVERTEXARRAYFOGCOORDOFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
    typedef void (APIENTRYP PFNGLVERTEXARRAYSECONDARYCOLOROFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
    typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBOFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset);
    typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
    typedef void (APIENTRYP PFNGLENABLEVERTEXARRAYEXTPROC) (GLuint vaobj, GLenum array);
    typedef void (APIENTRYP PFNGLDISABLEVERTEXARRAYEXTPROC) (GLuint vaobj, GLenum array);
    typedef void (APIENTRYP PFNGLENABLEVERTEXARRAYATTRIBEXTPROC) (GLuint vaobj, GLuint index);
    typedef void (APIENTRYP PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC) (GLuint vaobj, GLuint index);
    typedef void (APIENTRYP PFNGLGETVERTEXARRAYINTEGERVEXTPROC) (GLuint vaobj, GLenum pname, GLint *param);
    typedef void (APIENTRYP PFNGLGETVERTEXARRAYPOINTERVEXTPROC) (GLuint vaobj, GLenum pname, void **param);
    typedef void (APIENTRYP PFNGLGETVERTEXARRAYINTEGERI_VEXTPROC) (GLuint vaobj, GLuint index, GLenum pname, GLint *param);
    typedef void (APIENTRYP PFNGLGETVERTEXARRAYPOINTERI_VEXTPROC) (GLuint vaobj, GLuint index, GLenum pname, void **param);
    typedef void *(APIENTRYP PFNGLMAPNAMEDBUFFERRANGEEXTPROC) (GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
    typedef void (APIENTRYP PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC) (GLuint buffer, GLintptr offset, GLsizeiptr length);
    typedef void (APIENTRYP PFNGLNAMEDBUFFERSTORAGEEXTPROC) (GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
    typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERDATAEXTPROC) (GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
    typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC) (GLuint buffer, GLenum internalformat, GLsizeiptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
    typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC) (GLuint framebuffer, GLenum pname, GLint param);
    typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC) (GLuint framebuffer, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DEXTPROC) (GLuint program, GLint location, GLdouble x);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DEXTPROC) (GLuint program, GLint location, GLdouble x, GLdouble y);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DEXTPROC) (GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DEXTPROC) (GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2DVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3DVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4DVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3DVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4DVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2DVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4DVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2DVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3DVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    typedef void (APIENTRYP PFNGLTEXTUREBUFFERRANGEEXTPROC) (GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
    typedef void (APIENTRYP PFNGLTEXTURESTORAGE1DEXTPROC) (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
    typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DEXTPROC) (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
    typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DEXTPROC) (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
    typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC) (GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
    typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC) (GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
    typedef void (APIENTRYP PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC) (GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
    typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
    typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
    typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
    typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC) (GLuint vaobj, GLuint attribindex, GLuint bindingindex);
    typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC) (GLuint vaobj, GLuint bindingindex, GLuint divisor);
    typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBLOFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
    typedef void (APIENTRYP PFNGLTEXTUREPAGECOMMITMENTEXTPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
    typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBDIVISOREXTPROC) (GLuint vaobj, GLuint index, GLuint divisor);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glMatrixLoadfEXT (GLenum mode, const GLfloat *m);
    GLAPI void APIENTRY glMatrixLoaddEXT (GLenum mode, const GLdouble *m);
    GLAPI void APIENTRY glMatrixMultfEXT (GLenum mode, const GLfloat *m);
    GLAPI void APIENTRY glMatrixMultdEXT (GLenum mode, const GLdouble *m);
    GLAPI void APIENTRY glMatrixLoadIdentityEXT (GLenum mode);
    GLAPI void APIENTRY glMatrixRotatefEXT (GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
    GLAPI void APIENTRY glMatrixRotatedEXT (GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
    GLAPI void APIENTRY glMatrixScalefEXT (GLenum mode, GLfloat x, GLfloat y, GLfloat z);
    GLAPI void APIENTRY glMatrixScaledEXT (GLenum mode, GLdouble x, GLdouble y, GLdouble z);
    GLAPI void APIENTRY glMatrixTranslatefEXT (GLenum mode, GLfloat x, GLfloat y, GLfloat z);
    GLAPI void APIENTRY glMatrixTranslatedEXT (GLenum mode, GLdouble x, GLdouble y, GLdouble z);
    GLAPI void APIENTRY glMatrixFrustumEXT (GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
    GLAPI void APIENTRY glMatrixOrthoEXT (GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
    GLAPI void APIENTRY glMatrixPopEXT (GLenum mode);
    GLAPI void APIENTRY glMatrixPushEXT (GLenum mode);
    GLAPI void APIENTRY glClientAttribDefaultEXT (GLbitfield mask);
    GLAPI void APIENTRY glPushClientAttribDefaultEXT (GLbitfield mask);
    GLAPI void APIENTRY glTextureParameterfEXT (GLuint texture, GLenum target, GLenum pname, GLfloat param);
    GLAPI void APIENTRY glTextureParameterfvEXT (GLuint texture, GLenum target, GLenum pname, const GLfloat *params);
    GLAPI void APIENTRY glTextureParameteriEXT (GLuint texture, GLenum target, GLenum pname, GLint param);
    GLAPI void APIENTRY glTextureParameterivEXT (GLuint texture, GLenum target, GLenum pname, const GLint *params);
    GLAPI void APIENTRY glTextureImage1DEXT (GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
    GLAPI void APIENTRY glTextureImage2DEXT (GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
    GLAPI void APIENTRY glTextureSubImage1DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
    GLAPI void APIENTRY glTextureSubImage2DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
    GLAPI void APIENTRY glCopyTextureImage1DEXT (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
    GLAPI void APIENTRY glCopyTextureImage2DEXT (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
    GLAPI void APIENTRY glCopyTextureSubImage1DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
    GLAPI void APIENTRY glCopyTextureSubImage2DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    GLAPI void APIENTRY glGetTextureImageEXT (GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
    GLAPI void APIENTRY glGetTextureParameterfvEXT (GLuint texture, GLenum target, GLenum pname, GLfloat *params);
    GLAPI void APIENTRY glGetTextureParameterivEXT (GLuint texture, GLenum target, GLenum pname, GLint *params);
    GLAPI void APIENTRY glGetTextureLevelParameterfvEXT (GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat *params);
    GLAPI void APIENTRY glGetTextureLevelParameterivEXT (GLuint texture, GLenum target, GLint level, GLenum pname, GLint *params);
    GLAPI void APIENTRY glTextureImage3DEXT (GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
    GLAPI void APIENTRY glTextureSubImage3DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
    GLAPI void APIENTRY glCopyTextureSubImage3DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    GLAPI void APIENTRY glBindMultiTextureEXT (GLenum texunit, GLenum target, GLuint texture);
    GLAPI void APIENTRY glMultiTexCoordPointerEXT (GLenum texunit, GLint size, GLenum type, GLsizei stride, const void *pointer);
    GLAPI void APIENTRY glMultiTexEnvfEXT (GLenum texunit, GLenum target, GLenum pname, GLfloat param);
    GLAPI void APIENTRY glMultiTexEnvfvEXT (GLenum texunit, GLenum target, GLenum pname, const GLfloat *params);
    GLAPI void APIENTRY glMultiTexEnviEXT (GLenum texunit, GLenum target, GLenum pname, GLint param);
    GLAPI void APIENTRY glMultiTexEnvivEXT (GLenum texunit, GLenum target, GLenum pname, const GLint *params);
    GLAPI void APIENTRY glMultiTexGendEXT (GLenum texunit, GLenum coord, GLenum pname, GLdouble param);
    GLAPI void APIENTRY glMultiTexGendvEXT (GLenum texunit, GLenum coord, GLenum pname, const GLdouble *params);
    GLAPI void APIENTRY glMultiTexGenfEXT (GLenum texunit, GLenum coord, GLenum pname, GLfloat param);
    GLAPI void APIENTRY glMultiTexGenfvEXT (GLenum texunit, GLenum coord, GLenum pname, const GLfloat *params);
    GLAPI void APIENTRY glMultiTexGeniEXT (GLenum texunit, GLenum coord, GLenum pname, GLint param);
    GLAPI void APIENTRY glMultiTexGenivEXT (GLenum texunit, GLenum coord, GLenum pname, const GLint *params);
    GLAPI void APIENTRY glGetMultiTexEnvfvEXT (GLenum texunit, GLenum target, GLenum pname, GLfloat *params);
    GLAPI void APIENTRY glGetMultiTexEnvivEXT (GLenum texunit, GLenum target, GLenum pname, GLint *params);
    GLAPI void APIENTRY glGetMultiTexGendvEXT (GLenum texunit, GLenum coord, GLenum pname, GLdouble *params);
    GLAPI void APIENTRY glGetMultiTexGenfvEXT (GLenum texunit, GLenum coord, GLenum pname, GLfloat *params);
    GLAPI void APIENTRY glGetMultiTexGenivEXT (GLenum texunit, GLenum coord, GLenum pname, GLint *params);
    GLAPI void APIENTRY glMultiTexParameteriEXT (GLenum texunit, GLenum target, GLenum pname, GLint param);
    GLAPI void APIENTRY glMultiTexParameterivEXT (GLenum texunit, GLenum target, GLenum pname, const GLint *params);
    GLAPI void APIENTRY glMultiTexParameterfEXT (GLenum texunit, GLenum target, GLenum pname, GLfloat param);
    GLAPI void APIENTRY glMultiTexParameterfvEXT (GLenum texunit, GLenum target, GLenum pname, const GLfloat *params);
    GLAPI void APIENTRY glMultiTexImage1DEXT (GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
    GLAPI void APIENTRY glMultiTexImage2DEXT (GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
    GLAPI void APIENTRY glMultiTexSubImage1DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
    GLAPI void APIENTRY glMultiTexSubImage2DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
    GLAPI void APIENTRY glCopyMultiTexImage1DEXT (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
    GLAPI void APIENTRY glCopyMultiTexImage2DEXT (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
    GLAPI void APIENTRY glCopyMultiTexSubImage1DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
    GLAPI void APIENTRY glCopyMultiTexSubImage2DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    GLAPI void APIENTRY glGetMultiTexImageEXT (GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
    GLAPI void APIENTRY glGetMultiTexParameterfvEXT (GLenum texunit, GLenum target, GLenum pname, GLfloat *params);
    GLAPI void APIENTRY glGetMultiTexParameterivEXT (GLenum texunit, GLenum target, GLenum pname, GLint *params);
    GLAPI void APIENTRY glGetMultiTexLevelParameterfvEXT (GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat *params);
    GLAPI void APIENTRY glGetMultiTexLevelParameterivEXT (GLenum texunit, GLenum target, GLint level, GLenum pname, GLint *params);
    GLAPI void APIENTRY glMultiTexImage3DEXT (GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
    GLAPI void APIENTRY glMultiTexSubImage3DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
    GLAPI void APIENTRY glCopyMultiTexSubImage3DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    GLAPI void APIENTRY glEnableClientStateIndexedEXT (GLenum array, GLuint index);
    GLAPI void APIENTRY glDisableClientStateIndexedEXT (GLenum array, GLuint index);
    GLAPI void APIENTRY glGetFloatIndexedvEXT (GLenum target, GLuint index, GLfloat *data);
    GLAPI void APIENTRY glGetDoubleIndexedvEXT (GLenum target, GLuint index, GLdouble *data);
    GLAPI void APIENTRY glGetPointerIndexedvEXT (GLenum target, GLuint index, void **data);
    GLAPI void APIENTRY glEnableIndexedEXT (GLenum target, GLuint index);
    GLAPI void APIENTRY glDisableIndexedEXT (GLenum target, GLuint index);
    GLAPI GLboolean APIENTRY glIsEnabledIndexedEXT (GLenum target, GLuint index);
    GLAPI void APIENTRY glGetIntegerIndexedvEXT (GLenum target, GLuint index, GLint *data);
    GLAPI void APIENTRY glGetBooleanIndexedvEXT (GLenum target, GLuint index, GLboolean *data);
    GLAPI void APIENTRY glCompressedTextureImage3DEXT (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *bits);
    GLAPI void APIENTRY glCompressedTextureImage2DEXT (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *bits);
    GLAPI void APIENTRY glCompressedTextureImage1DEXT (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *bits);
    GLAPI void APIENTRY glCompressedTextureSubImage3DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *bits);
    GLAPI void APIENTRY glCompressedTextureSubImage2DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *bits);
    GLAPI void APIENTRY glCompressedTextureSubImage1DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *bits);
    GLAPI void APIENTRY glGetCompressedTextureImageEXT (GLuint texture, GLenum target, GLint lod, void *img);
    GLAPI void APIENTRY glCompressedMultiTexImage3DEXT (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *bits);
    GLAPI void APIENTRY glCompressedMultiTexImage2DEXT (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *bits);
    GLAPI void APIENTRY glCompressedMultiTexImage1DEXT (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *bits);
    GLAPI void APIENTRY glCompressedMultiTexSubImage3DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *bits);
    GLAPI void APIENTRY glCompressedMultiTexSubImage2DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *bits);
    GLAPI void APIENTRY glCompressedMultiTexSubImage1DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *bits);
    GLAPI void APIENTRY glGetCompressedMultiTexImageEXT (GLenum texunit, GLenum target, GLint lod, void *img);
    GLAPI void APIENTRY glMatrixLoadTransposefEXT (GLenum mode, const GLfloat *m);
    GLAPI void APIENTRY glMatrixLoadTransposedEXT (GLenum mode, const GLdouble *m);
    GLAPI void APIENTRY glMatrixMultTransposefEXT (GLenum mode, const GLfloat *m);
    GLAPI void APIENTRY glMatrixMultTransposedEXT (GLenum mode, const GLdouble *m);
    GLAPI void APIENTRY glNamedBufferDataEXT (GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
    GLAPI void APIENTRY glNamedBufferSubDataEXT (GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
    GLAPI void *APIENTRY glMapNamedBufferEXT (GLuint buffer, GLenum access);
    GLAPI GLboolean APIENTRY glUnmapNamedBufferEXT (GLuint buffer);
    GLAPI void APIENTRY glGetNamedBufferParameterivEXT (GLuint buffer, GLenum pname, GLint *params);
    GLAPI void APIENTRY glGetNamedBufferPointervEXT (GLuint buffer, GLenum pname, void **params);
    GLAPI void APIENTRY glGetNamedBufferSubDataEXT (GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
    GLAPI void APIENTRY glProgramUniform1fEXT (GLuint program, GLint location, GLfloat v0);
    GLAPI void APIENTRY glProgramUniform2fEXT (GLuint program, GLint location, GLfloat v0, GLfloat v1);
    GLAPI void APIENTRY glProgramUniform3fEXT (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
    GLAPI void APIENTRY glProgramUniform4fEXT (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
    GLAPI void APIENTRY glProgramUniform1iEXT (GLuint program, GLint location, GLint v0);
    GLAPI void APIENTRY glProgramUniform2iEXT (GLuint program, GLint location, GLint v0, GLint v1);
    GLAPI void APIENTRY glProgramUniform3iEXT (GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
    GLAPI void APIENTRY glProgramUniform4iEXT (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
    GLAPI void APIENTRY glProgramUniform1fvEXT (GLuint program, GLint location, GLsizei count, const GLfloat *value);
    GLAPI void APIENTRY glProgramUniform2fvEXT (GLuint program, GLint location, GLsizei count, const GLfloat *value);
    GLAPI void APIENTRY glProgramUniform3fvEXT (GLuint program, GLint location, GLsizei count, const GLfloat *value);
    GLAPI void APIENTRY glProgramUniform4fvEXT (GLuint program, GLint location, GLsizei count, const GLfloat *value);
    GLAPI void APIENTRY glProgramUniform1ivEXT (GLuint program, GLint location, GLsizei count, const GLint *value);
    GLAPI void APIENTRY glProgramUniform2ivEXT (GLuint program, GLint location, GLsizei count, const GLint *value);
    GLAPI void APIENTRY glProgramUniform3ivEXT (GLuint program, GLint location, GLsizei count, const GLint *value);
    GLAPI void APIENTRY glProgramUniform4ivEXT (GLuint program, GLint location, GLsizei count, const GLint *value);
    GLAPI void APIENTRY glProgramUniformMatrix2fvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    GLAPI void APIENTRY glProgramUniformMatrix3fvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    GLAPI void APIENTRY glProgramUniformMatrix4fvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    GLAPI void APIENTRY glProgramUniformMatrix2x3fvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    GLAPI void APIENTRY glProgramUniformMatrix3x2fvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    GLAPI void APIENTRY glProgramUniformMatrix2x4fvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    GLAPI void APIENTRY glProgramUniformMatrix4x2fvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    GLAPI void APIENTRY glProgramUniformMatrix3x4fvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    GLAPI void APIENTRY glProgramUniformMatrix4x3fvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    GLAPI void APIENTRY glTextureBufferEXT (GLuint texture, GLenum target, GLenum internalformat, GLuint buffer);
    GLAPI void APIENTRY glMultiTexBufferEXT (GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer);
    GLAPI void APIENTRY glTextureParameterIivEXT (GLuint texture, GLenum target, GLenum pname, const GLint *params);
    GLAPI void APIENTRY glTextureParameterIuivEXT (GLuint texture, GLenum target, GLenum pname, const GLuint *params);
    GLAPI void APIENTRY glGetTextureParameterIivEXT (GLuint texture, GLenum target, GLenum pname, GLint *params);
    GLAPI void APIENTRY glGetTextureParameterIuivEXT (GLuint texture, GLenum target, GLenum pname, GLuint *params);
    GLAPI void APIENTRY glMultiTexParameterIivEXT (GLenum texunit, GLenum target, GLenum pname, const GLint *params);
    GLAPI void APIENTRY glMultiTexParameterIuivEXT (GLenum texunit, GLenum target, GLenum pname, const GLuint *params);
    GLAPI void APIENTRY glGetMultiTexParameterIivEXT (GLenum texunit, GLenum target, GLenum pname, GLint *params);
    GLAPI void APIENTRY glGetMultiTexParameterIuivEXT (GLenum texunit, GLenum target, GLenum pname, GLuint *params);
    GLAPI void APIENTRY glProgramUniform1uiEXT (GLuint program, GLint location, GLuint v0);
    GLAPI void APIENTRY glProgramUniform2uiEXT (GLuint program, GLint location, GLuint v0, GLuint v1);
    GLAPI void APIENTRY glProgramUniform3uiEXT (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
    GLAPI void APIENTRY glProgramUniform4uiEXT (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
    GLAPI void APIENTRY glProgramUniform1uivEXT (GLuint program, GLint location, GLsizei count, const GLuint *value);
    GLAPI void APIENTRY glProgramUniform2uivEXT (GLuint program, GLint location, GLsizei count, const GLuint *value);
    GLAPI void APIENTRY glProgramUniform3uivEXT (GLuint program, GLint location, GLsizei count, const GLuint *value);
    GLAPI void APIENTRY glProgramUniform4uivEXT (GLuint program, GLint location, GLsizei count, const GLuint *value);
    GLAPI void APIENTRY glNamedProgramLocalParameters4fvEXT (GLuint program, GLenum target, GLuint index, GLsizei count, const GLfloat *params);
    GLAPI void APIENTRY glNamedProgramLocalParameterI4iEXT (GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
    GLAPI void APIENTRY glNamedProgramLocalParameterI4ivEXT (GLuint program, GLenum target, GLuint index, const GLint *params);
    GLAPI void APIENTRY glNamedProgramLocalParametersI4ivEXT (GLuint program, GLenum target, GLuint index, GLsizei count, const GLint *params);
    GLAPI void APIENTRY glNamedProgramLocalParameterI4uiEXT (GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
    GLAPI void APIENTRY glNamedProgramLocalParameterI4uivEXT (GLuint program, GLenum target, GLuint index, const GLuint *params);
    GLAPI void APIENTRY glNamedProgramLocalParametersI4uivEXT (GLuint program, GLenum target, GLuint index, GLsizei count, const GLuint *params);
    GLAPI void APIENTRY glGetNamedProgramLocalParameterIivEXT (GLuint program, GLenum target, GLuint index, GLint *params);
    GLAPI void APIENTRY glGetNamedProgramLocalParameterIuivEXT (GLuint program, GLenum target, GLuint index, GLuint *params);
    GLAPI void APIENTRY glEnableClientStateiEXT (GLenum array, GLuint index);
    GLAPI void APIENTRY glDisableClientStateiEXT (GLenum array, GLuint index);
    GLAPI void APIENTRY glGetFloati_vEXT (GLenum pname, GLuint index, GLfloat *params);
    GLAPI void APIENTRY glGetDoublei_vEXT (GLenum pname, GLuint index, GLdouble *params);
    GLAPI void APIENTRY glGetPointeri_vEXT (GLenum pname, GLuint index, void **params);
    GLAPI void APIENTRY glNamedProgramStringEXT (GLuint program, GLenum target, GLenum format, GLsizei len, const void *string);
    GLAPI void APIENTRY glNamedProgramLocalParameter4dEXT (GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    GLAPI void APIENTRY glNamedProgramLocalParameter4dvEXT (GLuint program, GLenum target, GLuint index, const GLdouble *params);
    GLAPI void APIENTRY glNamedProgramLocalParameter4fEXT (GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    GLAPI void APIENTRY glNamedProgramLocalParameter4fvEXT (GLuint program, GLenum target, GLuint index, const GLfloat *params);
    GLAPI void APIENTRY glGetNamedProgramLocalParameterdvEXT (GLuint program, GLenum target, GLuint index, GLdouble *params);
    GLAPI void APIENTRY glGetNamedProgramLocalParameterfvEXT (GLuint program, GLenum target, GLuint index, GLfloat *params);
    GLAPI void APIENTRY glGetNamedProgramivEXT (GLuint program, GLenum target, GLenum pname, GLint *params);
    GLAPI void APIENTRY glGetNamedProgramStringEXT (GLuint program, GLenum target, GLenum pname, void *string);
    GLAPI void APIENTRY glNamedRenderbufferStorageEXT (GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
    GLAPI void APIENTRY glGetNamedRenderbufferParameterivEXT (GLuint renderbuffer, GLenum pname, GLint *params);
    GLAPI void APIENTRY glNamedRenderbufferStorageMultisampleEXT (GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
    GLAPI void APIENTRY glNamedRenderbufferStorageMultisampleCoverageEXT (GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
    GLAPI GLenum APIENTRY glCheckNamedFramebufferStatusEXT (GLuint framebuffer, GLenum target);
    GLAPI void APIENTRY glNamedFramebufferTexture1DEXT (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
    GLAPI void APIENTRY glNamedFramebufferTexture2DEXT (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
    GLAPI void APIENTRY glNamedFramebufferTexture3DEXT (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
    GLAPI void APIENTRY glNamedFramebufferRenderbufferEXT (GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
    GLAPI void APIENTRY glGetNamedFramebufferAttachmentParameterivEXT (GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
    GLAPI void APIENTRY glGenerateTextureMipmapEXT (GLuint texture, GLenum target);
    GLAPI void APIENTRY glGenerateMultiTexMipmapEXT (GLenum texunit, GLenum target);
    GLAPI void APIENTRY glFramebufferDrawBufferEXT (GLuint framebuffer, GLenum mode);
    GLAPI void APIENTRY glFramebufferDrawBuffersEXT (GLuint framebuffer, GLsizei n, const GLenum *bufs);
    GLAPI void APIENTRY glFramebufferReadBufferEXT (GLuint framebuffer, GLenum mode);
    GLAPI void APIENTRY glGetFramebufferParameterivEXT (GLuint framebuffer, GLenum pname, GLint *params);
    GLAPI void APIENTRY glNamedCopyBufferSubDataEXT (GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
    GLAPI void APIENTRY glNamedFramebufferTextureEXT (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
    GLAPI void APIENTRY glNamedFramebufferTextureLayerEXT (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
    GLAPI void APIENTRY glNamedFramebufferTextureFaceEXT (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face);
    GLAPI void APIENTRY glTextureRenderbufferEXT (GLuint texture, GLenum target, GLuint renderbuffer);
    GLAPI void APIENTRY glMultiTexRenderbufferEXT (GLenum texunit, GLenum target, GLuint renderbuffer);
    GLAPI void APIENTRY glVertexArrayVertexOffsetEXT (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
    GLAPI void APIENTRY glVertexArrayColorOffsetEXT (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
    GLAPI void APIENTRY glVertexArrayEdgeFlagOffsetEXT (GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset);
    GLAPI void APIENTRY glVertexArrayIndexOffsetEXT (GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
    GLAPI void APIENTRY glVertexArrayNormalOffsetEXT (GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
    GLAPI void APIENTRY glVertexArrayTexCoordOffsetEXT (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
    GLAPI void APIENTRY glVertexArrayMultiTexCoordOffsetEXT (GLuint vaobj, GLuint buffer, GLenum texunit, GLint size, GLenum type, GLsizei stride, GLintptr offset);
    GLAPI void APIENTRY glVertexArrayFogCoordOffsetEXT (GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
    GLAPI void APIENTRY glVertexArraySecondaryColorOffsetEXT (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
    GLAPI void APIENTRY glVertexArrayVertexAttribOffsetEXT (GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset);
    GLAPI void APIENTRY glVertexArrayVertexAttribIOffsetEXT (GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
    GLAPI void APIENTRY glEnableVertexArrayEXT (GLuint vaobj, GLenum array);
    GLAPI void APIENTRY glDisableVertexArrayEXT (GLuint vaobj, GLenum array);
    GLAPI void APIENTRY glEnableVertexArrayAttribEXT (GLuint vaobj, GLuint index);
    GLAPI void APIENTRY glDisableVertexArrayAttribEXT (GLuint vaobj, GLuint index);
    GLAPI void APIENTRY glGetVertexArrayIntegervEXT (GLuint vaobj, GLenum pname, GLint *param);
    GLAPI void APIENTRY glGetVertexArrayPointervEXT (GLuint vaobj, GLenum pname, void **param);
    GLAPI void APIENTRY glGetVertexArrayIntegeri_vEXT (GLuint vaobj, GLuint index, GLenum pname, GLint *param);
    GLAPI void APIENTRY glGetVertexArrayPointeri_vEXT (GLuint vaobj, GLuint index, GLenum pname, void **param);
    GLAPI void *APIENTRY glMapNamedBufferRangeEXT (GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
    GLAPI void APIENTRY glFlushMappedNamedBufferRangeEXT (GLuint buffer, GLintptr offset, GLsizeiptr length);
    GLAPI void APIENTRY glNamedBufferStorageEXT (GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
    GLAPI void APIENTRY glClearNamedBufferDataEXT (GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
    GLAPI void APIENTRY glClearNamedBufferSubDataEXT (GLuint buffer, GLenum internalformat, GLsizeiptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
    GLAPI void APIENTRY glNamedFramebufferParameteriEXT (GLuint framebuffer, GLenum pname, GLint param);
    GLAPI void APIENTRY glGetNamedFramebufferParameterivEXT (GLuint framebuffer, GLenum pname, GLint *params);
    GLAPI void APIENTRY glProgramUniform1dEXT (GLuint program, GLint location, GLdouble x);
    GLAPI void APIENTRY glProgramUniform2dEXT (GLuint program, GLint location, GLdouble x, GLdouble y);
    GLAPI void APIENTRY glProgramUniform3dEXT (GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z);
    GLAPI void APIENTRY glProgramUniform4dEXT (GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    GLAPI void APIENTRY glProgramUniform1dvEXT (GLuint program, GLint location, GLsizei count, const GLdouble *value);
    GLAPI void APIENTRY glProgramUniform2dvEXT (GLuint program, GLint location, GLsizei count, const GLdouble *value);
    GLAPI void APIENTRY glProgramUniform3dvEXT (GLuint program, GLint location, GLsizei count, const GLdouble *value);
    GLAPI void APIENTRY glProgramUniform4dvEXT (GLuint program, GLint location, GLsizei count, const GLdouble *value);
    GLAPI void APIENTRY glProgramUniformMatrix2dvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    GLAPI void APIENTRY glProgramUniformMatrix3dvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    GLAPI void APIENTRY glProgramUniformMatrix4dvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    GLAPI void APIENTRY glProgramUniformMatrix2x3dvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    GLAPI void APIENTRY glProgramUniformMatrix2x4dvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    GLAPI void APIENTRY glProgramUniformMatrix3x2dvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    GLAPI void APIENTRY glProgramUniformMatrix3x4dvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    GLAPI void APIENTRY glProgramUniformMatrix4x2dvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    GLAPI void APIENTRY glProgramUniformMatrix4x3dvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    GLAPI void APIENTRY glTextureBufferRangeEXT (GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
    GLAPI void APIENTRY glTextureStorage1DEXT (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
    GLAPI void APIENTRY glTextureStorage2DEXT (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
    GLAPI void APIENTRY glTextureStorage3DEXT (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
    GLAPI void APIENTRY glTextureStorage2DMultisampleEXT (GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
    GLAPI void APIENTRY glTextureStorage3DMultisampleEXT (GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
    GLAPI void APIENTRY glVertexArrayBindVertexBufferEXT (GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
    GLAPI void APIENTRY glVertexArrayVertexAttribFormatEXT (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
    GLAPI void APIENTRY glVertexArrayVertexAttribIFormatEXT (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
    GLAPI void APIENTRY glVertexArrayVertexAttribLFormatEXT (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
    GLAPI void APIENTRY glVertexArrayVertexAttribBindingEXT (GLuint vaobj, GLuint attribindex, GLuint bindingindex);
    GLAPI void APIENTRY glVertexArrayVertexBindingDivisorEXT (GLuint vaobj, GLuint bindingindex, GLuint divisor);
    GLAPI void APIENTRY glVertexArrayVertexAttribLOffsetEXT (GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
    GLAPI void APIENTRY glTexturePageCommitmentEXT (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
    GLAPI void APIENTRY glVertexArrayVertexAttribDivisorEXT (GLuint vaobj, GLuint index, GLuint divisor);
#endif
#endif /* GL_EXT_direct_state_access */
    
#ifndef GL_EXT_draw_instanced
#define GL_EXT_draw_instanced 1
    typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDEXTPROC) (GLenum mode, GLint start, GLsizei count, GLsizei primcount);
    typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDEXTPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glDrawArraysInstancedEXT (GLenum mode, GLint start, GLsizei count, GLsizei primcount);
    GLAPI void APIENTRY glDrawElementsInstancedEXT (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount);
#endif
#endif /* GL_EXT_draw_instanced */
    
#ifndef GL_EXT_polygon_offset_clamp
#define GL_EXT_polygon_offset_clamp 1
#define GL_POLYGON_OFFSET_CLAMP_EXT       0x8E1B
    typedef void (APIENTRYP PFNGLPOLYGONOFFSETCLAMPEXTPROC) (GLfloat factor, GLfloat units, GLfloat clamp);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glPolygonOffsetClampEXT (GLfloat factor, GLfloat units, GLfloat clamp);
#endif
#endif /* GL_EXT_polygon_offset_clamp */
    
#ifndef GL_EXT_post_depth_coverage
#define GL_EXT_post_depth_coverage 1
#endif /* GL_EXT_post_depth_coverage */
    
#ifndef GL_EXT_raster_multisample
#define GL_EXT_raster_multisample 1
#define GL_RASTER_MULTISAMPLE_EXT         0x9327
#define GL_RASTER_SAMPLES_EXT             0x9328
#define GL_MAX_RASTER_SAMPLES_EXT         0x9329
#define GL_RASTER_FIXED_SAMPLE_LOCATIONS_EXT 0x932A
#define GL_MULTISAMPLE_RASTERIZATION_ALLOWED_EXT 0x932B
#define GL_EFFECTIVE_RASTER_SAMPLES_EXT   0x932C
    typedef void (APIENTRYP PFNGLRASTERSAMPLESEXTPROC) (GLuint samples, GLboolean fixedsamplelocations);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glRasterSamplesEXT (GLuint samples, GLboolean fixedsamplelocations);
#endif
#endif /* GL_EXT_raster_multisample */
    
#ifndef GL_EXT_separate_shader_objects
#define GL_EXT_separate_shader_objects 1
#define GL_ACTIVE_PROGRAM_EXT             0x8B8D
    typedef void (APIENTRYP PFNGLUSESHADERPROGRAMEXTPROC) (GLenum type, GLuint program);
    typedef void (APIENTRYP PFNGLACTIVEPROGRAMEXTPROC) (GLuint program);
    typedef GLuint (APIENTRYP PFNGLCREATESHADERPROGRAMEXTPROC) (GLenum type, const GLchar *string);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glUseShaderProgramEXT (GLenum type, GLuint program);
    GLAPI void APIENTRY glActiveProgramEXT (GLuint program);
    GLAPI GLuint APIENTRY glCreateShaderProgramEXT (GLenum type, const GLchar *string);
#endif
#endif /* GL_EXT_separate_shader_objects */
    
#ifndef GL_EXT_shader_integer_mix
#define GL_EXT_shader_integer_mix 1
#endif /* GL_EXT_shader_integer_mix */
    
#ifndef GL_EXT_texture_compression_s3tc
#define GL_EXT_texture_compression_s3tc 1
#define GL_COMPRESSED_RGB_S3TC_DXT1_EXT   0x83F0
#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT  0x83F1
#define GL_COMPRESSED_RGBA_S3TC_DXT3_EXT  0x83F2
#define GL_COMPRESSED_RGBA_S3TC_DXT5_EXT  0x83F3
#endif /* GL_EXT_texture_compression_s3tc */
    
#ifndef GL_EXT_texture_filter_minmax
#define GL_EXT_texture_filter_minmax 1
#endif /* GL_EXT_texture_filter_minmax */
    
#ifndef GL_EXT_texture_sRGB_decode
#define GL_EXT_texture_sRGB_decode 1
#define GL_TEXTURE_SRGB_DECODE_EXT        0x8A48
#define GL_DECODE_EXT                     0x8A49
#define GL_SKIP_DECODE_EXT                0x8A4A
#endif /* GL_EXT_texture_sRGB_decode */
    
#ifndef GL_EXT_window_rectangles
#define GL_EXT_window_rectangles 1
#define GL_INCLUSIVE_EXT                  0x8F10
#define GL_EXCLUSIVE_EXT                  0x8F11
#define GL_WINDOW_RECTANGLE_EXT           0x8F12
#define GL_WINDOW_RECTANGLE_MODE_EXT      0x8F13
#define GL_MAX_WINDOW_RECTANGLES_EXT      0x8F14
#define GL_NUM_WINDOW_RECTANGLES_EXT      0x8F15
    typedef void (APIENTRYP PFNGLWINDOWRECTANGLESEXTPROC) (GLenum mode, GLsizei count, const GLint *box);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glWindowRectanglesEXT (GLenum mode, GLsizei count, const GLint *box);
#endif
#endif /* GL_EXT_window_rectangles */
    
#ifndef GL_INTEL_conservative_rasterization
#define GL_INTEL_conservative_rasterization 1
#define GL_CONSERVATIVE_RASTERIZATION_INTEL 0x83FE
#endif /* GL_INTEL_conservative_rasterization */
    
#ifndef GL_INTEL_framebuffer_CMAA
#define GL_INTEL_framebuffer_CMAA 1
    typedef void (APIENTRYP PFNGLAPPLYFRAMEBUFFERATTACHMENTCMAAINTELPROC) (void);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glApplyFramebufferAttachmentCMAAINTEL (void);
#endif
#endif /* GL_INTEL_framebuffer_CMAA */
    
#ifndef GL_INTEL_performance_query
#define GL_INTEL_performance_query 1
#define GL_PERFQUERY_SINGLE_CONTEXT_INTEL 0x00000000
#define GL_PERFQUERY_GLOBAL_CONTEXT_INTEL 0x00000001
#define GL_PERFQUERY_WAIT_INTEL           0x83FB
#define GL_PERFQUERY_FLUSH_INTEL          0x83FA
#define GL_PERFQUERY_DONOT_FLUSH_INTEL    0x83F9
#define GL_PERFQUERY_COUNTER_EVENT_INTEL  0x94F0
#define GL_PERFQUERY_COUNTER_DURATION_NORM_INTEL 0x94F1
#define GL_PERFQUERY_COUNTER_DURATION_RAW_INTEL 0x94F2
#define GL_PERFQUERY_COUNTER_THROUGHPUT_INTEL 0x94F3
#define GL_PERFQUERY_COUNTER_RAW_INTEL    0x94F4
#define GL_PERFQUERY_COUNTER_TIMESTAMP_INTEL 0x94F5
#define GL_PERFQUERY_COUNTER_DATA_UINT32_INTEL 0x94F8
#define GL_PERFQUERY_COUNTER_DATA_UINT64_INTEL 0x94F9
#define GL_PERFQUERY_COUNTER_DATA_FLOAT_INTEL 0x94FA
#define GL_PERFQUERY_COUNTER_DATA_DOUBLE_INTEL 0x94FB
#define GL_PERFQUERY_COUNTER_DATA_BOOL32_INTEL 0x94FC
#define GL_PERFQUERY_QUERY_NAME_LENGTH_MAX_INTEL 0x94FD
#define GL_PERFQUERY_COUNTER_NAME_LENGTH_MAX_INTEL 0x94FE
#define GL_PERFQUERY_COUNTER_DESC_LENGTH_MAX_INTEL 0x94FF
#define GL_PERFQUERY_GPA_EXTENDED_COUNTERS_INTEL 0x9500
    typedef void (APIENTRYP PFNGLBEGINPERFQUERYINTELPROC) (GLuint queryHandle);
    typedef void (APIENTRYP PFNGLCREATEPERFQUERYINTELPROC) (GLuint queryId, GLuint *queryHandle);
    typedef void (APIENTRYP PFNGLDELETEPERFQUERYINTELPROC) (GLuint queryHandle);
    typedef void (APIENTRYP PFNGLENDPERFQUERYINTELPROC) (GLuint queryHandle);
    typedef void (APIENTRYP PFNGLGETFIRSTPERFQUERYIDINTELPROC) (GLuint *queryId);
    typedef void (APIENTRYP PFNGLGETNEXTPERFQUERYIDINTELPROC) (GLuint queryId, GLuint *nextQueryId);
    typedef void (APIENTRYP PFNGLGETPERFCOUNTERINFOINTELPROC) (GLuint queryId, GLuint counterId, GLuint counterNameLength, GLchar *counterName, GLuint counterDescLength, GLchar *counterDesc, GLuint *counterOffset, GLuint *counterDataSize, GLuint *counterTypeEnum, GLuint *counterDataTypeEnum, GLuint64 *rawCounterMaxValue);
    typedef void (APIENTRYP PFNGLGETPERFQUERYDATAINTELPROC) (GLuint queryHandle, GLuint flags, GLsizei dataSize, GLvoid *data, GLuint *bytesWritten);
    typedef void (APIENTRYP PFNGLGETPERFQUERYIDBYNAMEINTELPROC) (GLchar *queryName, GLuint *queryId);
    typedef void (APIENTRYP PFNGLGETPERFQUERYINFOINTELPROC) (GLuint queryId, GLuint queryNameLength, GLchar *queryName, GLuint *dataSize, GLuint *noCounters, GLuint *noInstances, GLuint *capsMask);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glBeginPerfQueryINTEL (GLuint queryHandle);
    GLAPI void APIENTRY glCreatePerfQueryINTEL (GLuint queryId, GLuint *queryHandle);
    GLAPI void APIENTRY glDeletePerfQueryINTEL (GLuint queryHandle);
    GLAPI void APIENTRY glEndPerfQueryINTEL (GLuint queryHandle);
    GLAPI void APIENTRY glGetFirstPerfQueryIdINTEL (GLuint *queryId);
    GLAPI void APIENTRY glGetNextPerfQueryIdINTEL (GLuint queryId, GLuint *nextQueryId);
    GLAPI void APIENTRY glGetPerfCounterInfoINTEL (GLuint queryId, GLuint counterId, GLuint counterNameLength, GLchar *counterName, GLuint counterDescLength, GLchar *counterDesc, GLuint *counterOffset, GLuint *counterDataSize, GLuint *counterTypeEnum, GLuint *counterDataTypeEnum, GLuint64 *rawCounterMaxValue);
    GLAPI void APIENTRY glGetPerfQueryDataINTEL (GLuint queryHandle, GLuint flags, GLsizei dataSize, GLvoid *data, GLuint *bytesWritten);
    GLAPI void APIENTRY glGetPerfQueryIdByNameINTEL (GLchar *queryName, GLuint *queryId);
    GLAPI void APIENTRY glGetPerfQueryInfoINTEL (GLuint queryId, GLuint queryNameLength, GLchar *queryName, GLuint *dataSize, GLuint *noCounters, GLuint *noInstances, GLuint *capsMask);
#endif
#endif /* GL_INTEL_performance_query */
    
#ifndef GL_NV_bindless_texture
#define GL_NV_bindless_texture 1
    typedef GLuint64 (APIENTRYP PFNGLGETTEXTUREHANDLENVPROC) (GLuint texture);
    typedef GLuint64 (APIENTRYP PFNGLGETTEXTURESAMPLERHANDLENVPROC) (GLuint texture, GLuint sampler);
    typedef void (APIENTRYP PFNGLMAKETEXTUREHANDLERESIDENTNVPROC) (GLuint64 handle);
    typedef void (APIENTRYP PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC) (GLuint64 handle);
    typedef GLuint64 (APIENTRYP PFNGLGETIMAGEHANDLENVPROC) (GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
    typedef void (APIENTRYP PFNGLMAKEIMAGEHANDLERESIDENTNVPROC) (GLuint64 handle, GLenum access);
    typedef void (APIENTRYP PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC) (GLuint64 handle);
    typedef void (APIENTRYP PFNGLUNIFORMHANDLEUI64NVPROC) (GLint location, GLuint64 value);
    typedef void (APIENTRYP PFNGLUNIFORMHANDLEUI64VNVPROC) (GLint location, GLsizei count, const GLuint64 *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC) (GLuint program, GLint location, GLuint64 value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC) (GLuint program, GLint location, GLsizei count, const GLuint64 *values);
    typedef GLboolean (APIENTRYP PFNGLISTEXTUREHANDLERESIDENTNVPROC) (GLuint64 handle);
    typedef GLboolean (APIENTRYP PFNGLISIMAGEHANDLERESIDENTNVPROC) (GLuint64 handle);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI GLuint64 APIENTRY glGetTextureHandleNV (GLuint texture);
    GLAPI GLuint64 APIENTRY glGetTextureSamplerHandleNV (GLuint texture, GLuint sampler);
    GLAPI void APIENTRY glMakeTextureHandleResidentNV (GLuint64 handle);
    GLAPI void APIENTRY glMakeTextureHandleNonResidentNV (GLuint64 handle);
    GLAPI GLuint64 APIENTRY glGetImageHandleNV (GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
    GLAPI void APIENTRY glMakeImageHandleResidentNV (GLuint64 handle, GLenum access);
    GLAPI void APIENTRY glMakeImageHandleNonResidentNV (GLuint64 handle);
    GLAPI void APIENTRY glUniformHandleui64NV (GLint location, GLuint64 value);
    GLAPI void APIENTRY glUniformHandleui64vNV (GLint location, GLsizei count, const GLuint64 *value);
    GLAPI void APIENTRY glProgramUniformHandleui64NV (GLuint program, GLint location, GLuint64 value);
    GLAPI void APIENTRY glProgramUniformHandleui64vNV (GLuint program, GLint location, GLsizei count, const GLuint64 *values);
    GLAPI GLboolean APIENTRY glIsTextureHandleResidentNV (GLuint64 handle);
    GLAPI GLboolean APIENTRY glIsImageHandleResidentNV (GLuint64 handle);
#endif
#endif /* GL_NV_bindless_texture */
    
#ifndef GL_NV_blend_equation_advanced
#define GL_NV_blend_equation_advanced 1
#define GL_BLEND_OVERLAP_NV               0x9281
#define GL_BLEND_PREMULTIPLIED_SRC_NV     0x9280
#define GL_BLUE_NV                        0x1905
#define GL_COLORBURN_NV                   0x929A
#define GL_COLORDODGE_NV                  0x9299
#define GL_CONJOINT_NV                    0x9284
#define GL_CONTRAST_NV                    0x92A1
#define GL_DARKEN_NV                      0x9297
#define GL_DIFFERENCE_NV                  0x929E
#define GL_DISJOINT_NV                    0x9283
#define GL_DST_ATOP_NV                    0x928F
#define GL_DST_IN_NV                      0x928B
#define GL_DST_NV                         0x9287
#define GL_DST_OUT_NV                     0x928D
#define GL_DST_OVER_NV                    0x9289
#define GL_EXCLUSION_NV                   0x92A0
#define GL_GREEN_NV                       0x1904
#define GL_HARDLIGHT_NV                   0x929B
#define GL_HARDMIX_NV                     0x92A9
#define GL_HSL_COLOR_NV                   0x92AF
#define GL_HSL_HUE_NV                     0x92AD
#define GL_HSL_LUMINOSITY_NV              0x92B0
#define GL_HSL_SATURATION_NV              0x92AE
#define GL_INVERT_OVG_NV                  0x92B4
#define GL_INVERT_RGB_NV                  0x92A3
#define GL_LIGHTEN_NV                     0x9298
#define GL_LINEARBURN_NV                  0x92A5
#define GL_LINEARDODGE_NV                 0x92A4
#define GL_LINEARLIGHT_NV                 0x92A7
#define GL_MINUS_CLAMPED_NV               0x92B3
#define GL_MINUS_NV                       0x929F
#define GL_MULTIPLY_NV                    0x9294
#define GL_OVERLAY_NV                     0x9296
#define GL_PINLIGHT_NV                    0x92A8
#define GL_PLUS_CLAMPED_ALPHA_NV          0x92B2
#define GL_PLUS_CLAMPED_NV                0x92B1
#define GL_PLUS_DARKER_NV                 0x9292
#define GL_PLUS_NV                        0x9291
#define GL_RED_NV                         0x1903
#define GL_SCREEN_NV                      0x9295
#define GL_SOFTLIGHT_NV                   0x929C
#define GL_SRC_ATOP_NV                    0x928E
#define GL_SRC_IN_NV                      0x928A
#define GL_SRC_NV                         0x9286
#define GL_SRC_OUT_NV                     0x928C
#define GL_SRC_OVER_NV                    0x9288
#define GL_UNCORRELATED_NV                0x9282
#define GL_VIVIDLIGHT_NV                  0x92A6
#define GL_XOR_NV                         0x1506
    typedef void (APIENTRYP PFNGLBLENDPARAMETERINVPROC) (GLenum pname, GLint value);
    typedef void (APIENTRYP PFNGLBLENDBARRIERNVPROC) (void);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glBlendParameteriNV (GLenum pname, GLint value);
    GLAPI void APIENTRY glBlendBarrierNV (void);
#endif
#endif /* GL_NV_blend_equation_advanced */
    
#ifndef GL_NV_blend_equation_advanced_coherent
#define GL_NV_blend_equation_advanced_coherent 1
#define GL_BLEND_ADVANCED_COHERENT_NV     0x9285
#endif /* GL_NV_blend_equation_advanced_coherent */
    
#ifndef GL_NV_conditional_render
#define GL_NV_conditional_render 1
#define GL_QUERY_WAIT_NV                  0x8E13
#define GL_QUERY_NO_WAIT_NV               0x8E14
#define GL_QUERY_BY_REGION_WAIT_NV        0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT_NV     0x8E16
    typedef void (APIENTRYP PFNGLBEGINCONDITIONALRENDERNVPROC) (GLuint id, GLenum mode);
    typedef void (APIENTRYP PFNGLENDCONDITIONALRENDERNVPROC) (void);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glBeginConditionalRenderNV (GLuint id, GLenum mode);
    GLAPI void APIENTRY glEndConditionalRenderNV (void);
#endif
#endif /* GL_NV_conditional_render */
    
#ifndef GL_NV_conservative_raster
#define GL_NV_conservative_raster 1
#define GL_CONSERVATIVE_RASTERIZATION_NV  0x9346
#define GL_SUBPIXEL_PRECISION_BIAS_X_BITS_NV 0x9347
#define GL_SUBPIXEL_PRECISION_BIAS_Y_BITS_NV 0x9348
#define GL_MAX_SUBPIXEL_PRECISION_BIAS_BITS_NV 0x9349
    typedef void (APIENTRYP PFNGLSUBPIXELPRECISIONBIASNVPROC) (GLuint xbits, GLuint ybits);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glSubpixelPrecisionBiasNV (GLuint xbits, GLuint ybits);
#endif
#endif /* GL_NV_conservative_raster */
    
#ifndef GL_NV_conservative_raster_pre_snap_triangles
#define GL_NV_conservative_raster_pre_snap_triangles 1
#define GL_CONSERVATIVE_RASTER_MODE_NV    0x954D
#define GL_CONSERVATIVE_RASTER_MODE_POST_SNAP_NV 0x954E
#define GL_CONSERVATIVE_RASTER_MODE_PRE_SNAP_TRIANGLES_NV 0x954F
    typedef void (APIENTRYP PFNGLCONSERVATIVERASTERPARAMETERINVPROC) (GLenum pname, GLint param);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glConservativeRasterParameteriNV (GLenum pname, GLint param);
#endif
#endif /* GL_NV_conservative_raster_pre_snap_triangles */
    
#ifndef GL_NV_draw_vulkan_image
#define GL_NV_draw_vulkan_image 1
    typedef void (APIENTRY  *GLVULKANPROCNV)(void);
    typedef void (APIENTRYP PFNGLDRAWVKIMAGENVPROC) (GLuint64 vkImage, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1);
    typedef GLVULKANPROCNV (APIENTRYP PFNGLGETVKPROCADDRNVPROC) (const GLchar *name);
    typedef void (APIENTRYP PFNGLWAITVKSEMAPHORENVPROC) (GLuint64 vkSemaphore);
    typedef void (APIENTRYP PFNGLSIGNALVKSEMAPHORENVPROC) (GLuint64 vkSemaphore);
    typedef void (APIENTRYP PFNGLSIGNALVKFENCENVPROC) (GLuint64 vkFence);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glDrawVkImageNV (GLuint64 vkImage, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1);
    GLAPI GLVULKANPROCNV APIENTRY glGetVkProcAddrNV (const GLchar *name);
    GLAPI void APIENTRY glWaitVkSemaphoreNV (GLuint64 vkSemaphore);
    GLAPI void APIENTRY glSignalVkSemaphoreNV (GLuint64 vkSemaphore);
    GLAPI void APIENTRY glSignalVkFenceNV (GLuint64 vkFence);
#endif
#endif /* GL_NV_draw_vulkan_image */
    
#ifndef GL_NV_fill_rectangle
#define GL_NV_fill_rectangle 1
#define GL_FILL_RECTANGLE_NV              0x933C
#endif /* GL_NV_fill_rectangle */
    
#ifndef GL_NV_fragment_coverage_to_color
#define GL_NV_fragment_coverage_to_color 1
#define GL_FRAGMENT_COVERAGE_TO_COLOR_NV  0x92DD
#define GL_FRAGMENT_COVERAGE_COLOR_NV     0x92DE
    typedef void (APIENTRYP PFNGLFRAGMENTCOVERAGECOLORNVPROC) (GLuint color);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glFragmentCoverageColorNV (GLuint color);
#endif
#endif /* GL_NV_fragment_coverage_to_color */
    
#ifndef GL_NV_fragment_shader_interlock
#define GL_NV_fragment_shader_interlock 1
#endif /* GL_NV_fragment_shader_interlock */
    
#ifndef GL_NV_framebuffer_mixed_samples
#define GL_NV_framebuffer_mixed_samples 1
#define GL_COVERAGE_MODULATION_TABLE_NV   0x9331
#define GL_COLOR_SAMPLES_NV               0x8E20
#define GL_DEPTH_SAMPLES_NV               0x932D
#define GL_STENCIL_SAMPLES_NV             0x932E
#define GL_MIXED_DEPTH_SAMPLES_SUPPORTED_NV 0x932F
#define GL_MIXED_STENCIL_SAMPLES_SUPPORTED_NV 0x9330
#define GL_COVERAGE_MODULATION_NV         0x9332
#define GL_COVERAGE_MODULATION_TABLE_SIZE_NV 0x9333
    typedef void (APIENTRYP PFNGLCOVERAGEMODULATIONTABLENVPROC) (GLsizei n, const GLfloat *v);
    typedef void (APIENTRYP PFNGLGETCOVERAGEMODULATIONTABLENVPROC) (GLsizei bufsize, GLfloat *v);
    typedef void (APIENTRYP PFNGLCOVERAGEMODULATIONNVPROC) (GLenum components);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glCoverageModulationTableNV (GLsizei n, const GLfloat *v);
    GLAPI void APIENTRY glGetCoverageModulationTableNV (GLsizei bufsize, GLfloat *v);
    GLAPI void APIENTRY glCoverageModulationNV (GLenum components);
#endif
#endif /* GL_NV_framebuffer_mixed_samples */
    
#ifndef GL_NV_geometry_shader_passthrough
#define GL_NV_geometry_shader_passthrough 1
#endif /* GL_NV_geometry_shader_passthrough */
    
#ifndef GL_NV_gpu_shader5
#define GL_NV_gpu_shader5 1
    typedef int64_t GLint64EXT;
#define GL_INT64_NV                       0x140E
#define GL_UNSIGNED_INT64_NV              0x140F
#define GL_INT8_NV                        0x8FE0
#define GL_INT8_VEC2_NV                   0x8FE1
#define GL_INT8_VEC3_NV                   0x8FE2
#define GL_INT8_VEC4_NV                   0x8FE3
#define GL_INT16_NV                       0x8FE4
#define GL_INT16_VEC2_NV                  0x8FE5
#define GL_INT16_VEC3_NV                  0x8FE6
#define GL_INT16_VEC4_NV                  0x8FE7
#define GL_INT64_VEC2_NV                  0x8FE9
#define GL_INT64_VEC3_NV                  0x8FEA
#define GL_INT64_VEC4_NV                  0x8FEB
#define GL_UNSIGNED_INT8_NV               0x8FEC
#define GL_UNSIGNED_INT8_VEC2_NV          0x8FED
#define GL_UNSIGNED_INT8_VEC3_NV          0x8FEE
#define GL_UNSIGNED_INT8_VEC4_NV          0x8FEF
#define GL_UNSIGNED_INT16_NV              0x8FF0
#define GL_UNSIGNED_INT16_VEC2_NV         0x8FF1
#define GL_UNSIGNED_INT16_VEC3_NV         0x8FF2
#define GL_UNSIGNED_INT16_VEC4_NV         0x8FF3
#define GL_UNSIGNED_INT64_VEC2_NV         0x8FF5
#define GL_UNSIGNED_INT64_VEC3_NV         0x8FF6
#define GL_UNSIGNED_INT64_VEC4_NV         0x8FF7
#define GL_FLOAT16_NV                     0x8FF8
#define GL_FLOAT16_VEC2_NV                0x8FF9
#define GL_FLOAT16_VEC3_NV                0x8FFA
#define GL_FLOAT16_VEC4_NV                0x8FFB
    typedef void (APIENTRYP PFNGLUNIFORM1I64NVPROC) (GLint location, GLint64EXT x);
    typedef void (APIENTRYP PFNGLUNIFORM2I64NVPROC) (GLint location, GLint64EXT x, GLint64EXT y);
    typedef void (APIENTRYP PFNGLUNIFORM3I64NVPROC) (GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
    typedef void (APIENTRYP PFNGLUNIFORM4I64NVPROC) (GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
    typedef void (APIENTRYP PFNGLUNIFORM1I64VNVPROC) (GLint location, GLsizei count, const GLint64EXT *value);
    typedef void (APIENTRYP PFNGLUNIFORM2I64VNVPROC) (GLint location, GLsizei count, const GLint64EXT *value);
    typedef void (APIENTRYP PFNGLUNIFORM3I64VNVPROC) (GLint location, GLsizei count, const GLint64EXT *value);
    typedef void (APIENTRYP PFNGLUNIFORM4I64VNVPROC) (GLint location, GLsizei count, const GLint64EXT *value);
    typedef void (APIENTRYP PFNGLUNIFORM1UI64NVPROC) (GLint location, GLuint64EXT x);
    typedef void (APIENTRYP PFNGLUNIFORM2UI64NVPROC) (GLint location, GLuint64EXT x, GLuint64EXT y);
    typedef void (APIENTRYP PFNGLUNIFORM3UI64NVPROC) (GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
    typedef void (APIENTRYP PFNGLUNIFORM4UI64NVPROC) (GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
    typedef void (APIENTRYP PFNGLUNIFORM1UI64VNVPROC) (GLint location, GLsizei count, const GLuint64EXT *value);
    typedef void (APIENTRYP PFNGLUNIFORM2UI64VNVPROC) (GLint location, GLsizei count, const GLuint64EXT *value);
    typedef void (APIENTRYP PFNGLUNIFORM3UI64VNVPROC) (GLint location, GLsizei count, const GLuint64EXT *value);
    typedef void (APIENTRYP PFNGLUNIFORM4UI64VNVPROC) (GLint location, GLsizei count, const GLuint64EXT *value);
    typedef void (APIENTRYP PFNGLGETUNIFORMI64VNVPROC) (GLuint program, GLint location, GLint64EXT *params);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1I64NVPROC) (GLuint program, GLint location, GLint64EXT x);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2I64NVPROC) (GLuint program, GLint location, GLint64EXT x, GLint64EXT y);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3I64NVPROC) (GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4I64NVPROC) (GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1I64VNVPROC) (GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2I64VNVPROC) (GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3I64VNVPROC) (GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4I64VNVPROC) (GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UI64NVPROC) (GLuint program, GLint location, GLuint64EXT x);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UI64NVPROC) (GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UI64NVPROC) (GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UI64NVPROC) (GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UI64VNVPROC) (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UI64VNVPROC) (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UI64VNVPROC) (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
    typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UI64VNVPROC) (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glUniform1i64NV (GLint location, GLint64EXT x);
    GLAPI void APIENTRY glUniform2i64NV (GLint location, GLint64EXT x, GLint64EXT y);
    GLAPI void APIENTRY glUniform3i64NV (GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
    GLAPI void APIENTRY glUniform4i64NV (GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
    GLAPI void APIENTRY glUniform1i64vNV (GLint location, GLsizei count, const GLint64EXT *value);
    GLAPI void APIENTRY glUniform2i64vNV (GLint location, GLsizei count, const GLint64EXT *value);
    GLAPI void APIENTRY glUniform3i64vNV (GLint location, GLsizei count, const GLint64EXT *value);
    GLAPI void APIENTRY glUniform4i64vNV (GLint location, GLsizei count, const GLint64EXT *value);
    GLAPI void APIENTRY glUniform1ui64NV (GLint location, GLuint64EXT x);
    GLAPI void APIENTRY glUniform2ui64NV (GLint location, GLuint64EXT x, GLuint64EXT y);
    GLAPI void APIENTRY glUniform3ui64NV (GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
    GLAPI void APIENTRY glUniform4ui64NV (GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
    GLAPI void APIENTRY glUniform1ui64vNV (GLint location, GLsizei count, const GLuint64EXT *value);
    GLAPI void APIENTRY glUniform2ui64vNV (GLint location, GLsizei count, const GLuint64EXT *value);
    GLAPI void APIENTRY glUniform3ui64vNV (GLint location, GLsizei count, const GLuint64EXT *value);
    GLAPI void APIENTRY glUniform4ui64vNV (GLint location, GLsizei count, const GLuint64EXT *value);
    GLAPI void APIENTRY glGetUniformi64vNV (GLuint program, GLint location, GLint64EXT *params);
    GLAPI void APIENTRY glProgramUniform1i64NV (GLuint program, GLint location, GLint64EXT x);
    GLAPI void APIENTRY glProgramUniform2i64NV (GLuint program, GLint location, GLint64EXT x, GLint64EXT y);
    GLAPI void APIENTRY glProgramUniform3i64NV (GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
    GLAPI void APIENTRY glProgramUniform4i64NV (GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
    GLAPI void APIENTRY glProgramUniform1i64vNV (GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
    GLAPI void APIENTRY glProgramUniform2i64vNV (GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
    GLAPI void APIENTRY glProgramUniform3i64vNV (GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
    GLAPI void APIENTRY glProgramUniform4i64vNV (GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
    GLAPI void APIENTRY glProgramUniform1ui64NV (GLuint program, GLint location, GLuint64EXT x);
    GLAPI void APIENTRY glProgramUniform2ui64NV (GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y);
    GLAPI void APIENTRY glProgramUniform3ui64NV (GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
    GLAPI void APIENTRY glProgramUniform4ui64NV (GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
    GLAPI void APIENTRY glProgramUniform1ui64vNV (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
    GLAPI void APIENTRY glProgramUniform2ui64vNV (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
    GLAPI void APIENTRY glProgramUniform3ui64vNV (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
    GLAPI void APIENTRY glProgramUniform4ui64vNV (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
#endif
#endif /* GL_NV_gpu_shader5 */
    
#ifndef GL_NV_internalformat_sample_query
#define GL_NV_internalformat_sample_query 1
#define GL_MULTISAMPLES_NV                0x9371
#define GL_SUPERSAMPLE_SCALE_X_NV         0x9372
#define GL_SUPERSAMPLE_SCALE_Y_NV         0x9373
#define GL_CONFORMANT_NV                  0x9374
    typedef void (APIENTRYP PFNGLGETINTERNALFORMATSAMPLEIVNVPROC) (GLenum target, GLenum internalformat, GLsizei samples, GLenum pname, GLsizei bufSize, GLint *params);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glGetInternalformatSampleivNV (GLenum target, GLenum internalformat, GLsizei samples, GLenum pname, GLsizei bufSize, GLint *params);
#endif
#endif /* GL_NV_internalformat_sample_query */
    
#ifndef GL_NV_path_rendering
#define GL_NV_path_rendering 1
#define GL_PATH_FORMAT_SVG_NV             0x9070
#define GL_PATH_FORMAT_PS_NV              0x9071
#define GL_STANDARD_FONT_NAME_NV          0x9072
#define GL_SYSTEM_FONT_NAME_NV            0x9073
#define GL_FILE_NAME_NV                   0x9074
#define GL_PATH_STROKE_WIDTH_NV           0x9075
#define GL_PATH_END_CAPS_NV               0x9076
#define GL_PATH_INITIAL_END_CAP_NV        0x9077
#define GL_PATH_TERMINAL_END_CAP_NV       0x9078
#define GL_PATH_JOIN_STYLE_NV             0x9079
#define GL_PATH_MITER_LIMIT_NV            0x907A
#define GL_PATH_DASH_CAPS_NV              0x907B
#define GL_PATH_INITIAL_DASH_CAP_NV       0x907C
#define GL_PATH_TERMINAL_DASH_CAP_NV      0x907D
#define GL_PATH_DASH_OFFSET_NV            0x907E
#define GL_PATH_CLIENT_LENGTH_NV          0x907F
#define GL_PATH_FILL_MODE_NV              0x9080
#define GL_PATH_FILL_MASK_NV              0x9081
#define GL_PATH_FILL_COVER_MODE_NV        0x9082
#define GL_PATH_STROKE_COVER_MODE_NV      0x9083
#define GL_PATH_STROKE_MASK_NV            0x9084
#define GL_COUNT_UP_NV                    0x9088
#define GL_COUNT_DOWN_NV                  0x9089
#define GL_PATH_OBJECT_BOUNDING_BOX_NV    0x908A
#define GL_CONVEX_HULL_NV                 0x908B
#define GL_BOUNDING_BOX_NV                0x908D
#define GL_TRANSLATE_X_NV                 0x908E
#define GL_TRANSLATE_Y_NV                 0x908F
#define GL_TRANSLATE_2D_NV                0x9090
#define GL_TRANSLATE_3D_NV                0x9091
#define GL_AFFINE_2D_NV                   0x9092
#define GL_AFFINE_3D_NV                   0x9094
#define GL_TRANSPOSE_AFFINE_2D_NV         0x9096
#define GL_TRANSPOSE_AFFINE_3D_NV         0x9098
#define GL_UTF8_NV                        0x909A
#define GL_UTF16_NV                       0x909B
#define GL_BOUNDING_BOX_OF_BOUNDING_BOXES_NV 0x909C
#define GL_PATH_COMMAND_COUNT_NV          0x909D
#define GL_PATH_COORD_COUNT_NV            0x909E
#define GL_PATH_DASH_ARRAY_COUNT_NV       0x909F
#define GL_PATH_COMPUTED_LENGTH_NV        0x90A0
#define GL_PATH_FILL_BOUNDING_BOX_NV      0x90A1
#define GL_PATH_STROKE_BOUNDING_BOX_NV    0x90A2
#define GL_SQUARE_NV                      0x90A3
#define GL_ROUND_NV                       0x90A4
#define GL_TRIANGULAR_NV                  0x90A5
#define GL_BEVEL_NV                       0x90A6
#define GL_MITER_REVERT_NV                0x90A7
#define GL_MITER_TRUNCATE_NV              0x90A8
#define GL_SKIP_MISSING_GLYPH_NV          0x90A9
#define GL_USE_MISSING_GLYPH_NV           0x90AA
#define GL_PATH_ERROR_POSITION_NV         0x90AB
#define GL_ACCUM_ADJACENT_PAIRS_NV        0x90AD
#define GL_ADJACENT_PAIRS_NV              0x90AE
#define GL_FIRST_TO_REST_NV               0x90AF
#define GL_PATH_GEN_MODE_NV               0x90B0
#define GL_PATH_GEN_COEFF_NV              0x90B1
#define GL_PATH_GEN_COMPONENTS_NV         0x90B3
#define GL_PATH_STENCIL_FUNC_NV           0x90B7
#define GL_PATH_STENCIL_REF_NV            0x90B8
#define GL_PATH_STENCIL_VALUE_MASK_NV     0x90B9
#define GL_PATH_STENCIL_DEPTH_OFFSET_FACTOR_NV 0x90BD
#define GL_PATH_STENCIL_DEPTH_OFFSET_UNITS_NV 0x90BE
#define GL_PATH_COVER_DEPTH_FUNC_NV       0x90BF
#define GL_PATH_DASH_OFFSET_RESET_NV      0x90B4
#define GL_MOVE_TO_RESETS_NV              0x90B5
#define GL_MOVE_TO_CONTINUES_NV           0x90B6
#define GL_CLOSE_PATH_NV                  0x00
#define GL_MOVE_TO_NV                     0x02
#define GL_RELATIVE_MOVE_TO_NV            0x03
#define GL_LINE_TO_NV                     0x04
#define GL_RELATIVE_LINE_TO_NV            0x05
#define GL_HORIZONTAL_LINE_TO_NV          0x06
#define GL_RELATIVE_HORIZONTAL_LINE_TO_NV 0x07
#define GL_VERTICAL_LINE_TO_NV            0x08
#define GL_RELATIVE_VERTICAL_LINE_TO_NV   0x09
#define GL_QUADRATIC_CURVE_TO_NV          0x0A
#define GL_RELATIVE_QUADRATIC_CURVE_TO_NV 0x0B
#define GL_CUBIC_CURVE_TO_NV              0x0C
#define GL_RELATIVE_CUBIC_CURVE_TO_NV     0x0D
#define GL_SMOOTH_QUADRATIC_CURVE_TO_NV   0x0E
#define GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV 0x0F
#define GL_SMOOTH_CUBIC_CURVE_TO_NV       0x10
#define GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV 0x11
#define GL_SMALL_CCW_ARC_TO_NV            0x12
#define GL_RELATIVE_SMALL_CCW_ARC_TO_NV   0x13
#define GL_SMALL_CW_ARC_TO_NV             0x14
#define GL_RELATIVE_SMALL_CW_ARC_TO_NV    0x15
#define GL_LARGE_CCW_ARC_TO_NV            0x16
#define GL_RELATIVE_LARGE_CCW_ARC_TO_NV   0x17
#define GL_LARGE_CW_ARC_TO_NV             0x18
#define GL_RELATIVE_LARGE_CW_ARC_TO_NV    0x19
#define GL_RESTART_PATH_NV                0xF0
#define GL_DUP_FIRST_CUBIC_CURVE_TO_NV    0xF2
#define GL_DUP_LAST_CUBIC_CURVE_TO_NV     0xF4
#define GL_RECT_NV                        0xF6
#define GL_CIRCULAR_CCW_ARC_TO_NV         0xF8
#define GL_CIRCULAR_CW_ARC_TO_NV          0xFA
#define GL_CIRCULAR_TANGENT_ARC_TO_NV     0xFC
#define GL_ARC_TO_NV                      0xFE
#define GL_RELATIVE_ARC_TO_NV             0xFF
#define GL_BOLD_BIT_NV                    0x01
#define GL_ITALIC_BIT_NV                  0x02
#define GL_GLYPH_WIDTH_BIT_NV             0x01
#define GL_GLYPH_HEIGHT_BIT_NV            0x02
#define GL_GLYPH_HORIZONTAL_BEARING_X_BIT_NV 0x04
#define GL_GLYPH_HORIZONTAL_BEARING_Y_BIT_NV 0x08
#define GL_GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV 0x10
#define GL_GLYPH_VERTICAL_BEARING_X_BIT_NV 0x20
#define GL_GLYPH_VERTICAL_BEARING_Y_BIT_NV 0x40
#define GL_GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV 0x80
#define GL_GLYPH_HAS_KERNING_BIT_NV       0x100
#define GL_FONT_X_MIN_BOUNDS_BIT_NV       0x00010000
#define GL_FONT_Y_MIN_BOUNDS_BIT_NV       0x00020000
#define GL_FONT_X_MAX_BOUNDS_BIT_NV       0x00040000
#define GL_FONT_Y_MAX_BOUNDS_BIT_NV       0x00080000
#define GL_FONT_UNITS_PER_EM_BIT_NV       0x00100000
#define GL_FONT_ASCENDER_BIT_NV           0x00200000
#define GL_FONT_DESCENDER_BIT_NV          0x00400000
#define GL_FONT_HEIGHT_BIT_NV             0x00800000
#define GL_FONT_MAX_ADVANCE_WIDTH_BIT_NV  0x01000000
#define GL_FONT_MAX_ADVANCE_HEIGHT_BIT_NV 0x02000000
#define GL_FONT_UNDERLINE_POSITION_BIT_NV 0x04000000
#define GL_FONT_UNDERLINE_THICKNESS_BIT_NV 0x08000000
#define GL_FONT_HAS_KERNING_BIT_NV        0x10000000
#define GL_ROUNDED_RECT_NV                0xE8
#define GL_RELATIVE_ROUNDED_RECT_NV       0xE9
#define GL_ROUNDED_RECT2_NV               0xEA
#define GL_RELATIVE_ROUNDED_RECT2_NV      0xEB
#define GL_ROUNDED_RECT4_NV               0xEC
#define GL_RELATIVE_ROUNDED_RECT4_NV      0xED
#define GL_ROUNDED_RECT8_NV               0xEE
#define GL_RELATIVE_ROUNDED_RECT8_NV      0xEF
#define GL_RELATIVE_RECT_NV               0xF7
#define GL_FONT_GLYPHS_AVAILABLE_NV       0x9368
#define GL_FONT_TARGET_UNAVAILABLE_NV     0x9369
#define GL_FONT_UNAVAILABLE_NV            0x936A
#define GL_FONT_UNINTELLIGIBLE_NV         0x936B
#define GL_CONIC_CURVE_TO_NV              0x1A
#define GL_RELATIVE_CONIC_CURVE_TO_NV     0x1B
#define GL_FONT_NUM_GLYPH_INDICES_BIT_NV  0x20000000
#define GL_STANDARD_FONT_FORMAT_NV        0x936C
#define GL_PATH_PROJECTION_NV             0x1701
#define GL_PATH_MODELVIEW_NV              0x1700
#define GL_PATH_MODELVIEW_STACK_DEPTH_NV  0x0BA3
#define GL_PATH_MODELVIEW_MATRIX_NV       0x0BA6
#define GL_PATH_MAX_MODELVIEW_STACK_DEPTH_NV 0x0D36
#define GL_PATH_TRANSPOSE_MODELVIEW_MATRIX_NV 0x84E3
#define GL_PATH_PROJECTION_STACK_DEPTH_NV 0x0BA4
#define GL_PATH_PROJECTION_MATRIX_NV      0x0BA7
#define GL_PATH_MAX_PROJECTION_STACK_DEPTH_NV 0x0D38
#define GL_PATH_TRANSPOSE_PROJECTION_MATRIX_NV 0x84E4
#define GL_FRAGMENT_INPUT_NV              0x936D
    typedef GLuint (APIENTRYP PFNGLGENPATHSNVPROC) (GLsizei range);
    typedef void (APIENTRYP PFNGLDELETEPATHSNVPROC) (GLuint path, GLsizei range);
    typedef GLboolean (APIENTRYP PFNGLISPATHNVPROC) (GLuint path);
    typedef void (APIENTRYP PFNGLPATHCOMMANDSNVPROC) (GLuint path, GLsizei numCommands, const GLubyte *commands, GLsizei numCoords, GLenum coordType, const void *coords);
    typedef void (APIENTRYP PFNGLPATHCOORDSNVPROC) (GLuint path, GLsizei numCoords, GLenum coordType, const void *coords);
    typedef void (APIENTRYP PFNGLPATHSUBCOMMANDSNVPROC) (GLuint path, GLsizei commandStart, GLsizei commandsToDelete, GLsizei numCommands, const GLubyte *commands, GLsizei numCoords, GLenum coordType, const void *coords);
    typedef void (APIENTRYP PFNGLPATHSUBCOORDSNVPROC) (GLuint path, GLsizei coordStart, GLsizei numCoords, GLenum coordType, const void *coords);
    typedef void (APIENTRYP PFNGLPATHSTRINGNVPROC) (GLuint path, GLenum format, GLsizei length, const void *pathString);
    typedef void (APIENTRYP PFNGLPATHGLYPHSNVPROC) (GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLsizei numGlyphs, GLenum type, const void *charcodes, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
    typedef void (APIENTRYP PFNGLPATHGLYPHRANGENVPROC) (GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint firstGlyph, GLsizei numGlyphs, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
    typedef void (APIENTRYP PFNGLWEIGHTPATHSNVPROC) (GLuint resultPath, GLsizei numPaths, const GLuint *paths, const GLfloat *weights);
    typedef void (APIENTRYP PFNGLCOPYPATHNVPROC) (GLuint resultPath, GLuint srcPath);
    typedef void (APIENTRYP PFNGLINTERPOLATEPATHSNVPROC) (GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight);
    typedef void (APIENTRYP PFNGLTRANSFORMPATHNVPROC) (GLuint resultPath, GLuint srcPath, GLenum transformType, const GLfloat *transformValues);
    typedef void (APIENTRYP PFNGLPATHPARAMETERIVNVPROC) (GLuint path, GLenum pname, const GLint *value);
    typedef void (APIENTRYP PFNGLPATHPARAMETERINVPROC) (GLuint path, GLenum pname, GLint value);
    typedef void (APIENTRYP PFNGLPATHPARAMETERFVNVPROC) (GLuint path, GLenum pname, const GLfloat *value);
    typedef void (APIENTRYP PFNGLPATHPARAMETERFNVPROC) (GLuint path, GLenum pname, GLfloat value);
    typedef void (APIENTRYP PFNGLPATHDASHARRAYNVPROC) (GLuint path, GLsizei dashCount, const GLfloat *dashArray);
    typedef void (APIENTRYP PFNGLPATHSTENCILFUNCNVPROC) (GLenum func, GLint ref, GLuint mask);
    typedef void (APIENTRYP PFNGLPATHSTENCILDEPTHOFFSETNVPROC) (GLfloat factor, GLfloat units);
    typedef void (APIENTRYP PFNGLSTENCILFILLPATHNVPROC) (GLuint path, GLenum fillMode, GLuint mask);
    typedef void (APIENTRYP PFNGLSTENCILSTROKEPATHNVPROC) (GLuint path, GLint reference, GLuint mask);
    typedef void (APIENTRYP PFNGLSTENCILFILLPATHINSTANCEDNVPROC) (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum transformType, const GLfloat *transformValues);
    typedef void (APIENTRYP PFNGLSTENCILSTROKEPATHINSTANCEDNVPROC) (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLint reference, GLuint mask, GLenum transformType, const GLfloat *transformValues);
    typedef void (APIENTRYP PFNGLPATHCOVERDEPTHFUNCNVPROC) (GLenum func);
    typedef void (APIENTRYP PFNGLCOVERFILLPATHNVPROC) (GLuint path, GLenum coverMode);
    typedef void (APIENTRYP PFNGLCOVERSTROKEPATHNVPROC) (GLuint path, GLenum coverMode);
    typedef void (APIENTRYP PFNGLCOVERFILLPATHINSTANCEDNVPROC) (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
    typedef void (APIENTRYP PFNGLCOVERSTROKEPATHINSTANCEDNVPROC) (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
    typedef void (APIENTRYP PFNGLGETPATHPARAMETERIVNVPROC) (GLuint path, GLenum pname, GLint *value);
    typedef void (APIENTRYP PFNGLGETPATHPARAMETERFVNVPROC) (GLuint path, GLenum pname, GLfloat *value);
    typedef void (APIENTRYP PFNGLGETPATHCOMMANDSNVPROC) (GLuint path, GLubyte *commands);
    typedef void (APIENTRYP PFNGLGETPATHCOORDSNVPROC) (GLuint path, GLfloat *coords);
    typedef void (APIENTRYP PFNGLGETPATHDASHARRAYNVPROC) (GLuint path, GLfloat *dashArray);
    typedef void (APIENTRYP PFNGLGETPATHMETRICSNVPROC) (GLbitfield metricQueryMask, GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLsizei stride, GLfloat *metrics);
    typedef void (APIENTRYP PFNGLGETPATHMETRICRANGENVPROC) (GLbitfield metricQueryMask, GLuint firstPathName, GLsizei numPaths, GLsizei stride, GLfloat *metrics);
    typedef void (APIENTRYP PFNGLGETPATHSPACINGNVPROC) (GLenum pathListMode, GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLfloat advanceScale, GLfloat kerningScale, GLenum transformType, GLfloat *returnedSpacing);
    typedef GLboolean (APIENTRYP PFNGLISPOINTINFILLPATHNVPROC) (GLuint path, GLuint mask, GLfloat x, GLfloat y);
    typedef GLboolean (APIENTRYP PFNGLISPOINTINSTROKEPATHNVPROC) (GLuint path, GLfloat x, GLfloat y);
    typedef GLfloat (APIENTRYP PFNGLGETPATHLENGTHNVPROC) (GLuint path, GLsizei startSegment, GLsizei numSegments);
    typedef GLboolean (APIENTRYP PFNGLPOINTALONGPATHNVPROC) (GLuint path, GLsizei startSegment, GLsizei numSegments, GLfloat distance, GLfloat *x, GLfloat *y, GLfloat *tangentX, GLfloat *tangentY);
    typedef void (APIENTRYP PFNGLMATRIXLOAD3X2FNVPROC) (GLenum matrixMode, const GLfloat *m);
    typedef void (APIENTRYP PFNGLMATRIXLOAD3X3FNVPROC) (GLenum matrixMode, const GLfloat *m);
    typedef void (APIENTRYP PFNGLMATRIXLOADTRANSPOSE3X3FNVPROC) (GLenum matrixMode, const GLfloat *m);
    typedef void (APIENTRYP PFNGLMATRIXMULT3X2FNVPROC) (GLenum matrixMode, const GLfloat *m);
    typedef void (APIENTRYP PFNGLMATRIXMULT3X3FNVPROC) (GLenum matrixMode, const GLfloat *m);
    typedef void (APIENTRYP PFNGLMATRIXMULTTRANSPOSE3X3FNVPROC) (GLenum matrixMode, const GLfloat *m);
    typedef void (APIENTRYP PFNGLSTENCILTHENCOVERFILLPATHNVPROC) (GLuint path, GLenum fillMode, GLuint mask, GLenum coverMode);
    typedef void (APIENTRYP PFNGLSTENCILTHENCOVERSTROKEPATHNVPROC) (GLuint path, GLint reference, GLuint mask, GLenum coverMode);
    typedef void (APIENTRYP PFNGLSTENCILTHENCOVERFILLPATHINSTANCEDNVPROC) (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
    typedef void (APIENTRYP PFNGLSTENCILTHENCOVERSTROKEPATHINSTANCEDNVPROC) (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLint reference, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
    typedef GLenum (APIENTRYP PFNGLPATHGLYPHINDEXRANGENVPROC) (GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint pathParameterTemplate, GLfloat emScale, GLuint baseAndCount[2]);
    typedef GLenum (APIENTRYP PFNGLPATHGLYPHINDEXARRAYNVPROC) (GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
    typedef GLenum (APIENTRYP PFNGLPATHMEMORYGLYPHINDEXARRAYNVPROC) (GLuint firstPathName, GLenum fontTarget, GLsizeiptr fontSize, const void *fontData, GLsizei faceIndex, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
    typedef void (APIENTRYP PFNGLPROGRAMPATHFRAGMENTINPUTGENNVPROC) (GLuint program, GLint location, GLenum genMode, GLint components, const GLfloat *coeffs);
    typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCEFVNVPROC) (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLfloat *params);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI GLuint APIENTRY glGenPathsNV (GLsizei range);
    GLAPI void APIENTRY glDeletePathsNV (GLuint path, GLsizei range);
    GLAPI GLboolean APIENTRY glIsPathNV (GLuint path);
    GLAPI void APIENTRY glPathCommandsNV (GLuint path, GLsizei numCommands, const GLubyte *commands, GLsizei numCoords, GLenum coordType, const void *coords);
    GLAPI void APIENTRY glPathCoordsNV (GLuint path, GLsizei numCoords, GLenum coordType, const void *coords);
    GLAPI void APIENTRY glPathSubCommandsNV (GLuint path, GLsizei commandStart, GLsizei commandsToDelete, GLsizei numCommands, const GLubyte *commands, GLsizei numCoords, GLenum coordType, const void *coords);
    GLAPI void APIENTRY glPathSubCoordsNV (GLuint path, GLsizei coordStart, GLsizei numCoords, GLenum coordType, const void *coords);
    GLAPI void APIENTRY glPathStringNV (GLuint path, GLenum format, GLsizei length, const void *pathString);
    GLAPI void APIENTRY glPathGlyphsNV (GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLsizei numGlyphs, GLenum type, const void *charcodes, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
    GLAPI void APIENTRY glPathGlyphRangeNV (GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint firstGlyph, GLsizei numGlyphs, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
    GLAPI void APIENTRY glWeightPathsNV (GLuint resultPath, GLsizei numPaths, const GLuint *paths, const GLfloat *weights);
    GLAPI void APIENTRY glCopyPathNV (GLuint resultPath, GLuint srcPath);
    GLAPI void APIENTRY glInterpolatePathsNV (GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight);
    GLAPI void APIENTRY glTransformPathNV (GLuint resultPath, GLuint srcPath, GLenum transformType, const GLfloat *transformValues);
    GLAPI void APIENTRY glPathParameterivNV (GLuint path, GLenum pname, const GLint *value);
    GLAPI void APIENTRY glPathParameteriNV (GLuint path, GLenum pname, GLint value);
    GLAPI void APIENTRY glPathParameterfvNV (GLuint path, GLenum pname, const GLfloat *value);
    GLAPI void APIENTRY glPathParameterfNV (GLuint path, GLenum pname, GLfloat value);
    GLAPI void APIENTRY glPathDashArrayNV (GLuint path, GLsizei dashCount, const GLfloat *dashArray);
    GLAPI void APIENTRY glPathStencilFuncNV (GLenum func, GLint ref, GLuint mask);
    GLAPI void APIENTRY glPathStencilDepthOffsetNV (GLfloat factor, GLfloat units);
    GLAPI void APIENTRY glStencilFillPathNV (GLuint path, GLenum fillMode, GLuint mask);
    GLAPI void APIENTRY glStencilStrokePathNV (GLuint path, GLint reference, GLuint mask);
    GLAPI void APIENTRY glStencilFillPathInstancedNV (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum transformType, const GLfloat *transformValues);
    GLAPI void APIENTRY glStencilStrokePathInstancedNV (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLint reference, GLuint mask, GLenum transformType, const GLfloat *transformValues);
    GLAPI void APIENTRY glPathCoverDepthFuncNV (GLenum func);
    GLAPI void APIENTRY glCoverFillPathNV (GLuint path, GLenum coverMode);
    GLAPI void APIENTRY glCoverStrokePathNV (GLuint path, GLenum coverMode);
    GLAPI void APIENTRY glCoverFillPathInstancedNV (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
    GLAPI void APIENTRY glCoverStrokePathInstancedNV (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
    GLAPI void APIENTRY glGetPathParameterivNV (GLuint path, GLenum pname, GLint *value);
    GLAPI void APIENTRY glGetPathParameterfvNV (GLuint path, GLenum pname, GLfloat *value);
    GLAPI void APIENTRY glGetPathCommandsNV (GLuint path, GLubyte *commands);
    GLAPI void APIENTRY glGetPathCoordsNV (GLuint path, GLfloat *coords);
    GLAPI void APIENTRY glGetPathDashArrayNV (GLuint path, GLfloat *dashArray);
    GLAPI void APIENTRY glGetPathMetricsNV (GLbitfield metricQueryMask, GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLsizei stride, GLfloat *metrics);
    GLAPI void APIENTRY glGetPathMetricRangeNV (GLbitfield metricQueryMask, GLuint firstPathName, GLsizei numPaths, GLsizei stride, GLfloat *metrics);
    GLAPI void APIENTRY glGetPathSpacingNV (GLenum pathListMode, GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLfloat advanceScale, GLfloat kerningScale, GLenum transformType, GLfloat *returnedSpacing);
    GLAPI GLboolean APIENTRY glIsPointInFillPathNV (GLuint path, GLuint mask, GLfloat x, GLfloat y);
    GLAPI GLboolean APIENTRY glIsPointInStrokePathNV (GLuint path, GLfloat x, GLfloat y);
    GLAPI GLfloat APIENTRY glGetPathLengthNV (GLuint path, GLsizei startSegment, GLsizei numSegments);
    GLAPI GLboolean APIENTRY glPointAlongPathNV (GLuint path, GLsizei startSegment, GLsizei numSegments, GLfloat distance, GLfloat *x, GLfloat *y, GLfloat *tangentX, GLfloat *tangentY);
    GLAPI void APIENTRY glMatrixLoad3x2fNV (GLenum matrixMode, const GLfloat *m);
    GLAPI void APIENTRY glMatrixLoad3x3fNV (GLenum matrixMode, const GLfloat *m);
    GLAPI void APIENTRY glMatrixLoadTranspose3x3fNV (GLenum matrixMode, const GLfloat *m);
    GLAPI void APIENTRY glMatrixMult3x2fNV (GLenum matrixMode, const GLfloat *m);
    GLAPI void APIENTRY glMatrixMult3x3fNV (GLenum matrixMode, const GLfloat *m);
    GLAPI void APIENTRY glMatrixMultTranspose3x3fNV (GLenum matrixMode, const GLfloat *m);
    GLAPI void APIENTRY glStencilThenCoverFillPathNV (GLuint path, GLenum fillMode, GLuint mask, GLenum coverMode);
    GLAPI void APIENTRY glStencilThenCoverStrokePathNV (GLuint path, GLint reference, GLuint mask, GLenum coverMode);
    GLAPI void APIENTRY glStencilThenCoverFillPathInstancedNV (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
    GLAPI void APIENTRY glStencilThenCoverStrokePathInstancedNV (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLint reference, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
    GLAPI GLenum APIENTRY glPathGlyphIndexRangeNV (GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint pathParameterTemplate, GLfloat emScale, GLuint baseAndCount[2]);
    GLAPI GLenum APIENTRY glPathGlyphIndexArrayNV (GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
    GLAPI GLenum APIENTRY glPathMemoryGlyphIndexArrayNV (GLuint firstPathName, GLenum fontTarget, GLsizeiptr fontSize, const void *fontData, GLsizei faceIndex, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
    GLAPI void APIENTRY glProgramPathFragmentInputGenNV (GLuint program, GLint location, GLenum genMode, GLint components, const GLfloat *coeffs);
    GLAPI void APIENTRY glGetProgramResourcefvNV (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLfloat *params);
#endif
#endif /* GL_NV_path_rendering */
    
#ifndef GL_NV_path_rendering_shared_edge
#define GL_NV_path_rendering_shared_edge 1
#define GL_SHARED_EDGE_NV                 0xC0
#endif /* GL_NV_path_rendering_shared_edge */
    
#ifndef GL_NV_sample_locations
#define GL_NV_sample_locations 1
#define GL_SAMPLE_LOCATION_SUBPIXEL_BITS_NV 0x933D
#define GL_SAMPLE_LOCATION_PIXEL_GRID_WIDTH_NV 0x933E
#define GL_SAMPLE_LOCATION_PIXEL_GRID_HEIGHT_NV 0x933F
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_TABLE_SIZE_NV 0x9340
#define GL_SAMPLE_LOCATION_NV             0x8E50
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_NV 0x9341
#define GL_FRAMEBUFFER_PROGRAMMABLE_SAMPLE_LOCATIONS_NV 0x9342
#define GL_FRAMEBUFFER_SAMPLE_LOCATION_PIXEL_GRID_NV 0x9343
    typedef void (APIENTRYP PFNGLFRAMEBUFFERSAMPLELOCATIONSFVNVPROC) (GLenum target, GLuint start, GLsizei count, const GLfloat *v);
    typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVNVPROC) (GLuint framebuffer, GLuint start, GLsizei count, const GLfloat *v);
    typedef void (APIENTRYP PFNGLRESOLVEDEPTHVALUESNVPROC) (void);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glFramebufferSampleLocationsfvNV (GLenum target, GLuint start, GLsizei count, const GLfloat *v);
    GLAPI void APIENTRY glNamedFramebufferSampleLocationsfvNV (GLuint framebuffer, GLuint start, GLsizei count, const GLfloat *v);
    GLAPI void APIENTRY glResolveDepthValuesNV (void);
#endif
#endif /* GL_NV_sample_locations */
    
#ifndef GL_NV_sample_mask_override_coverage
#define GL_NV_sample_mask_override_coverage 1
#endif /* GL_NV_sample_mask_override_coverage */
    
#ifndef GL_NV_shader_atomic_fp16_vector
#define GL_NV_shader_atomic_fp16_vector 1
#endif /* GL_NV_shader_atomic_fp16_vector */
    
#ifndef GL_NV_viewport_array2
#define GL_NV_viewport_array2 1
#endif /* GL_NV_viewport_array2 */
    
#ifndef GL_NV_viewport_swizzle
#define GL_NV_viewport_swizzle 1
#define GL_VIEWPORT_SWIZZLE_POSITIVE_X_NV 0x9350
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_X_NV 0x9351
#define GL_VIEWPORT_SWIZZLE_POSITIVE_Y_NV 0x9352
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_Y_NV 0x9353
#define GL_VIEWPORT_SWIZZLE_POSITIVE_Z_NV 0x9354
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_Z_NV 0x9355
#define GL_VIEWPORT_SWIZZLE_POSITIVE_W_NV 0x9356
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_W_NV 0x9357
#define GL_VIEWPORT_SWIZZLE_X_NV          0x9358
#define GL_VIEWPORT_SWIZZLE_Y_NV          0x9359
#define GL_VIEWPORT_SWIZZLE_Z_NV          0x935A
#define GL_VIEWPORT_SWIZZLE_W_NV          0x935B
    typedef void (APIENTRYP PFNGLVIEWPORTSWIZZLENVPROC) (GLuint index, GLenum swizzlex, GLenum swizzley, GLenum swizzlez, GLenum swizzlew);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glViewportSwizzleNV (GLuint index, GLenum swizzlex, GLenum swizzley, GLenum swizzlez, GLenum swizzlew);
#endif
#endif /* GL_NV_viewport_swizzle */
    
#ifndef GL_OVR_multiview
#define GL_OVR_multiview 1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_NUM_VIEWS_OVR 0x9630
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_BASE_VIEW_INDEX_OVR 0x9632
#define GL_MAX_VIEWS_OVR                  0x9631
#define GL_FRAMEBUFFER_INCOMPLETE_VIEW_TARGETS_OVR 0x9633
    typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREMULTIVIEWOVRPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint baseViewIndex, GLsizei numViews);
#ifdef GL_GLEXT_PROTOTYPES
    GLAPI void APIENTRY glFramebufferTextureMultiviewOVR (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint baseViewIndex, GLsizei numViews);
#endif
#endif /* GL_OVR_multiview */
    
#ifndef GL_OVR_multiview2
#define GL_OVR_multiview2 1
#endif /* GL_OVR_multiview2 */
    
#ifdef __cplusplus
}
#endif

typedef  void __stdcall GLCULLFACE (GLenum mode);
GLCULLFACE *glCullFace;
typedef  void __stdcall GLFRONTFACE (GLenum mode);
GLFRONTFACE *glFrontFace;
typedef  void __stdcall GLHINT (GLenum target, GLenum mode);
GLHINT *glHint;
typedef  void __stdcall GLLINEWIDTH (GLfloat width);
GLLINEWIDTH *glLineWidth;
typedef  void __stdcall GLPOINTSIZE (GLfloat size);
GLPOINTSIZE *glPointSize;
typedef  void __stdcall GLPOLYGONMODE (GLenum face, GLenum mode);
GLPOLYGONMODE *glPolygonMode;
typedef  void __stdcall GLSCISSOR (GLint x, GLint y, GLsizei width, GLsizei height);
GLSCISSOR *glScissor;
typedef  void __stdcall GLTEXPARAMETERF (GLenum target, GLenum pname, GLfloat param);
GLTEXPARAMETERF *glTexParameterf;
typedef  void __stdcall GLTEXPARAMETERFV (GLenum target, GLenum pname, const GLfloat *params);
GLTEXPARAMETERFV *glTexParameterfv;
typedef  void __stdcall GLTEXPARAMETERI (GLenum target, GLenum pname, GLint param);
GLTEXPARAMETERI *glTexParameteri;
typedef  void __stdcall GLTEXPARAMETERIV (GLenum target, GLenum pname, const GLint *params);
GLTEXPARAMETERIV *glTexParameteriv;
typedef  void __stdcall GLTEXIMAGE1D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
GLTEXIMAGE1D *glTexImage1D;
typedef  void __stdcall GLTEXIMAGE2D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
GLTEXIMAGE2D *glTexImage2D;
typedef  void __stdcall GLDRAWBUFFER (GLenum buf);
GLDRAWBUFFER *glDrawBuffer;
typedef  void __stdcall GLCLEAR (GLbitfield mask);
GLCLEAR *glClear;
typedef  void __stdcall GLCLEARCOLOR (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLCLEARCOLOR *glClearColor;
typedef  void __stdcall GLCLEARSTENCIL (GLint s);
GLCLEARSTENCIL *glClearStencil;
typedef  void __stdcall GLCLEARDEPTH (GLdouble depth);
GLCLEARDEPTH *glClearDepth;
typedef  void __stdcall GLSTENCILMASK (GLuint mask);
GLSTENCILMASK *glStencilMask;
typedef  void __stdcall GLCOLORMASK (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
GLCOLORMASK *glColorMask;
typedef  void __stdcall GLDEPTHMASK (GLboolean flag);
GLDEPTHMASK *glDepthMask;
typedef  void __stdcall GLDISABLE (GLenum cap);
GLDISABLE *glDisable;
typedef  void __stdcall GLENABLE (GLenum cap);
GLENABLE *glEnable;
typedef  void __stdcall GLFINISH (void);
GLFINISH *glFinish;
typedef  void __stdcall GLFLUSH (void);
GLFLUSH *glFlush;
typedef  void __stdcall GLBLENDFUNC (GLenum sfactor, GLenum dfactor);
GLBLENDFUNC *glBlendFunc;
typedef  void __stdcall GLLOGICOP (GLenum opcode);
GLLOGICOP *glLogicOp;
typedef  void __stdcall GLSTENCILFUNC (GLenum func, GLint ref, GLuint mask);
GLSTENCILFUNC *glStencilFunc;
typedef  void __stdcall GLSTENCILOP (GLenum fail, GLenum zfail, GLenum zpass);
GLSTENCILOP *glStencilOp;
typedef  void __stdcall GLDEPTHFUNC (GLenum func);
GLDEPTHFUNC *glDepthFunc;
typedef  void __stdcall GLPIXELSTOREF (GLenum pname, GLfloat param);
GLPIXELSTOREF *glPixelStoref;
typedef  void __stdcall GLPIXELSTOREI (GLenum pname, GLint param);
GLPIXELSTOREI *glPixelStorei;
typedef  void __stdcall GLREADBUFFER (GLenum src);
GLREADBUFFER *glReadBuffer;
typedef  void __stdcall GLREADPIXELS (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
GLREADPIXELS *glReadPixels;
typedef  void __stdcall GLGETBOOLEANV (GLenum pname, GLboolean *data);
GLGETBOOLEANV *glGetBooleanv;
typedef  void __stdcall GLGETDOUBLEV (GLenum pname, GLdouble *data);
GLGETDOUBLEV *glGetDoublev;
typedef  GLenum __stdcall GLGETERROR (void);
GLGETERROR *glGetError;
typedef  void __stdcall GLGETFLOATV (GLenum pname, GLfloat *data);
GLGETFLOATV *glGetFloatv;
typedef  void __stdcall GLGETINTEGERV (GLenum pname, GLint *data);
GLGETINTEGERV *glGetIntegerv;
typedef  const GLubyte  __stdcall GLGETSTRING (GLenum name);
GLGETSTRING *glGetString;
typedef  void __stdcall GLGETTEXIMAGE (GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
GLGETTEXIMAGE *glGetTexImage;
typedef  void __stdcall GLGETTEXPARAMETERFV (GLenum target, GLenum pname, GLfloat *params);
GLGETTEXPARAMETERFV *glGetTexParameterfv;
typedef  void __stdcall GLGETTEXPARAMETERIV (GLenum target, GLenum pname, GLint *params);
GLGETTEXPARAMETERIV *glGetTexParameteriv;
typedef  void __stdcall GLGETTEXLEVELPARAMETERFV (GLenum target, GLint level, GLenum pname, GLfloat *params);
GLGETTEXLEVELPARAMETERFV *glGetTexLevelParameterfv;
typedef  void __stdcall GLGETTEXLEVELPARAMETERIV (GLenum target, GLint level, GLenum pname, GLint *params);
GLGETTEXLEVELPARAMETERIV *glGetTexLevelParameteriv;
typedef  GLboolean __stdcall GLISENABLED (GLenum cap);
GLISENABLED *glIsEnabled;
typedef  void __stdcall GLDEPTHRANGE (GLdouble near, GLdouble far);
GLDEPTHRANGE *glDepthRange;
typedef  void __stdcall GLVIEWPORT (GLint x, GLint y, GLsizei width, GLsizei height);
GLVIEWPORT *glViewport;
typedef  void __stdcall GLDRAWARRAYS (GLenum mode, GLint first, GLsizei count);
GLDRAWARRAYS *glDrawArrays;
typedef  void __stdcall GLDRAWELEMENTS (GLenum mode, GLsizei count, GLenum type, const void *indices);
GLDRAWELEMENTS *glDrawElements;
typedef  void __stdcall GLGETPOINTERV (GLenum pname, void **params);
GLGETPOINTERV *glGetPointerv;
typedef  void __stdcall GLPOLYGONOFFSET (GLfloat factor, GLfloat units);
GLPOLYGONOFFSET *glPolygonOffset;
typedef  void __stdcall GLCOPYTEXIMAGE1D (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
GLCOPYTEXIMAGE1D *glCopyTexImage1D;
typedef  void __stdcall GLCOPYTEXIMAGE2D (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
GLCOPYTEXIMAGE2D *glCopyTexImage2D;
typedef  void __stdcall GLCOPYTEXSUBIMAGE1D (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
GLCOPYTEXSUBIMAGE1D *glCopyTexSubImage1D;
typedef  void __stdcall GLCOPYTEXSUBIMAGE2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLCOPYTEXSUBIMAGE2D *glCopyTexSubImage2D;
typedef  void __stdcall GLTEXSUBIMAGE1D (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
GLTEXSUBIMAGE1D *glTexSubImage1D;
typedef  void __stdcall GLTEXSUBIMAGE2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
GLTEXSUBIMAGE2D *glTexSubImage2D;
typedef  void __stdcall GLBINDTEXTURE (GLenum target, GLuint texture);
GLBINDTEXTURE *glBindTexture;
typedef  void __stdcall GLDELETETEXTURES (GLsizei n, const GLuint *textures);
GLDELETETEXTURES *glDeleteTextures;
typedef  void __stdcall GLGENTEXTURES (GLsizei n, GLuint *textures);
GLGENTEXTURES *glGenTextures;
typedef  GLboolean __stdcall GLISTEXTURE (GLuint texture);
GLISTEXTURE *glIsTexture;
typedef  void __stdcall GLDRAWRANGEELEMENTS (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
GLDRAWRANGEELEMENTS *glDrawRangeElements;
typedef  void __stdcall GLTEXIMAGE3D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
GLTEXIMAGE3D *glTexImage3D;
typedef  void __stdcall GLTEXSUBIMAGE3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
GLTEXSUBIMAGE3D *glTexSubImage3D;
typedef  void __stdcall GLCOPYTEXSUBIMAGE3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLCOPYTEXSUBIMAGE3D *glCopyTexSubImage3D;
typedef  void __stdcall GLACTIVETEXTURE (GLenum texture);
GLACTIVETEXTURE *glActiveTexture;
typedef  void __stdcall GLSAMPLECOVERAGE (GLfloat value, GLboolean invert);
GLSAMPLECOVERAGE *glSampleCoverage;
typedef  void __stdcall GLCOMPRESSEDTEXIMAGE3D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
GLCOMPRESSEDTEXIMAGE3D *glCompressedTexImage3D;
typedef  void __stdcall GLCOMPRESSEDTEXIMAGE2D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
GLCOMPRESSEDTEXIMAGE2D *glCompressedTexImage2D;
typedef  void __stdcall GLCOMPRESSEDTEXIMAGE1D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
GLCOMPRESSEDTEXIMAGE1D *glCompressedTexImage1D;
typedef  void __stdcall GLCOMPRESSEDTEXSUBIMAGE3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
GLCOMPRESSEDTEXSUBIMAGE3D *glCompressedTexSubImage3D;
typedef  void __stdcall GLCOMPRESSEDTEXSUBIMAGE2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
GLCOMPRESSEDTEXSUBIMAGE2D *glCompressedTexSubImage2D;
typedef  void __stdcall GLCOMPRESSEDTEXSUBIMAGE1D (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
GLCOMPRESSEDTEXSUBIMAGE1D *glCompressedTexSubImage1D;
typedef  void __stdcall GLGETCOMPRESSEDTEXIMAGE (GLenum target, GLint level, void *img);
GLGETCOMPRESSEDTEXIMAGE *glGetCompressedTexImage;
typedef  void __stdcall GLBLENDFUNCSEPARATE (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
GLBLENDFUNCSEPARATE *glBlendFuncSeparate;
typedef  void __stdcall GLMULTIDRAWARRAYS (GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
GLMULTIDRAWARRAYS *glMultiDrawArrays;
typedef  void __stdcall GLMULTIDRAWELEMENTS (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount);
GLMULTIDRAWELEMENTS *glMultiDrawElements;
typedef  void __stdcall GLPOINTPARAMETERF (GLenum pname, GLfloat param);
GLPOINTPARAMETERF *glPointParameterf;
typedef  void __stdcall GLPOINTPARAMETERFV (GLenum pname, const GLfloat *params);
GLPOINTPARAMETERFV *glPointParameterfv;
typedef  void __stdcall GLPOINTPARAMETERI (GLenum pname, GLint param);
GLPOINTPARAMETERI *glPointParameteri;
typedef  void __stdcall GLPOINTPARAMETERIV (GLenum pname, const GLint *params);
GLPOINTPARAMETERIV *glPointParameteriv;
typedef  void __stdcall GLBLENDCOLOR (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLBLENDCOLOR *glBlendColor;
typedef  void __stdcall GLBLENDEQUATION (GLenum mode);
GLBLENDEQUATION *glBlendEquation;
typedef  void __stdcall GLGENQUERIES (GLsizei n, GLuint *ids);
GLGENQUERIES *glGenQueries;
typedef  void __stdcall GLDELETEQUERIES (GLsizei n, const GLuint *ids);
GLDELETEQUERIES *glDeleteQueries;
typedef  GLboolean __stdcall GLISQUERY (GLuint id);
GLISQUERY *glIsQuery;
typedef  void __stdcall GLBEGINQUERY (GLenum target, GLuint id);
GLBEGINQUERY *glBeginQuery;
typedef  void __stdcall GLENDQUERY (GLenum target);
GLENDQUERY *glEndQuery;
typedef  void __stdcall GLGETQUERYIV (GLenum target, GLenum pname, GLint *params);
GLGETQUERYIV *glGetQueryiv;
typedef  void __stdcall GLGETQUERYOBJECTIV (GLuint id, GLenum pname, GLint *params);
GLGETQUERYOBJECTIV *glGetQueryObjectiv;
typedef  void __stdcall GLGETQUERYOBJECTUIV (GLuint id, GLenum pname, GLuint *params);
GLGETQUERYOBJECTUIV *glGetQueryObjectuiv;
typedef  void __stdcall GLBINDBUFFER (GLenum target, GLuint buffer);
GLBINDBUFFER *glBindBuffer;
typedef  void __stdcall GLDELETEBUFFERS (GLsizei n, const GLuint *buffers);
GLDELETEBUFFERS *glDeleteBuffers;
typedef  void __stdcall GLGENBUFFERS (GLsizei n, GLuint *buffers);
GLGENBUFFERS *glGenBuffers;
typedef  GLboolean __stdcall GLISBUFFER (GLuint buffer);
GLISBUFFER *glIsBuffer;
typedef  void __stdcall GLBUFFERDATA (GLenum target, GLsizeiptr size, const void *data, GLenum usage);
GLBUFFERDATA *glBufferData;
typedef  void __stdcall GLBUFFERSUBDATA (GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
GLBUFFERSUBDATA *glBufferSubData;
typedef  void __stdcall GLGETBUFFERSUBDATA (GLenum target, GLintptr offset, GLsizeiptr size, void *data);
GLGETBUFFERSUBDATA *glGetBufferSubData;
typedef  void  __stdcall GLMAPBUFFER (GLenum target, GLenum access);
GLMAPBUFFER *glMapBuffer;
typedef  GLboolean __stdcall GLUNMAPBUFFER (GLenum target);
GLUNMAPBUFFER *glUnmapBuffer;
typedef  void __stdcall GLGETBUFFERPARAMETERIV (GLenum target, GLenum pname, GLint *params);
GLGETBUFFERPARAMETERIV *glGetBufferParameteriv;
typedef  void __stdcall GLGETBUFFERPOINTERV (GLenum target, GLenum pname, void **params);
GLGETBUFFERPOINTERV *glGetBufferPointerv;
typedef  void __stdcall GLBLENDEQUATIONSEPARATE (GLenum modeRGB, GLenum modeAlpha);
GLBLENDEQUATIONSEPARATE *glBlendEquationSeparate;
typedef  void __stdcall GLDRAWBUFFERS (GLsizei n, const GLenum *bufs);
GLDRAWBUFFERS *glDrawBuffers;
typedef  void __stdcall GLSTENCILOPSEPARATE (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
GLSTENCILOPSEPARATE *glStencilOpSeparate;
typedef  void __stdcall GLSTENCILFUNCSEPARATE (GLenum face, GLenum func, GLint ref, GLuint mask);
GLSTENCILFUNCSEPARATE *glStencilFuncSeparate;
typedef  void __stdcall GLSTENCILMASKSEPARATE (GLenum face, GLuint mask);
GLSTENCILMASKSEPARATE *glStencilMaskSeparate;
typedef  void __stdcall GLATTACHSHADER (GLuint program, GLuint shader);
GLATTACHSHADER *glAttachShader;
typedef  void __stdcall GLBINDATTRIBLOCATION (GLuint program, GLuint index, const GLchar *name);
GLBINDATTRIBLOCATION *glBindAttribLocation;
typedef  void __stdcall GLCOMPILESHADER (GLuint shader);
GLCOMPILESHADER *glCompileShader;
typedef  GLuint __stdcall GLCREATEPROGRAM (void);
GLCREATEPROGRAM *glCreateProgram;
typedef  GLuint __stdcall GLCREATESHADER (GLenum type);
GLCREATESHADER *glCreateShader;
typedef  void __stdcall GLDELETEPROGRAM (GLuint program);
GLDELETEPROGRAM *glDeleteProgram;
typedef  void __stdcall GLDELETESHADER (GLuint shader);
GLDELETESHADER *glDeleteShader;
typedef  void __stdcall GLDETACHSHADER (GLuint program, GLuint shader);
GLDETACHSHADER *glDetachShader;
typedef  void __stdcall GLDISABLEVERTEXATTRIBARRAY (GLuint index);
GLDISABLEVERTEXATTRIBARRAY *glDisableVertexAttribArray;
typedef  void __stdcall GLENABLEVERTEXATTRIBARRAY (GLuint index);
GLENABLEVERTEXATTRIBARRAY *glEnableVertexAttribArray;
typedef  void __stdcall GLGETACTIVEATTRIB (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
GLGETACTIVEATTRIB *glGetActiveAttrib;
typedef  void __stdcall GLGETACTIVEUNIFORM (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
GLGETACTIVEUNIFORM *glGetActiveUniform;
typedef  void __stdcall GLGETATTACHEDSHADERS (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
GLGETATTACHEDSHADERS *glGetAttachedShaders;
typedef  GLint __stdcall GLGETATTRIBLOCATION (GLuint program, const GLchar *name);
GLGETATTRIBLOCATION *glGetAttribLocation;
typedef  void __stdcall GLGETPROGRAMIV (GLuint program, GLenum pname, GLint *params);
GLGETPROGRAMIV *glGetProgramiv;
typedef  void __stdcall GLGETPROGRAMINFOLOG (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GLGETPROGRAMINFOLOG *glGetProgramInfoLog;
typedef  void __stdcall GLGETSHADERIV (GLuint shader, GLenum pname, GLint *params);
GLGETSHADERIV *glGetShaderiv;
typedef  void __stdcall GLGETSHADERINFOLOG (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GLGETSHADERINFOLOG *glGetShaderInfoLog;
typedef  void __stdcall GLGETSHADERSOURCE (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
GLGETSHADERSOURCE *glGetShaderSource;
typedef  GLint __stdcall GLGETUNIFORMLOCATION (GLuint program, const GLchar *name);
GLGETUNIFORMLOCATION *glGetUniformLocation;
typedef  void __stdcall GLGETUNIFORMFV (GLuint program, GLint location, GLfloat *params);
GLGETUNIFORMFV *glGetUniformfv;
typedef  void __stdcall GLGETUNIFORMIV (GLuint program, GLint location, GLint *params);
GLGETUNIFORMIV *glGetUniformiv;
typedef  void __stdcall GLGETVERTEXATTRIBDV (GLuint index, GLenum pname, GLdouble *params);
GLGETVERTEXATTRIBDV *glGetVertexAttribdv;
typedef  void __stdcall GLGETVERTEXATTRIBFV (GLuint index, GLenum pname, GLfloat *params);
GLGETVERTEXATTRIBFV *glGetVertexAttribfv;
typedef  void __stdcall GLGETVERTEXATTRIBIV (GLuint index, GLenum pname, GLint *params);
GLGETVERTEXATTRIBIV *glGetVertexAttribiv;
typedef  void __stdcall GLGETVERTEXATTRIBPOINTERV (GLuint index, GLenum pname, void **pointer);
GLGETVERTEXATTRIBPOINTERV *glGetVertexAttribPointerv;
typedef  GLboolean __stdcall GLISPROGRAM (GLuint program);
GLISPROGRAM *glIsProgram;
typedef  GLboolean __stdcall GLISSHADER (GLuint shader);
GLISSHADER *glIsShader;
typedef  void __stdcall GLLINKPROGRAM (GLuint program);
GLLINKPROGRAM *glLinkProgram;
typedef  void __stdcall GLSHADERSOURCE (GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
GLSHADERSOURCE *glShaderSource;
typedef  void __stdcall GLUSEPROGRAM (GLuint program);
GLUSEPROGRAM *glUseProgram;
typedef  void __stdcall GLUNIFORM1F (GLint location, GLfloat v0);
GLUNIFORM1F *glUniform1f;
typedef  void __stdcall GLUNIFORM2F (GLint location, GLfloat v0, GLfloat v1);
GLUNIFORM2F *glUniform2f;
typedef  void __stdcall GLUNIFORM3F (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
GLUNIFORM3F *glUniform3f;
typedef  void __stdcall GLUNIFORM4F (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
GLUNIFORM4F *glUniform4f;
typedef  void __stdcall GLUNIFORM1I (GLint location, GLint v0);
GLUNIFORM1I *glUniform1i;
typedef  void __stdcall GLUNIFORM2I (GLint location, GLint v0, GLint v1);
GLUNIFORM2I *glUniform2i;
typedef  void __stdcall GLUNIFORM3I (GLint location, GLint v0, GLint v1, GLint v2);
GLUNIFORM3I *glUniform3i;
typedef  void __stdcall GLUNIFORM4I (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
GLUNIFORM4I *glUniform4i;
typedef  void __stdcall GLUNIFORM1FV (GLint location, GLsizei count, const GLfloat *value);
GLUNIFORM1FV *glUniform1fv;
typedef  void __stdcall GLUNIFORM2FV (GLint location, GLsizei count, const GLfloat *value);
GLUNIFORM2FV *glUniform2fv;
typedef  void __stdcall GLUNIFORM3FV (GLint location, GLsizei count, const GLfloat *value);
GLUNIFORM3FV *glUniform3fv;
typedef  void __stdcall GLUNIFORM4FV (GLint location, GLsizei count, const GLfloat *value);
GLUNIFORM4FV *glUniform4fv;
typedef  void __stdcall GLUNIFORM1IV (GLint location, GLsizei count, const GLint *value);
GLUNIFORM1IV *glUniform1iv;
typedef  void __stdcall GLUNIFORM2IV (GLint location, GLsizei count, const GLint *value);
GLUNIFORM2IV *glUniform2iv;
typedef  void __stdcall GLUNIFORM3IV (GLint location, GLsizei count, const GLint *value);
GLUNIFORM3IV *glUniform3iv;
typedef  void __stdcall GLUNIFORM4IV (GLint location, GLsizei count, const GLint *value);
GLUNIFORM4IV *glUniform4iv;
typedef  void __stdcall GLUNIFORMMATRIX2FV (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLUNIFORMMATRIX2FV *glUniformMatrix2fv;
typedef  void __stdcall GLUNIFORMMATRIX3FV (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLUNIFORMMATRIX3FV *glUniformMatrix3fv;
typedef  void __stdcall GLUNIFORMMATRIX4FV (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLUNIFORMMATRIX4FV *glUniformMatrix4fv;
typedef  void __stdcall GLVALIDATEPROGRAM (GLuint program);
GLVALIDATEPROGRAM *glValidateProgram;
typedef  void __stdcall GLVERTEXATTRIB1D (GLuint index, GLdouble x);
GLVERTEXATTRIB1D *glVertexAttrib1d;
typedef  void __stdcall GLVERTEXATTRIB1DV (GLuint index, const GLdouble *v);
GLVERTEXATTRIB1DV *glVertexAttrib1dv;
typedef  void __stdcall GLVERTEXATTRIB1F (GLuint index, GLfloat x);
GLVERTEXATTRIB1F *glVertexAttrib1f;
typedef  void __stdcall GLVERTEXATTRIB1FV (GLuint index, const GLfloat *v);
GLVERTEXATTRIB1FV *glVertexAttrib1fv;
typedef  void __stdcall GLVERTEXATTRIB1S (GLuint index, GLshort x);
GLVERTEXATTRIB1S *glVertexAttrib1s;
typedef  void __stdcall GLVERTEXATTRIB1SV (GLuint index, const GLshort *v);
GLVERTEXATTRIB1SV *glVertexAttrib1sv;
typedef  void __stdcall GLVERTEXATTRIB2D (GLuint index, GLdouble x, GLdouble y);
GLVERTEXATTRIB2D *glVertexAttrib2d;
typedef  void __stdcall GLVERTEXATTRIB2DV (GLuint index, const GLdouble *v);
GLVERTEXATTRIB2DV *glVertexAttrib2dv;
typedef  void __stdcall GLVERTEXATTRIB2F (GLuint index, GLfloat x, GLfloat y);
GLVERTEXATTRIB2F *glVertexAttrib2f;
typedef  void __stdcall GLVERTEXATTRIB2FV (GLuint index, const GLfloat *v);
GLVERTEXATTRIB2FV *glVertexAttrib2fv;
typedef  void __stdcall GLVERTEXATTRIB2S (GLuint index, GLshort x, GLshort y);
GLVERTEXATTRIB2S *glVertexAttrib2s;
typedef  void __stdcall GLVERTEXATTRIB2SV (GLuint index, const GLshort *v);
GLVERTEXATTRIB2SV *glVertexAttrib2sv;
typedef  void __stdcall GLVERTEXATTRIB3D (GLuint index, GLdouble x, GLdouble y, GLdouble z);
GLVERTEXATTRIB3D *glVertexAttrib3d;
typedef  void __stdcall GLVERTEXATTRIB3DV (GLuint index, const GLdouble *v);
GLVERTEXATTRIB3DV *glVertexAttrib3dv;
typedef  void __stdcall GLVERTEXATTRIB3F (GLuint index, GLfloat x, GLfloat y, GLfloat z);
GLVERTEXATTRIB3F *glVertexAttrib3f;
typedef  void __stdcall GLVERTEXATTRIB3FV (GLuint index, const GLfloat *v);
GLVERTEXATTRIB3FV *glVertexAttrib3fv;
typedef  void __stdcall GLVERTEXATTRIB3S (GLuint index, GLshort x, GLshort y, GLshort z);
GLVERTEXATTRIB3S *glVertexAttrib3s;
typedef  void __stdcall GLVERTEXATTRIB3SV (GLuint index, const GLshort *v);
GLVERTEXATTRIB3SV *glVertexAttrib3sv;
typedef  void __stdcall GLVERTEXATTRIB4NBV (GLuint index, const GLbyte *v);
GLVERTEXATTRIB4NBV *glVertexAttrib4Nbv;
typedef  void __stdcall GLVERTEXATTRIB4NIV (GLuint index, const GLint *v);
GLVERTEXATTRIB4NIV *glVertexAttrib4Niv;
typedef  void __stdcall GLVERTEXATTRIB4NSV (GLuint index, const GLshort *v);
GLVERTEXATTRIB4NSV *glVertexAttrib4Nsv;
typedef  void __stdcall GLVERTEXATTRIB4NUB (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
GLVERTEXATTRIB4NUB *glVertexAttrib4Nub;
typedef  void __stdcall GLVERTEXATTRIB4NUBV (GLuint index, const GLubyte *v);
GLVERTEXATTRIB4NUBV *glVertexAttrib4Nubv;
typedef  void __stdcall GLVERTEXATTRIB4NUIV (GLuint index, const GLuint *v);
GLVERTEXATTRIB4NUIV *glVertexAttrib4Nuiv;
typedef  void __stdcall GLVERTEXATTRIB4NUSV (GLuint index, const GLushort *v);
GLVERTEXATTRIB4NUSV *glVertexAttrib4Nusv;
typedef  void __stdcall GLVERTEXATTRIB4BV (GLuint index, const GLbyte *v);
GLVERTEXATTRIB4BV *glVertexAttrib4bv;
typedef  void __stdcall GLVERTEXATTRIB4D (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLVERTEXATTRIB4D *glVertexAttrib4d;
typedef  void __stdcall GLVERTEXATTRIB4DV (GLuint index, const GLdouble *v);
GLVERTEXATTRIB4DV *glVertexAttrib4dv;
typedef  void __stdcall GLVERTEXATTRIB4F (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLVERTEXATTRIB4F *glVertexAttrib4f;
typedef  void __stdcall GLVERTEXATTRIB4FV (GLuint index, const GLfloat *v);
GLVERTEXATTRIB4FV *glVertexAttrib4fv;
typedef  void __stdcall GLVERTEXATTRIB4IV (GLuint index, const GLint *v);
GLVERTEXATTRIB4IV *glVertexAttrib4iv;
typedef  void __stdcall GLVERTEXATTRIB4S (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
GLVERTEXATTRIB4S *glVertexAttrib4s;
typedef  void __stdcall GLVERTEXATTRIB4SV (GLuint index, const GLshort *v);
GLVERTEXATTRIB4SV *glVertexAttrib4sv;
typedef  void __stdcall GLVERTEXATTRIB4UBV (GLuint index, const GLubyte *v);
GLVERTEXATTRIB4UBV *glVertexAttrib4ubv;
typedef  void __stdcall GLVERTEXATTRIB4UIV (GLuint index, const GLuint *v);
GLVERTEXATTRIB4UIV *glVertexAttrib4uiv;
typedef  void __stdcall GLVERTEXATTRIB4USV (GLuint index, const GLushort *v);
GLVERTEXATTRIB4USV *glVertexAttrib4usv;
typedef  void __stdcall GLVERTEXATTRIBPOINTER (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
GLVERTEXATTRIBPOINTER *glVertexAttribPointer;
typedef  void __stdcall GLUNIFORMMATRIX2X3FV (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLUNIFORMMATRIX2X3FV *glUniformMatrix2x3fv;
typedef  void __stdcall GLUNIFORMMATRIX3X2FV (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLUNIFORMMATRIX3X2FV *glUniformMatrix3x2fv;
typedef  void __stdcall GLUNIFORMMATRIX2X4FV (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLUNIFORMMATRIX2X4FV *glUniformMatrix2x4fv;
typedef  void __stdcall GLUNIFORMMATRIX4X2FV (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLUNIFORMMATRIX4X2FV *glUniformMatrix4x2fv;
typedef  void __stdcall GLUNIFORMMATRIX3X4FV (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLUNIFORMMATRIX3X4FV *glUniformMatrix3x4fv;
typedef  void __stdcall GLUNIFORMMATRIX4X3FV (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLUNIFORMMATRIX4X3FV *glUniformMatrix4x3fv;
typedef  void __stdcall GLCOLORMASKI (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
GLCOLORMASKI *glColorMaski;
typedef  void __stdcall GLGETBOOLEANI_V (GLenum target, GLuint index, GLboolean *data);
GLGETBOOLEANI_V *glGetBooleani_v;
typedef  void __stdcall GLGETINTEGERI_V (GLenum target, GLuint index, GLint *data);
GLGETINTEGERI_V *glGetIntegeri_v;
typedef  void __stdcall GLENABLEI (GLenum target, GLuint index);
GLENABLEI *glEnablei;
typedef  void __stdcall GLDISABLEI (GLenum target, GLuint index);
GLDISABLEI *glDisablei;
typedef  GLboolean __stdcall GLISENABLEDI (GLenum target, GLuint index);
GLISENABLEDI *glIsEnabledi;
typedef  void __stdcall GLBEGINTRANSFORMFEEDBACK (GLenum primitiveMode);
GLBEGINTRANSFORMFEEDBACK *glBeginTransformFeedback;
typedef  void __stdcall GLENDTRANSFORMFEEDBACK (void);
GLENDTRANSFORMFEEDBACK *glEndTransformFeedback;
typedef  void __stdcall GLBINDBUFFERRANGE (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLBINDBUFFERRANGE *glBindBufferRange;
typedef  void __stdcall GLBINDBUFFERBASE (GLenum target, GLuint index, GLuint buffer);
GLBINDBUFFERBASE *glBindBufferBase;
typedef  void __stdcall GLTRANSFORMFEEDBACKVARYINGS (GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
GLTRANSFORMFEEDBACKVARYINGS *glTransformFeedbackVaryings;
typedef  void __stdcall GLGETTRANSFORMFEEDBACKVARYING (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
GLGETTRANSFORMFEEDBACKVARYING *glGetTransformFeedbackVarying;
typedef  void __stdcall GLCLAMPCOLOR (GLenum target, GLenum clamp);
GLCLAMPCOLOR *glClampColor;
typedef  void __stdcall GLBEGINCONDITIONALRENDER (GLuint id, GLenum mode);
GLBEGINCONDITIONALRENDER *glBeginConditionalRender;
typedef  void __stdcall GLENDCONDITIONALRENDER (void);
GLENDCONDITIONALRENDER *glEndConditionalRender;
typedef  void __stdcall GLVERTEXATTRIBIPOINTER (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
GLVERTEXATTRIBIPOINTER *glVertexAttribIPointer;
typedef  void __stdcall GLGETVERTEXATTRIBIIV (GLuint index, GLenum pname, GLint *params);
GLGETVERTEXATTRIBIIV *glGetVertexAttribIiv;
typedef  void __stdcall GLGETVERTEXATTRIBIUIV (GLuint index, GLenum pname, GLuint *params);
GLGETVERTEXATTRIBIUIV *glGetVertexAttribIuiv;
typedef  void __stdcall GLVERTEXATTRIBI1I (GLuint index, GLint x);
GLVERTEXATTRIBI1I *glVertexAttribI1i;
typedef  void __stdcall GLVERTEXATTRIBI2I (GLuint index, GLint x, GLint y);
GLVERTEXATTRIBI2I *glVertexAttribI2i;
typedef  void __stdcall GLVERTEXATTRIBI3I (GLuint index, GLint x, GLint y, GLint z);
GLVERTEXATTRIBI3I *glVertexAttribI3i;
typedef  void __stdcall GLVERTEXATTRIBI4I (GLuint index, GLint x, GLint y, GLint z, GLint w);
GLVERTEXATTRIBI4I *glVertexAttribI4i;
typedef  void __stdcall GLVERTEXATTRIBI1UI (GLuint index, GLuint x);
GLVERTEXATTRIBI1UI *glVertexAttribI1ui;
typedef  void __stdcall GLVERTEXATTRIBI2UI (GLuint index, GLuint x, GLuint y);
GLVERTEXATTRIBI2UI *glVertexAttribI2ui;
typedef  void __stdcall GLVERTEXATTRIBI3UI (GLuint index, GLuint x, GLuint y, GLuint z);
GLVERTEXATTRIBI3UI *glVertexAttribI3ui;
typedef  void __stdcall GLVERTEXATTRIBI4UI (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
GLVERTEXATTRIBI4UI *glVertexAttribI4ui;
typedef  void __stdcall GLVERTEXATTRIBI1IV (GLuint index, const GLint *v);
GLVERTEXATTRIBI1IV *glVertexAttribI1iv;
typedef  void __stdcall GLVERTEXATTRIBI2IV (GLuint index, const GLint *v);
GLVERTEXATTRIBI2IV *glVertexAttribI2iv;
typedef  void __stdcall GLVERTEXATTRIBI3IV (GLuint index, const GLint *v);
GLVERTEXATTRIBI3IV *glVertexAttribI3iv;
typedef  void __stdcall GLVERTEXATTRIBI4IV (GLuint index, const GLint *v);
GLVERTEXATTRIBI4IV *glVertexAttribI4iv;
typedef  void __stdcall GLVERTEXATTRIBI1UIV (GLuint index, const GLuint *v);
GLVERTEXATTRIBI1UIV *glVertexAttribI1uiv;
typedef  void __stdcall GLVERTEXATTRIBI2UIV (GLuint index, const GLuint *v);
GLVERTEXATTRIBI2UIV *glVertexAttribI2uiv;
typedef  void __stdcall GLVERTEXATTRIBI3UIV (GLuint index, const GLuint *v);
GLVERTEXATTRIBI3UIV *glVertexAttribI3uiv;
typedef  void __stdcall GLVERTEXATTRIBI4UIV (GLuint index, const GLuint *v);
GLVERTEXATTRIBI4UIV *glVertexAttribI4uiv;
typedef  void __stdcall GLVERTEXATTRIBI4BV (GLuint index, const GLbyte *v);
GLVERTEXATTRIBI4BV *glVertexAttribI4bv;
typedef  void __stdcall GLVERTEXATTRIBI4SV (GLuint index, const GLshort *v);
GLVERTEXATTRIBI4SV *glVertexAttribI4sv;
typedef  void __stdcall GLVERTEXATTRIBI4UBV (GLuint index, const GLubyte *v);
GLVERTEXATTRIBI4UBV *glVertexAttribI4ubv;
typedef  void __stdcall GLVERTEXATTRIBI4USV (GLuint index, const GLushort *v);
GLVERTEXATTRIBI4USV *glVertexAttribI4usv;
typedef  void __stdcall GLGETUNIFORMUIV (GLuint program, GLint location, GLuint *params);
GLGETUNIFORMUIV *glGetUniformuiv;
typedef  void __stdcall GLBINDFRAGDATALOCATION (GLuint program, GLuint color, const GLchar *name);
GLBINDFRAGDATALOCATION *glBindFragDataLocation;
typedef  GLint __stdcall GLGETFRAGDATALOCATION (GLuint program, const GLchar *name);
GLGETFRAGDATALOCATION *glGetFragDataLocation;
typedef  void __stdcall GLUNIFORM1UI (GLint location, GLuint v0);
GLUNIFORM1UI *glUniform1ui;
typedef  void __stdcall GLUNIFORM2UI (GLint location, GLuint v0, GLuint v1);
GLUNIFORM2UI *glUniform2ui;
typedef  void __stdcall GLUNIFORM3UI (GLint location, GLuint v0, GLuint v1, GLuint v2);
GLUNIFORM3UI *glUniform3ui;
typedef  void __stdcall GLUNIFORM4UI (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
GLUNIFORM4UI *glUniform4ui;
typedef  void __stdcall GLUNIFORM1UIV (GLint location, GLsizei count, const GLuint *value);
GLUNIFORM1UIV *glUniform1uiv;
typedef  void __stdcall GLUNIFORM2UIV (GLint location, GLsizei count, const GLuint *value);
GLUNIFORM2UIV *glUniform2uiv;
typedef  void __stdcall GLUNIFORM3UIV (GLint location, GLsizei count, const GLuint *value);
GLUNIFORM3UIV *glUniform3uiv;
typedef  void __stdcall GLUNIFORM4UIV (GLint location, GLsizei count, const GLuint *value);
GLUNIFORM4UIV *glUniform4uiv;
typedef  void __stdcall GLTEXPARAMETERIIV (GLenum target, GLenum pname, const GLint *params);
GLTEXPARAMETERIIV *glTexParameterIiv;
typedef  void __stdcall GLTEXPARAMETERIUIV (GLenum target, GLenum pname, const GLuint *params);
GLTEXPARAMETERIUIV *glTexParameterIuiv;
typedef  void __stdcall GLGETTEXPARAMETERIIV (GLenum target, GLenum pname, GLint *params);
GLGETTEXPARAMETERIIV *glGetTexParameterIiv;
typedef  void __stdcall GLGETTEXPARAMETERIUIV (GLenum target, GLenum pname, GLuint *params);
GLGETTEXPARAMETERIUIV *glGetTexParameterIuiv;
typedef  void __stdcall GLCLEARBUFFERIV (GLenum buffer, GLint drawbuffer, const GLint *value);
GLCLEARBUFFERIV *glClearBufferiv;
typedef  void __stdcall GLCLEARBUFFERUIV (GLenum buffer, GLint drawbuffer, const GLuint *value);
GLCLEARBUFFERUIV *glClearBufferuiv;
typedef  void __stdcall GLCLEARBUFFERFV (GLenum buffer, GLint drawbuffer, const GLfloat *value);
GLCLEARBUFFERFV *glClearBufferfv;
typedef  void __stdcall GLCLEARBUFFERFI (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
GLCLEARBUFFERFI *glClearBufferfi;
typedef  const GLubyte  __stdcall GLGETSTRINGI (GLenum name, GLuint index);
GLGETSTRINGI *glGetStringi;
typedef  GLboolean __stdcall GLISRENDERBUFFER (GLuint renderbuffer);
GLISRENDERBUFFER *glIsRenderbuffer;
typedef  void __stdcall GLBINDRENDERBUFFER (GLenum target, GLuint renderbuffer);
GLBINDRENDERBUFFER *glBindRenderbuffer;
typedef  void __stdcall GLDELETERENDERBUFFERS (GLsizei n, const GLuint *renderbuffers);
GLDELETERENDERBUFFERS *glDeleteRenderbuffers;
typedef  void __stdcall GLGENRENDERBUFFERS (GLsizei n, GLuint *renderbuffers);
GLGENRENDERBUFFERS *glGenRenderbuffers;
typedef  void __stdcall GLRENDERBUFFERSTORAGE (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
GLRENDERBUFFERSTORAGE *glRenderbufferStorage;
typedef  void __stdcall GLGETRENDERBUFFERPARAMETERIV (GLenum target, GLenum pname, GLint *params);
GLGETRENDERBUFFERPARAMETERIV *glGetRenderbufferParameteriv;
typedef  GLboolean __stdcall GLISFRAMEBUFFER (GLuint framebuffer);
GLISFRAMEBUFFER *glIsFramebuffer;
typedef  void __stdcall GLBINDFRAMEBUFFER (GLenum target, GLuint framebuffer);
GLBINDFRAMEBUFFER *glBindFramebuffer;
typedef  void __stdcall GLDELETEFRAMEBUFFERS (GLsizei n, const GLuint *framebuffers);
GLDELETEFRAMEBUFFERS *glDeleteFramebuffers;
typedef  void __stdcall GLGENFRAMEBUFFERS (GLsizei n, GLuint *framebuffers);
GLGENFRAMEBUFFERS *glGenFramebuffers;
typedef  GLenum __stdcall GLCHECKFRAMEBUFFERSTATUS (GLenum target);
GLCHECKFRAMEBUFFERSTATUS *glCheckFramebufferStatus;
typedef  void __stdcall GLFRAMEBUFFERTEXTURE1D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLFRAMEBUFFERTEXTURE1D *glFramebufferTexture1D;
typedef  void __stdcall GLFRAMEBUFFERTEXTURE2D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLFRAMEBUFFERTEXTURE2D *glFramebufferTexture2D;
typedef  void __stdcall GLFRAMEBUFFERTEXTURE3D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
GLFRAMEBUFFERTEXTURE3D *glFramebufferTexture3D;
typedef  void __stdcall GLFRAMEBUFFERRENDERBUFFER (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
GLFRAMEBUFFERRENDERBUFFER *glFramebufferRenderbuffer;
typedef  void __stdcall GLGETFRAMEBUFFERATTACHMENTPARAMETERIV (GLenum target, GLenum attachment, GLenum pname, GLint *params);
GLGETFRAMEBUFFERATTACHMENTPARAMETERIV *glGetFramebufferAttachmentParameteriv;
typedef  void __stdcall GLGENERATEMIPMAP (GLenum target);
GLGENERATEMIPMAP *glGenerateMipmap;
typedef  void __stdcall GLBLITFRAMEBUFFER (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
GLBLITFRAMEBUFFER *glBlitFramebuffer;
typedef  void __stdcall GLRENDERBUFFERSTORAGEMULTISAMPLE (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
GLRENDERBUFFERSTORAGEMULTISAMPLE *glRenderbufferStorageMultisample;
typedef  void __stdcall GLFRAMEBUFFERTEXTURELAYER (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLFRAMEBUFFERTEXTURELAYER *glFramebufferTextureLayer;
typedef  void  __stdcall GLMAPBUFFERRANGE (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
GLMAPBUFFERRANGE *glMapBufferRange;
typedef  void __stdcall GLFLUSHMAPPEDBUFFERRANGE (GLenum target, GLintptr offset, GLsizeiptr length);
GLFLUSHMAPPEDBUFFERRANGE *glFlushMappedBufferRange;
typedef  void __stdcall GLBINDVERTEXARRAY (GLuint array);
GLBINDVERTEXARRAY *glBindVertexArray;
typedef  void __stdcall GLDELETEVERTEXARRAYS (GLsizei n, const GLuint *arrays);
GLDELETEVERTEXARRAYS *glDeleteVertexArrays;
typedef  void __stdcall GLGENVERTEXARRAYS (GLsizei n, GLuint *arrays);
GLGENVERTEXARRAYS *glGenVertexArrays;
typedef  GLboolean __stdcall GLISVERTEXARRAY (GLuint array);
GLISVERTEXARRAY *glIsVertexArray;
typedef  void __stdcall GLDRAWARRAYSINSTANCED (GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
GLDRAWARRAYSINSTANCED *glDrawArraysInstanced;
typedef  void __stdcall GLDRAWELEMENTSINSTANCED (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount);
GLDRAWELEMENTSINSTANCED *glDrawElementsInstanced;
typedef  void __stdcall GLTEXBUFFER (GLenum target, GLenum internalformat, GLuint buffer);
GLTEXBUFFER *glTexBuffer;
typedef  void __stdcall GLPRIMITIVERESTARTINDEX (GLuint index);
GLPRIMITIVERESTARTINDEX *glPrimitiveRestartIndex;
typedef  void __stdcall GLCOPYBUFFERSUBDATA (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
GLCOPYBUFFERSUBDATA *glCopyBufferSubData;
typedef  void __stdcall GLGETUNIFORMINDICES (GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices);
GLGETUNIFORMINDICES *glGetUniformIndices;
typedef  void __stdcall GLGETACTIVEUNIFORMSIV (GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
GLGETACTIVEUNIFORMSIV *glGetActiveUniformsiv;
typedef  void __stdcall GLGETACTIVEUNIFORMNAME (GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
GLGETACTIVEUNIFORMNAME *glGetActiveUniformName;
typedef  GLuint __stdcall GLGETUNIFORMBLOCKINDEX (GLuint program, const GLchar *uniformBlockName);
GLGETUNIFORMBLOCKINDEX *glGetUniformBlockIndex;
typedef  void __stdcall GLGETACTIVEUNIFORMBLOCKIV (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
GLGETACTIVEUNIFORMBLOCKIV *glGetActiveUniformBlockiv;
typedef  void __stdcall GLGETACTIVEUNIFORMBLOCKNAME (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
GLGETACTIVEUNIFORMBLOCKNAME *glGetActiveUniformBlockName;
typedef  void __stdcall GLUNIFORMBLOCKBINDING (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
GLUNIFORMBLOCKBINDING *glUniformBlockBinding;
typedef  void __stdcall GLDRAWELEMENTSBASEVERTEX (GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
GLDRAWELEMENTSBASEVERTEX *glDrawElementsBaseVertex;
typedef  void __stdcall GLDRAWRANGEELEMENTSBASEVERTEX (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
GLDRAWRANGEELEMENTSBASEVERTEX *glDrawRangeElementsBaseVertex;
typedef  void __stdcall GLDRAWELEMENTSINSTANCEDBASEVERTEX (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
GLDRAWELEMENTSINSTANCEDBASEVERTEX *glDrawElementsInstancedBaseVertex;
typedef  void __stdcall GLMULTIDRAWELEMENTSBASEVERTEX (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex);
GLMULTIDRAWELEMENTSBASEVERTEX *glMultiDrawElementsBaseVertex;
typedef  void __stdcall GLPROVOKINGVERTEX (GLenum mode);
GLPROVOKINGVERTEX *glProvokingVertex;
typedef  GLsync __stdcall GLFENCESYNC (GLenum condition, GLbitfield flags);
GLFENCESYNC *glFenceSync;
typedef  GLboolean __stdcall GLISSYNC (GLsync sync);
GLISSYNC *glIsSync;
typedef  void __stdcall GLDELETESYNC (GLsync sync);
GLDELETESYNC *glDeleteSync;
typedef  GLenum __stdcall GLCLIENTWAITSYNC (GLsync sync, GLbitfield flags, GLuint64 timeout);
GLCLIENTWAITSYNC *glClientWaitSync;
typedef  void __stdcall GLWAITSYNC (GLsync sync, GLbitfield flags, GLuint64 timeout);
GLWAITSYNC *glWaitSync;
typedef  void __stdcall GLGETINTEGER64V (GLenum pname, GLint64 *data);
GLGETINTEGER64V *glGetInteger64v;
typedef  void __stdcall GLGETSYNCIV (GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
GLGETSYNCIV *glGetSynciv;
typedef  void __stdcall GLGETINTEGER64I_V (GLenum target, GLuint index, GLint64 *data);
GLGETINTEGER64I_V *glGetInteger64i_v;
typedef  void __stdcall GLGETBUFFERPARAMETERI64V (GLenum target, GLenum pname, GLint64 *params);
GLGETBUFFERPARAMETERI64V *glGetBufferParameteri64v;
typedef  void __stdcall GLFRAMEBUFFERTEXTURE (GLenum target, GLenum attachment, GLuint texture, GLint level);
GLFRAMEBUFFERTEXTURE *glFramebufferTexture;
typedef  void __stdcall GLTEXIMAGE2DMULTISAMPLE (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLTEXIMAGE2DMULTISAMPLE *glTexImage2DMultisample;
typedef  void __stdcall GLTEXIMAGE3DMULTISAMPLE (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
GLTEXIMAGE3DMULTISAMPLE *glTexImage3DMultisample;
typedef  void __stdcall GLGETMULTISAMPLEFV (GLenum pname, GLuint index, GLfloat *val);
GLGETMULTISAMPLEFV *glGetMultisamplefv;
typedef  void __stdcall GLSAMPLEMASKI (GLuint maskNumber, GLbitfield mask);
GLSAMPLEMASKI *glSampleMaski;
typedef  void __stdcall GLBINDFRAGDATALOCATIONINDEXED (GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
GLBINDFRAGDATALOCATIONINDEXED *glBindFragDataLocationIndexed;
typedef  GLint __stdcall GLGETFRAGDATAINDEX (GLuint program, const GLchar *name);
GLGETFRAGDATAINDEX *glGetFragDataIndex;
typedef  void __stdcall GLGENSAMPLERS (GLsizei count, GLuint *samplers);
GLGENSAMPLERS *glGenSamplers;
typedef  void __stdcall GLDELETESAMPLERS (GLsizei count, const GLuint *samplers);
GLDELETESAMPLERS *glDeleteSamplers;
typedef  GLboolean __stdcall GLISSAMPLER (GLuint sampler);
GLISSAMPLER *glIsSampler;
typedef  void __stdcall GLBINDSAMPLER (GLuint unit, GLuint sampler);
GLBINDSAMPLER *glBindSampler;
typedef  void __stdcall GLSAMPLERPARAMETERI (GLuint sampler, GLenum pname, GLint param);
GLSAMPLERPARAMETERI *glSamplerParameteri;
typedef  void __stdcall GLSAMPLERPARAMETERIV (GLuint sampler, GLenum pname, const GLint *param);
GLSAMPLERPARAMETERIV *glSamplerParameteriv;
typedef  void __stdcall GLSAMPLERPARAMETERF (GLuint sampler, GLenum pname, GLfloat param);
GLSAMPLERPARAMETERF *glSamplerParameterf;
typedef  void __stdcall GLSAMPLERPARAMETERFV (GLuint sampler, GLenum pname, const GLfloat *param);
GLSAMPLERPARAMETERFV *glSamplerParameterfv;
typedef  void __stdcall GLSAMPLERPARAMETERIIV (GLuint sampler, GLenum pname, const GLint *param);
GLSAMPLERPARAMETERIIV *glSamplerParameterIiv;
typedef  void __stdcall GLSAMPLERPARAMETERIUIV (GLuint sampler, GLenum pname, const GLuint *param);
GLSAMPLERPARAMETERIUIV *glSamplerParameterIuiv;
typedef  void __stdcall GLGETSAMPLERPARAMETERIV (GLuint sampler, GLenum pname, GLint *params);
GLGETSAMPLERPARAMETERIV *glGetSamplerParameteriv;
typedef  void __stdcall GLGETSAMPLERPARAMETERIIV (GLuint sampler, GLenum pname, GLint *params);
GLGETSAMPLERPARAMETERIIV *glGetSamplerParameterIiv;
typedef  void __stdcall GLGETSAMPLERPARAMETERFV (GLuint sampler, GLenum pname, GLfloat *params);
GLGETSAMPLERPARAMETERFV *glGetSamplerParameterfv;
typedef  void __stdcall GLGETSAMPLERPARAMETERIUIV (GLuint sampler, GLenum pname, GLuint *params);
GLGETSAMPLERPARAMETERIUIV *glGetSamplerParameterIuiv;
typedef  void __stdcall GLQUERYCOUNTER (GLuint id, GLenum target);
GLQUERYCOUNTER *glQueryCounter;
typedef  void __stdcall GLGETQUERYOBJECTI64V (GLuint id, GLenum pname, GLint64 *params);
GLGETQUERYOBJECTI64V *glGetQueryObjecti64v;
typedef  void __stdcall GLGETQUERYOBJECTUI64V (GLuint id, GLenum pname, GLuint64 *params);
GLGETQUERYOBJECTUI64V *glGetQueryObjectui64v;
typedef  void __stdcall GLVERTEXATTRIBDIVISOR (GLuint index, GLuint divisor);
GLVERTEXATTRIBDIVISOR *glVertexAttribDivisor;
typedef  void __stdcall GLVERTEXATTRIBP1UI (GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLVERTEXATTRIBP1UI *glVertexAttribP1ui;
typedef  void __stdcall GLVERTEXATTRIBP1UIV (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
GLVERTEXATTRIBP1UIV *glVertexAttribP1uiv;
typedef  void __stdcall GLVERTEXATTRIBP2UI (GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLVERTEXATTRIBP2UI *glVertexAttribP2ui;
typedef  void __stdcall GLVERTEXATTRIBP2UIV (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
GLVERTEXATTRIBP2UIV *glVertexAttribP2uiv;
typedef  void __stdcall GLVERTEXATTRIBP3UI (GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLVERTEXATTRIBP3UI *glVertexAttribP3ui;
typedef  void __stdcall GLVERTEXATTRIBP3UIV (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
GLVERTEXATTRIBP3UIV *glVertexAttribP3uiv;
typedef  void __stdcall GLVERTEXATTRIBP4UI (GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLVERTEXATTRIBP4UI *glVertexAttribP4ui;
typedef  void __stdcall GLVERTEXATTRIBP4UIV (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
GLVERTEXATTRIBP4UIV *glVertexAttribP4uiv;
typedef  void __stdcall GLMINSAMPLESHADING (GLfloat value);
GLMINSAMPLESHADING *glMinSampleShading;
typedef  void __stdcall GLBLENDEQUATIONI (GLuint buf, GLenum mode);
GLBLENDEQUATIONI *glBlendEquationi;
typedef  void __stdcall GLBLENDEQUATIONSEPARATEI (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
GLBLENDEQUATIONSEPARATEI *glBlendEquationSeparatei;
typedef  void __stdcall GLBLENDFUNCI (GLuint buf, GLenum src, GLenum dst);
GLBLENDFUNCI *glBlendFunci;
typedef  void __stdcall GLBLENDFUNCSEPARATEI (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
GLBLENDFUNCSEPARATEI *glBlendFuncSeparatei;
typedef  void __stdcall GLDRAWARRAYSINDIRECT (GLenum mode, const void *indirect);
GLDRAWARRAYSINDIRECT *glDrawArraysIndirect;
typedef  void __stdcall GLDRAWELEMENTSINDIRECT (GLenum mode, GLenum type, const void *indirect);
GLDRAWELEMENTSINDIRECT *glDrawElementsIndirect;
typedef  void __stdcall GLUNIFORM1D (GLint location, GLdouble x);
GLUNIFORM1D *glUniform1d;
typedef  void __stdcall GLUNIFORM2D (GLint location, GLdouble x, GLdouble y);
GLUNIFORM2D *glUniform2d;
typedef  void __stdcall GLUNIFORM3D (GLint location, GLdouble x, GLdouble y, GLdouble z);
GLUNIFORM3D *glUniform3d;
typedef  void __stdcall GLUNIFORM4D (GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLUNIFORM4D *glUniform4d;
typedef  void __stdcall GLUNIFORM1DV (GLint location, GLsizei count, const GLdouble *value);
GLUNIFORM1DV *glUniform1dv;
typedef  void __stdcall GLUNIFORM2DV (GLint location, GLsizei count, const GLdouble *value);
GLUNIFORM2DV *glUniform2dv;
typedef  void __stdcall GLUNIFORM3DV (GLint location, GLsizei count, const GLdouble *value);
GLUNIFORM3DV *glUniform3dv;
typedef  void __stdcall GLUNIFORM4DV (GLint location, GLsizei count, const GLdouble *value);
GLUNIFORM4DV *glUniform4dv;
typedef  void __stdcall GLUNIFORMMATRIX2DV (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLUNIFORMMATRIX2DV *glUniformMatrix2dv;
typedef  void __stdcall GLUNIFORMMATRIX3DV (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLUNIFORMMATRIX3DV *glUniformMatrix3dv;
typedef  void __stdcall GLUNIFORMMATRIX4DV (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLUNIFORMMATRIX4DV *glUniformMatrix4dv;
typedef  void __stdcall GLUNIFORMMATRIX2X3DV (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLUNIFORMMATRIX2X3DV *glUniformMatrix2x3dv;
typedef  void __stdcall GLUNIFORMMATRIX2X4DV (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLUNIFORMMATRIX2X4DV *glUniformMatrix2x4dv;
typedef  void __stdcall GLUNIFORMMATRIX3X2DV (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLUNIFORMMATRIX3X2DV *glUniformMatrix3x2dv;
typedef  void __stdcall GLUNIFORMMATRIX3X4DV (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLUNIFORMMATRIX3X4DV *glUniformMatrix3x4dv;
typedef  void __stdcall GLUNIFORMMATRIX4X2DV (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLUNIFORMMATRIX4X2DV *glUniformMatrix4x2dv;
typedef  void __stdcall GLUNIFORMMATRIX4X3DV (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLUNIFORMMATRIX4X3DV *glUniformMatrix4x3dv;
typedef  void __stdcall GLGETUNIFORMDV (GLuint program, GLint location, GLdouble *params);
GLGETUNIFORMDV *glGetUniformdv;
typedef  GLint __stdcall GLGETSUBROUTINEUNIFORMLOCATION (GLuint program, GLenum shadertype, const GLchar *name);
GLGETSUBROUTINEUNIFORMLOCATION *glGetSubroutineUniformLocation;
typedef  GLuint __stdcall GLGETSUBROUTINEINDEX (GLuint program, GLenum shadertype, const GLchar *name);
GLGETSUBROUTINEINDEX *glGetSubroutineIndex;
typedef  void __stdcall GLGETACTIVESUBROUTINEUNIFORMIV (GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
GLGETACTIVESUBROUTINEUNIFORMIV *glGetActiveSubroutineUniformiv;
typedef  void __stdcall GLGETACTIVESUBROUTINEUNIFORMNAME (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
GLGETACTIVESUBROUTINEUNIFORMNAME *glGetActiveSubroutineUniformName;
typedef  void __stdcall GLGETACTIVESUBROUTINENAME (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
GLGETACTIVESUBROUTINENAME *glGetActiveSubroutineName;
typedef  void __stdcall GLUNIFORMSUBROUTINESUIV (GLenum shadertype, GLsizei count, const GLuint *indices);
GLUNIFORMSUBROUTINESUIV *glUniformSubroutinesuiv;
typedef  void __stdcall GLGETUNIFORMSUBROUTINEUIV (GLenum shadertype, GLint location, GLuint *params);
GLGETUNIFORMSUBROUTINEUIV *glGetUniformSubroutineuiv;
typedef  void __stdcall GLGETPROGRAMSTAGEIV (GLuint program, GLenum shadertype, GLenum pname, GLint *values);
GLGETPROGRAMSTAGEIV *glGetProgramStageiv;
typedef  void __stdcall GLPATCHPARAMETERI (GLenum pname, GLint value);
GLPATCHPARAMETERI *glPatchParameteri;
typedef  void __stdcall GLPATCHPARAMETERFV (GLenum pname, const GLfloat *values);
GLPATCHPARAMETERFV *glPatchParameterfv;
typedef  void __stdcall GLBINDTRANSFORMFEEDBACK (GLenum target, GLuint id);
GLBINDTRANSFORMFEEDBACK *glBindTransformFeedback;
typedef  void __stdcall GLDELETETRANSFORMFEEDBACKS (GLsizei n, const GLuint *ids);
GLDELETETRANSFORMFEEDBACKS *glDeleteTransformFeedbacks;
typedef  void __stdcall GLGENTRANSFORMFEEDBACKS (GLsizei n, GLuint *ids);
GLGENTRANSFORMFEEDBACKS *glGenTransformFeedbacks;
typedef  GLboolean __stdcall GLISTRANSFORMFEEDBACK (GLuint id);
GLISTRANSFORMFEEDBACK *glIsTransformFeedback;
typedef  void __stdcall GLPAUSETRANSFORMFEEDBACK (void);
GLPAUSETRANSFORMFEEDBACK *glPauseTransformFeedback;
typedef  void __stdcall GLRESUMETRANSFORMFEEDBACK (void);
GLRESUMETRANSFORMFEEDBACK *glResumeTransformFeedback;
typedef  void __stdcall GLDRAWTRANSFORMFEEDBACK (GLenum mode, GLuint id);
GLDRAWTRANSFORMFEEDBACK *glDrawTransformFeedback;
typedef  void __stdcall GLDRAWTRANSFORMFEEDBACKSTREAM (GLenum mode, GLuint id, GLuint stream);
GLDRAWTRANSFORMFEEDBACKSTREAM *glDrawTransformFeedbackStream;
typedef  void __stdcall GLBEGINQUERYINDEXED (GLenum target, GLuint index, GLuint id);
GLBEGINQUERYINDEXED *glBeginQueryIndexed;
typedef  void __stdcall GLENDQUERYINDEXED (GLenum target, GLuint index);
GLENDQUERYINDEXED *glEndQueryIndexed;
typedef  void __stdcall GLGETQUERYINDEXEDIV (GLenum target, GLuint index, GLenum pname, GLint *params);
GLGETQUERYINDEXEDIV *glGetQueryIndexediv;
typedef  void __stdcall GLRELEASESHADERCOMPILER (void);
GLRELEASESHADERCOMPILER *glReleaseShaderCompiler;
typedef  void __stdcall GLSHADERBINARY (GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length);
GLSHADERBINARY *glShaderBinary;
typedef  void __stdcall GLGETSHADERPRECISIONFORMAT (GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
GLGETSHADERPRECISIONFORMAT *glGetShaderPrecisionFormat;
typedef  void __stdcall GLDEPTHRANGEF (GLfloat n, GLfloat f);
GLDEPTHRANGEF *glDepthRangef;
typedef  void __stdcall GLCLEARDEPTHF (GLfloat d);
GLCLEARDEPTHF *glClearDepthf;
typedef  void __stdcall GLGETPROGRAMBINARY (GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary);
GLGETPROGRAMBINARY *glGetProgramBinary;
typedef  void __stdcall GLPROGRAMBINARY (GLuint program, GLenum binaryFormat, const void *binary, GLsizei length);
GLPROGRAMBINARY *glProgramBinary;
typedef  void __stdcall GLPROGRAMPARAMETERI (GLuint program, GLenum pname, GLint value);
GLPROGRAMPARAMETERI *glProgramParameteri;
typedef  void __stdcall GLUSEPROGRAMSTAGES (GLuint pipeline, GLbitfield stages, GLuint program);
GLUSEPROGRAMSTAGES *glUseProgramStages;
typedef  void __stdcall GLACTIVESHADERPROGRAM (GLuint pipeline, GLuint program);
GLACTIVESHADERPROGRAM *glActiveShaderProgram;
typedef  GLuint __stdcall GLCREATESHADERPROGRAMV (GLenum type, GLsizei count, const GLchar *const*strings);
GLCREATESHADERPROGRAMV *glCreateShaderProgramv;
typedef  void __stdcall GLBINDPROGRAMPIPELINE (GLuint pipeline);
GLBINDPROGRAMPIPELINE *glBindProgramPipeline;
typedef  void __stdcall GLDELETEPROGRAMPIPELINES (GLsizei n, const GLuint *pipelines);
GLDELETEPROGRAMPIPELINES *glDeleteProgramPipelines;
typedef  void __stdcall GLGENPROGRAMPIPELINES (GLsizei n, GLuint *pipelines);
GLGENPROGRAMPIPELINES *glGenProgramPipelines;
typedef  GLboolean __stdcall GLISPROGRAMPIPELINE (GLuint pipeline);
GLISPROGRAMPIPELINE *glIsProgramPipeline;
typedef  void __stdcall GLGETPROGRAMPIPELINEIV (GLuint pipeline, GLenum pname, GLint *params);
GLGETPROGRAMPIPELINEIV *glGetProgramPipelineiv;
typedef  void __stdcall GLPROGRAMUNIFORM1I (GLuint program, GLint location, GLint v0);
GLPROGRAMUNIFORM1I *glProgramUniform1i;
typedef  void __stdcall GLPROGRAMUNIFORM1IV (GLuint program, GLint location, GLsizei count, const GLint *value);
GLPROGRAMUNIFORM1IV *glProgramUniform1iv;
typedef  void __stdcall GLPROGRAMUNIFORM1F (GLuint program, GLint location, GLfloat v0);
GLPROGRAMUNIFORM1F *glProgramUniform1f;
typedef  void __stdcall GLPROGRAMUNIFORM1FV (GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLPROGRAMUNIFORM1FV *glProgramUniform1fv;
typedef  void __stdcall GLPROGRAMUNIFORM1D (GLuint program, GLint location, GLdouble v0);
GLPROGRAMUNIFORM1D *glProgramUniform1d;
typedef  void __stdcall GLPROGRAMUNIFORM1DV (GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLPROGRAMUNIFORM1DV *glProgramUniform1dv;
typedef  void __stdcall GLPROGRAMUNIFORM1UI (GLuint program, GLint location, GLuint v0);
GLPROGRAMUNIFORM1UI *glProgramUniform1ui;
typedef  void __stdcall GLPROGRAMUNIFORM1UIV (GLuint program, GLint location, GLsizei count, const GLuint *value);
GLPROGRAMUNIFORM1UIV *glProgramUniform1uiv;
typedef  void __stdcall GLPROGRAMUNIFORM2I (GLuint program, GLint location, GLint v0, GLint v1);
GLPROGRAMUNIFORM2I *glProgramUniform2i;
typedef  void __stdcall GLPROGRAMUNIFORM2IV (GLuint program, GLint location, GLsizei count, const GLint *value);
GLPROGRAMUNIFORM2IV *glProgramUniform2iv;
typedef  void __stdcall GLPROGRAMUNIFORM2F (GLuint program, GLint location, GLfloat v0, GLfloat v1);
GLPROGRAMUNIFORM2F *glProgramUniform2f;
typedef  void __stdcall GLPROGRAMUNIFORM2FV (GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLPROGRAMUNIFORM2FV *glProgramUniform2fv;
typedef  void __stdcall GLPROGRAMUNIFORM2D (GLuint program, GLint location, GLdouble v0, GLdouble v1);
GLPROGRAMUNIFORM2D *glProgramUniform2d;
typedef  void __stdcall GLPROGRAMUNIFORM2DV (GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLPROGRAMUNIFORM2DV *glProgramUniform2dv;
typedef  void __stdcall GLPROGRAMUNIFORM2UI (GLuint program, GLint location, GLuint v0, GLuint v1);
GLPROGRAMUNIFORM2UI *glProgramUniform2ui;
typedef  void __stdcall GLPROGRAMUNIFORM2UIV (GLuint program, GLint location, GLsizei count, const GLuint *value);
GLPROGRAMUNIFORM2UIV *glProgramUniform2uiv;
typedef  void __stdcall GLPROGRAMUNIFORM3I (GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
GLPROGRAMUNIFORM3I *glProgramUniform3i;
typedef  void __stdcall GLPROGRAMUNIFORM3IV (GLuint program, GLint location, GLsizei count, const GLint *value);
GLPROGRAMUNIFORM3IV *glProgramUniform3iv;
typedef  void __stdcall GLPROGRAMUNIFORM3F (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
GLPROGRAMUNIFORM3F *glProgramUniform3f;
typedef  void __stdcall GLPROGRAMUNIFORM3FV (GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLPROGRAMUNIFORM3FV *glProgramUniform3fv;
typedef  void __stdcall GLPROGRAMUNIFORM3D (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
GLPROGRAMUNIFORM3D *glProgramUniform3d;
typedef  void __stdcall GLPROGRAMUNIFORM3DV (GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLPROGRAMUNIFORM3DV *glProgramUniform3dv;
typedef  void __stdcall GLPROGRAMUNIFORM3UI (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
GLPROGRAMUNIFORM3UI *glProgramUniform3ui;
typedef  void __stdcall GLPROGRAMUNIFORM3UIV (GLuint program, GLint location, GLsizei count, const GLuint *value);
GLPROGRAMUNIFORM3UIV *glProgramUniform3uiv;
typedef  void __stdcall GLPROGRAMUNIFORM4I (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
GLPROGRAMUNIFORM4I *glProgramUniform4i;
typedef  void __stdcall GLPROGRAMUNIFORM4IV (GLuint program, GLint location, GLsizei count, const GLint *value);
GLPROGRAMUNIFORM4IV *glProgramUniform4iv;
typedef  void __stdcall GLPROGRAMUNIFORM4F (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
GLPROGRAMUNIFORM4F *glProgramUniform4f;
typedef  void __stdcall GLPROGRAMUNIFORM4FV (GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLPROGRAMUNIFORM4FV *glProgramUniform4fv;
typedef  void __stdcall GLPROGRAMUNIFORM4D (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
GLPROGRAMUNIFORM4D *glProgramUniform4d;
typedef  void __stdcall GLPROGRAMUNIFORM4DV (GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLPROGRAMUNIFORM4DV *glProgramUniform4dv;
typedef  void __stdcall GLPROGRAMUNIFORM4UI (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
GLPROGRAMUNIFORM4UI *glProgramUniform4ui;
typedef  void __stdcall GLPROGRAMUNIFORM4UIV (GLuint program, GLint location, GLsizei count, const GLuint *value);
GLPROGRAMUNIFORM4UIV *glProgramUniform4uiv;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX2FV (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLPROGRAMUNIFORMMATRIX2FV *glProgramUniformMatrix2fv;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX3FV (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLPROGRAMUNIFORMMATRIX3FV *glProgramUniformMatrix3fv;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX4FV (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLPROGRAMUNIFORMMATRIX4FV *glProgramUniformMatrix4fv;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX2DV (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLPROGRAMUNIFORMMATRIX2DV *glProgramUniformMatrix2dv;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX3DV (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLPROGRAMUNIFORMMATRIX3DV *glProgramUniformMatrix3dv;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX4DV (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLPROGRAMUNIFORMMATRIX4DV *glProgramUniformMatrix4dv;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX2X3FV (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLPROGRAMUNIFORMMATRIX2X3FV *glProgramUniformMatrix2x3fv;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX3X2FV (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLPROGRAMUNIFORMMATRIX3X2FV *glProgramUniformMatrix3x2fv;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX2X4FV (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLPROGRAMUNIFORMMATRIX2X4FV *glProgramUniformMatrix2x4fv;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX4X2FV (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLPROGRAMUNIFORMMATRIX4X2FV *glProgramUniformMatrix4x2fv;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX3X4FV (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLPROGRAMUNIFORMMATRIX3X4FV *glProgramUniformMatrix3x4fv;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX4X3FV (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLPROGRAMUNIFORMMATRIX4X3FV *glProgramUniformMatrix4x3fv;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX2X3DV (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLPROGRAMUNIFORMMATRIX2X3DV *glProgramUniformMatrix2x3dv;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX3X2DV (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLPROGRAMUNIFORMMATRIX3X2DV *glProgramUniformMatrix3x2dv;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX2X4DV (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLPROGRAMUNIFORMMATRIX2X4DV *glProgramUniformMatrix2x4dv;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX4X2DV (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLPROGRAMUNIFORMMATRIX4X2DV *glProgramUniformMatrix4x2dv;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX3X4DV (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLPROGRAMUNIFORMMATRIX3X4DV *glProgramUniformMatrix3x4dv;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX4X3DV (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLPROGRAMUNIFORMMATRIX4X3DV *glProgramUniformMatrix4x3dv;
typedef  void __stdcall GLVALIDATEPROGRAMPIPELINE (GLuint pipeline);
GLVALIDATEPROGRAMPIPELINE *glValidateProgramPipeline;
typedef  void __stdcall GLGETPROGRAMPIPELINEINFOLOG (GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GLGETPROGRAMPIPELINEINFOLOG *glGetProgramPipelineInfoLog;
typedef  void __stdcall GLVERTEXATTRIBL1D (GLuint index, GLdouble x);
GLVERTEXATTRIBL1D *glVertexAttribL1d;
typedef  void __stdcall GLVERTEXATTRIBL2D (GLuint index, GLdouble x, GLdouble y);
GLVERTEXATTRIBL2D *glVertexAttribL2d;
typedef  void __stdcall GLVERTEXATTRIBL3D (GLuint index, GLdouble x, GLdouble y, GLdouble z);
GLVERTEXATTRIBL3D *glVertexAttribL3d;
typedef  void __stdcall GLVERTEXATTRIBL4D (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLVERTEXATTRIBL4D *glVertexAttribL4d;
typedef  void __stdcall GLVERTEXATTRIBL1DV (GLuint index, const GLdouble *v);
GLVERTEXATTRIBL1DV *glVertexAttribL1dv;
typedef  void __stdcall GLVERTEXATTRIBL2DV (GLuint index, const GLdouble *v);
GLVERTEXATTRIBL2DV *glVertexAttribL2dv;
typedef  void __stdcall GLVERTEXATTRIBL3DV (GLuint index, const GLdouble *v);
GLVERTEXATTRIBL3DV *glVertexAttribL3dv;
typedef  void __stdcall GLVERTEXATTRIBL4DV (GLuint index, const GLdouble *v);
GLVERTEXATTRIBL4DV *glVertexAttribL4dv;
typedef  void __stdcall GLVERTEXATTRIBLPOINTER (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
GLVERTEXATTRIBLPOINTER *glVertexAttribLPointer;
typedef  void __stdcall GLGETVERTEXATTRIBLDV (GLuint index, GLenum pname, GLdouble *params);
GLGETVERTEXATTRIBLDV *glGetVertexAttribLdv;
typedef  void __stdcall GLVIEWPORTARRAYV (GLuint first, GLsizei count, const GLfloat *v);
GLVIEWPORTARRAYV *glViewportArrayv;
typedef  void __stdcall GLVIEWPORTINDEXEDF (GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
GLVIEWPORTINDEXEDF *glViewportIndexedf;
typedef  void __stdcall GLVIEWPORTINDEXEDFV (GLuint index, const GLfloat *v);
GLVIEWPORTINDEXEDFV *glViewportIndexedfv;
typedef  void __stdcall GLSCISSORARRAYV (GLuint first, GLsizei count, const GLint *v);
GLSCISSORARRAYV *glScissorArrayv;
typedef  void __stdcall GLSCISSORINDEXED (GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
GLSCISSORINDEXED *glScissorIndexed;
typedef  void __stdcall GLSCISSORINDEXEDV (GLuint index, const GLint *v);
GLSCISSORINDEXEDV *glScissorIndexedv;
typedef  void __stdcall GLDEPTHRANGEARRAYV (GLuint first, GLsizei count, const GLdouble *v);
GLDEPTHRANGEARRAYV *glDepthRangeArrayv;
typedef  void __stdcall GLDEPTHRANGEINDEXED (GLuint index, GLdouble n, GLdouble f);
GLDEPTHRANGEINDEXED *glDepthRangeIndexed;
typedef  void __stdcall GLGETFLOATI_V (GLenum target, GLuint index, GLfloat *data);
GLGETFLOATI_V *glGetFloati_v;
typedef  void __stdcall GLGETDOUBLEI_V (GLenum target, GLuint index, GLdouble *data);
GLGETDOUBLEI_V *glGetDoublei_v;
typedef  void __stdcall GLDRAWARRAYSINSTANCEDBASEINSTANCE (GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
GLDRAWARRAYSINSTANCEDBASEINSTANCE *glDrawArraysInstancedBaseInstance;
typedef  void __stdcall GLDRAWELEMENTSINSTANCEDBASEINSTANCE (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance);
GLDRAWELEMENTSINSTANCEDBASEINSTANCE *glDrawElementsInstancedBaseInstance;
typedef  void __stdcall GLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCE (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
GLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCE *glDrawElementsInstancedBaseVertexBaseInstance;
typedef  void __stdcall GLGETINTERNALFORMATIV (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params);
GLGETINTERNALFORMATIV *glGetInternalformativ;
typedef  void __stdcall GLGETACTIVEATOMICCOUNTERBUFFERIV (GLuint program, GLuint bufferIndex, GLenum pname, GLint *params);
GLGETACTIVEATOMICCOUNTERBUFFERIV *glGetActiveAtomicCounterBufferiv;
typedef  void __stdcall GLBINDIMAGETEXTURE (GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
GLBINDIMAGETEXTURE *glBindImageTexture;
typedef  void __stdcall GLMEMORYBARRIER (GLbitfield barriers);
GLMEMORYBARRIER *glMemoryBarrier;
typedef  void __stdcall GLTEXSTORAGE1D (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
GLTEXSTORAGE1D *glTexStorage1D;
typedef  void __stdcall GLTEXSTORAGE2D (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
GLTEXSTORAGE2D *glTexStorage2D;
typedef  void __stdcall GLTEXSTORAGE3D (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
GLTEXSTORAGE3D *glTexStorage3D;
typedef  void __stdcall GLDRAWTRANSFORMFEEDBACKINSTANCED (GLenum mode, GLuint id, GLsizei instancecount);
GLDRAWTRANSFORMFEEDBACKINSTANCED *glDrawTransformFeedbackInstanced;
typedef  void __stdcall GLDRAWTRANSFORMFEEDBACKSTREAMINSTANCED (GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
GLDRAWTRANSFORMFEEDBACKSTREAMINSTANCED *glDrawTransformFeedbackStreamInstanced;
typedef  void __stdcall GLCLEARBUFFERDATA (GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data);
GLCLEARBUFFERDATA *glClearBufferData;
typedef  void __stdcall GLCLEARBUFFERSUBDATA (GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
GLCLEARBUFFERSUBDATA *glClearBufferSubData;
typedef  void __stdcall GLDISPATCHCOMPUTE (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
GLDISPATCHCOMPUTE *glDispatchCompute;
typedef  void __stdcall GLDISPATCHCOMPUTEINDIRECT (GLintptr indirect);
GLDISPATCHCOMPUTEINDIRECT *glDispatchComputeIndirect;
typedef  void __stdcall GLCOPYIMAGESUBDATA (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
GLCOPYIMAGESUBDATA *glCopyImageSubData;
typedef  void __stdcall GLFRAMEBUFFERPARAMETERI (GLenum target, GLenum pname, GLint param);
GLFRAMEBUFFERPARAMETERI *glFramebufferParameteri;
typedef  void __stdcall GLGETFRAMEBUFFERPARAMETERIV (GLenum target, GLenum pname, GLint *params);
GLGETFRAMEBUFFERPARAMETERIV *glGetFramebufferParameteriv;
typedef  void __stdcall GLGETINTERNALFORMATI64V (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 *params);
GLGETINTERNALFORMATI64V *glGetInternalformati64v;
typedef  void __stdcall GLINVALIDATETEXSUBIMAGE (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
GLINVALIDATETEXSUBIMAGE *glInvalidateTexSubImage;
typedef  void __stdcall GLINVALIDATETEXIMAGE (GLuint texture, GLint level);
GLINVALIDATETEXIMAGE *glInvalidateTexImage;
typedef  void __stdcall GLINVALIDATEBUFFERSUBDATA (GLuint buffer, GLintptr offset, GLsizeiptr length);
GLINVALIDATEBUFFERSUBDATA *glInvalidateBufferSubData;
typedef  void __stdcall GLINVALIDATEBUFFERDATA (GLuint buffer);
GLINVALIDATEBUFFERDATA *glInvalidateBufferData;
typedef  void __stdcall GLINVALIDATEFRAMEBUFFER (GLenum target, GLsizei numAttachments, const GLenum *attachments);
GLINVALIDATEFRAMEBUFFER *glInvalidateFramebuffer;
typedef  void __stdcall GLINVALIDATESUBFRAMEBUFFER (GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
GLINVALIDATESUBFRAMEBUFFER *glInvalidateSubFramebuffer;
typedef  void __stdcall GLMULTIDRAWARRAYSINDIRECT (GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride);
GLMULTIDRAWARRAYSINDIRECT *glMultiDrawArraysIndirect;
typedef  void __stdcall GLMULTIDRAWELEMENTSINDIRECT (GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride);
GLMULTIDRAWELEMENTSINDIRECT *glMultiDrawElementsIndirect;
typedef  void __stdcall GLGETPROGRAMINTERFACEIV (GLuint program, GLenum programInterface, GLenum pname, GLint *params);
GLGETPROGRAMINTERFACEIV *glGetProgramInterfaceiv;
typedef  GLuint __stdcall GLGETPROGRAMRESOURCEINDEX (GLuint program, GLenum programInterface, const GLchar *name);
GLGETPROGRAMRESOURCEINDEX *glGetProgramResourceIndex;
typedef  void __stdcall GLGETPROGRAMRESOURCENAME (GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
GLGETPROGRAMRESOURCENAME *glGetProgramResourceName;
typedef  void __stdcall GLGETPROGRAMRESOURCEIV (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLint *params);
GLGETPROGRAMRESOURCEIV *glGetProgramResourceiv;
typedef  GLint __stdcall GLGETPROGRAMRESOURCELOCATION (GLuint program, GLenum programInterface, const GLchar *name);
GLGETPROGRAMRESOURCELOCATION *glGetProgramResourceLocation;
typedef  GLint __stdcall GLGETPROGRAMRESOURCELOCATIONINDEX (GLuint program, GLenum programInterface, const GLchar *name);
GLGETPROGRAMRESOURCELOCATIONINDEX *glGetProgramResourceLocationIndex;
typedef  void __stdcall GLSHADERSTORAGEBLOCKBINDING (GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
GLSHADERSTORAGEBLOCKBINDING *glShaderStorageBlockBinding;
typedef  void __stdcall GLTEXBUFFERRANGE (GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLTEXBUFFERRANGE *glTexBufferRange;
typedef  void __stdcall GLTEXSTORAGE2DMULTISAMPLE (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLTEXSTORAGE2DMULTISAMPLE *glTexStorage2DMultisample;
typedef  void __stdcall GLTEXSTORAGE3DMULTISAMPLE (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
GLTEXSTORAGE3DMULTISAMPLE *glTexStorage3DMultisample;
typedef  void __stdcall GLTEXTUREVIEW (GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
GLTEXTUREVIEW *glTextureView;
typedef  void __stdcall GLBINDVERTEXBUFFER (GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
GLBINDVERTEXBUFFER *glBindVertexBuffer;
typedef  void __stdcall GLVERTEXATTRIBFORMAT (GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
GLVERTEXATTRIBFORMAT *glVertexAttribFormat;
typedef  void __stdcall GLVERTEXATTRIBIFORMAT (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLVERTEXATTRIBIFORMAT *glVertexAttribIFormat;
typedef  void __stdcall GLVERTEXATTRIBLFORMAT (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLVERTEXATTRIBLFORMAT *glVertexAttribLFormat;
typedef  void __stdcall GLVERTEXATTRIBBINDING (GLuint attribindex, GLuint bindingindex);
GLVERTEXATTRIBBINDING *glVertexAttribBinding;
typedef  void __stdcall GLVERTEXBINDINGDIVISOR (GLuint bindingindex, GLuint divisor);
GLVERTEXBINDINGDIVISOR *glVertexBindingDivisor;
typedef  void __stdcall GLDEBUGMESSAGECONTROL (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
GLDEBUGMESSAGECONTROL *glDebugMessageControl;
typedef  void __stdcall GLDEBUGMESSAGEINSERT (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
GLDEBUGMESSAGEINSERT *glDebugMessageInsert;
typedef  void __stdcall GLDEBUGMESSAGECALLBACK (GLDEBUGPROC callback, const void *userParam);
GLDEBUGMESSAGECALLBACK *glDebugMessageCallback;
typedef  GLuint __stdcall GLGETDEBUGMESSAGELOG (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
GLGETDEBUGMESSAGELOG *glGetDebugMessageLog;
typedef  void __stdcall GLPUSHDEBUGGROUP (GLenum source, GLuint id, GLsizei length, const GLchar *message);
GLPUSHDEBUGGROUP *glPushDebugGroup;
typedef  void __stdcall GLPOPDEBUGGROUP (void);
GLPOPDEBUGGROUP *glPopDebugGroup;
typedef  void __stdcall GLOBJECTLABEL (GLenum identifier, GLuint name, GLsizei length, const GLchar *label);
GLOBJECTLABEL *glObjectLabel;
typedef  void __stdcall GLGETOBJECTLABEL (GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label);
GLGETOBJECTLABEL *glGetObjectLabel;
typedef  void __stdcall GLOBJECTPTRLABEL (const void *ptr, GLsizei length, const GLchar *label);
GLOBJECTPTRLABEL *glObjectPtrLabel;
typedef  void __stdcall GLGETOBJECTPTRLABEL (const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label);
GLGETOBJECTPTRLABEL *glGetObjectPtrLabel;
typedef  void __stdcall GLBUFFERSTORAGE (GLenum target, GLsizeiptr size, const void *data, GLbitfield flags);
GLBUFFERSTORAGE *glBufferStorage;
typedef  void __stdcall GLCLEARTEXIMAGE (GLuint texture, GLint level, GLenum format, GLenum type, const void *data);
GLCLEARTEXIMAGE *glClearTexImage;
typedef  void __stdcall GLCLEARTEXSUBIMAGE (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data);
GLCLEARTEXSUBIMAGE *glClearTexSubImage;
typedef  void __stdcall GLBINDBUFFERSBASE (GLenum target, GLuint first, GLsizei count, const GLuint *buffers);
GLBINDBUFFERSBASE *glBindBuffersBase;
typedef  void __stdcall GLBINDBUFFERSRANGE (GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes);
GLBINDBUFFERSRANGE *glBindBuffersRange;
typedef  void __stdcall GLBINDTEXTURES (GLuint first, GLsizei count, const GLuint *textures);
GLBINDTEXTURES *glBindTextures;
typedef  void __stdcall GLBINDSAMPLERS (GLuint first, GLsizei count, const GLuint *samplers);
GLBINDSAMPLERS *glBindSamplers;
typedef  void __stdcall GLBINDIMAGETEXTURES (GLuint first, GLsizei count, const GLuint *textures);
GLBINDIMAGETEXTURES *glBindImageTextures;
typedef  void __stdcall GLBINDVERTEXBUFFERS (GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
GLBINDVERTEXBUFFERS *glBindVertexBuffers;
typedef  void __stdcall GLCLIPCONTROL (GLenum origin, GLenum depth);
GLCLIPCONTROL *glClipControl;
typedef  void __stdcall GLCREATETRANSFORMFEEDBACKS (GLsizei n, GLuint *ids);
GLCREATETRANSFORMFEEDBACKS *glCreateTransformFeedbacks;
typedef  void __stdcall GLTRANSFORMFEEDBACKBUFFERBASE (GLuint xfb, GLuint index, GLuint buffer);
GLTRANSFORMFEEDBACKBUFFERBASE *glTransformFeedbackBufferBase;
typedef  void __stdcall GLTRANSFORMFEEDBACKBUFFERRANGE (GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLTRANSFORMFEEDBACKBUFFERRANGE *glTransformFeedbackBufferRange;
typedef  void __stdcall GLGETTRANSFORMFEEDBACKIV (GLuint xfb, GLenum pname, GLint *param);
GLGETTRANSFORMFEEDBACKIV *glGetTransformFeedbackiv;
typedef  void __stdcall GLGETTRANSFORMFEEDBACKI_V (GLuint xfb, GLenum pname, GLuint index, GLint *param);
GLGETTRANSFORMFEEDBACKI_V *glGetTransformFeedbacki_v;
typedef  void __stdcall GLGETTRANSFORMFEEDBACKI64_V (GLuint xfb, GLenum pname, GLuint index, GLint64 *param);
GLGETTRANSFORMFEEDBACKI64_V *glGetTransformFeedbacki64_v;
typedef  void __stdcall GLCREATEBUFFERS (GLsizei n, GLuint *buffers);
GLCREATEBUFFERS *glCreateBuffers;
typedef  void __stdcall GLNAMEDBUFFERSTORAGE (GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
GLNAMEDBUFFERSTORAGE *glNamedBufferStorage;
typedef  void __stdcall GLNAMEDBUFFERDATA (GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
GLNAMEDBUFFERDATA *glNamedBufferData;
typedef  void __stdcall GLNAMEDBUFFERSUBDATA (GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
GLNAMEDBUFFERSUBDATA *glNamedBufferSubData;
typedef  void __stdcall GLCOPYNAMEDBUFFERSUBDATA (GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
GLCOPYNAMEDBUFFERSUBDATA *glCopyNamedBufferSubData;
typedef  void __stdcall GLCLEARNAMEDBUFFERDATA (GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
GLCLEARNAMEDBUFFERDATA *glClearNamedBufferData;
typedef  void __stdcall GLCLEARNAMEDBUFFERSUBDATA (GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
GLCLEARNAMEDBUFFERSUBDATA *glClearNamedBufferSubData;
typedef  void  __stdcall GLMAPNAMEDBUFFER (GLuint buffer, GLenum access);
GLMAPNAMEDBUFFER *glMapNamedBuffer;
typedef  void  __stdcall GLMAPNAMEDBUFFERRANGE (GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
GLMAPNAMEDBUFFERRANGE *glMapNamedBufferRange;
typedef  GLboolean __stdcall GLUNMAPNAMEDBUFFER (GLuint buffer);
GLUNMAPNAMEDBUFFER *glUnmapNamedBuffer;
typedef  void __stdcall GLFLUSHMAPPEDNAMEDBUFFERRANGE (GLuint buffer, GLintptr offset, GLsizeiptr length);
GLFLUSHMAPPEDNAMEDBUFFERRANGE *glFlushMappedNamedBufferRange;
typedef  void __stdcall GLGETNAMEDBUFFERPARAMETERIV (GLuint buffer, GLenum pname, GLint *params);
GLGETNAMEDBUFFERPARAMETERIV *glGetNamedBufferParameteriv;
typedef  void __stdcall GLGETNAMEDBUFFERPARAMETERI64V (GLuint buffer, GLenum pname, GLint64 *params);
GLGETNAMEDBUFFERPARAMETERI64V *glGetNamedBufferParameteri64v;
typedef  void __stdcall GLGETNAMEDBUFFERPOINTERV (GLuint buffer, GLenum pname, void **params);
GLGETNAMEDBUFFERPOINTERV *glGetNamedBufferPointerv;
typedef  void __stdcall GLGETNAMEDBUFFERSUBDATA (GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
GLGETNAMEDBUFFERSUBDATA *glGetNamedBufferSubData;
typedef  void __stdcall GLCREATEFRAMEBUFFERS (GLsizei n, GLuint *framebuffers);
GLCREATEFRAMEBUFFERS *glCreateFramebuffers;
typedef  void __stdcall GLNAMEDFRAMEBUFFERRENDERBUFFER (GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
GLNAMEDFRAMEBUFFERRENDERBUFFER *glNamedFramebufferRenderbuffer;
typedef  void __stdcall GLNAMEDFRAMEBUFFERPARAMETERI (GLuint framebuffer, GLenum pname, GLint param);
GLNAMEDFRAMEBUFFERPARAMETERI *glNamedFramebufferParameteri;
typedef  void __stdcall GLNAMEDFRAMEBUFFERTEXTURE (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
GLNAMEDFRAMEBUFFERTEXTURE *glNamedFramebufferTexture;
typedef  void __stdcall GLNAMEDFRAMEBUFFERTEXTURELAYER (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLNAMEDFRAMEBUFFERTEXTURELAYER *glNamedFramebufferTextureLayer;
typedef  void __stdcall GLNAMEDFRAMEBUFFERDRAWBUFFER (GLuint framebuffer, GLenum buf);
GLNAMEDFRAMEBUFFERDRAWBUFFER *glNamedFramebufferDrawBuffer;
typedef  void __stdcall GLNAMEDFRAMEBUFFERDRAWBUFFERS (GLuint framebuffer, GLsizei n, const GLenum *bufs);
GLNAMEDFRAMEBUFFERDRAWBUFFERS *glNamedFramebufferDrawBuffers;
typedef  void __stdcall GLNAMEDFRAMEBUFFERREADBUFFER (GLuint framebuffer, GLenum src);
GLNAMEDFRAMEBUFFERREADBUFFER *glNamedFramebufferReadBuffer;
typedef  void __stdcall GLINVALIDATENAMEDFRAMEBUFFERDATA (GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments);
GLINVALIDATENAMEDFRAMEBUFFERDATA *glInvalidateNamedFramebufferData;
typedef  void __stdcall GLINVALIDATENAMEDFRAMEBUFFERSUBDATA (GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
GLINVALIDATENAMEDFRAMEBUFFERSUBDATA *glInvalidateNamedFramebufferSubData;
typedef  void __stdcall GLCLEARNAMEDFRAMEBUFFERIV (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value);
GLCLEARNAMEDFRAMEBUFFERIV *glClearNamedFramebufferiv;
typedef  void __stdcall GLCLEARNAMEDFRAMEBUFFERUIV (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value);
GLCLEARNAMEDFRAMEBUFFERUIV *glClearNamedFramebufferuiv;
typedef  void __stdcall GLCLEARNAMEDFRAMEBUFFERFV (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value);
GLCLEARNAMEDFRAMEBUFFERFV *glClearNamedFramebufferfv;
typedef  void __stdcall GLCLEARNAMEDFRAMEBUFFERFI (GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
GLCLEARNAMEDFRAMEBUFFERFI *glClearNamedFramebufferfi;
typedef  void __stdcall GLBLITNAMEDFRAMEBUFFER (GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
GLBLITNAMEDFRAMEBUFFER *glBlitNamedFramebuffer;
typedef  GLenum __stdcall GLCHECKNAMEDFRAMEBUFFERSTATUS (GLuint framebuffer, GLenum target);
GLCHECKNAMEDFRAMEBUFFERSTATUS *glCheckNamedFramebufferStatus;
typedef  void __stdcall GLGETNAMEDFRAMEBUFFERPARAMETERIV (GLuint framebuffer, GLenum pname, GLint *param);
GLGETNAMEDFRAMEBUFFERPARAMETERIV *glGetNamedFramebufferParameteriv;
typedef  void __stdcall GLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIV (GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
GLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIV *glGetNamedFramebufferAttachmentParameteriv;
typedef  void __stdcall GLCREATERENDERBUFFERS (GLsizei n, GLuint *renderbuffers);
GLCREATERENDERBUFFERS *glCreateRenderbuffers;
typedef  void __stdcall GLNAMEDRENDERBUFFERSTORAGE (GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
GLNAMEDRENDERBUFFERSTORAGE *glNamedRenderbufferStorage;
typedef  void __stdcall GLNAMEDRENDERBUFFERSTORAGEMULTISAMPLE (GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
GLNAMEDRENDERBUFFERSTORAGEMULTISAMPLE *glNamedRenderbufferStorageMultisample;
typedef  void __stdcall GLGETNAMEDRENDERBUFFERPARAMETERIV (GLuint renderbuffer, GLenum pname, GLint *params);
GLGETNAMEDRENDERBUFFERPARAMETERIV *glGetNamedRenderbufferParameteriv;
typedef  void __stdcall GLCREATETEXTURES (GLenum target, GLsizei n, GLuint *textures);
GLCREATETEXTURES *glCreateTextures;
typedef  void __stdcall GLTEXTUREBUFFER (GLuint texture, GLenum internalformat, GLuint buffer);
GLTEXTUREBUFFER *glTextureBuffer;
typedef  void __stdcall GLTEXTUREBUFFERRANGE (GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLTEXTUREBUFFERRANGE *glTextureBufferRange;
typedef  void __stdcall GLTEXTURESTORAGE1D (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
GLTEXTURESTORAGE1D *glTextureStorage1D;
typedef  void __stdcall GLTEXTURESTORAGE2D (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
GLTEXTURESTORAGE2D *glTextureStorage2D;
typedef  void __stdcall GLTEXTURESTORAGE3D (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
GLTEXTURESTORAGE3D *glTextureStorage3D;
typedef  void __stdcall GLTEXTURESTORAGE2DMULTISAMPLE (GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLTEXTURESTORAGE2DMULTISAMPLE *glTextureStorage2DMultisample;
typedef  void __stdcall GLTEXTURESTORAGE3DMULTISAMPLE (GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
GLTEXTURESTORAGE3DMULTISAMPLE *glTextureStorage3DMultisample;
typedef  void __stdcall GLTEXTURESUBIMAGE1D (GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
GLTEXTURESUBIMAGE1D *glTextureSubImage1D;
typedef  void __stdcall GLTEXTURESUBIMAGE2D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
GLTEXTURESUBIMAGE2D *glTextureSubImage2D;
typedef  void __stdcall GLTEXTURESUBIMAGE3D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
GLTEXTURESUBIMAGE3D *glTextureSubImage3D;
typedef  void __stdcall GLCOMPRESSEDTEXTURESUBIMAGE1D (GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
GLCOMPRESSEDTEXTURESUBIMAGE1D *glCompressedTextureSubImage1D;
typedef  void __stdcall GLCOMPRESSEDTEXTURESUBIMAGE2D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
GLCOMPRESSEDTEXTURESUBIMAGE2D *glCompressedTextureSubImage2D;
typedef  void __stdcall GLCOMPRESSEDTEXTURESUBIMAGE3D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
GLCOMPRESSEDTEXTURESUBIMAGE3D *glCompressedTextureSubImage3D;
typedef  void __stdcall GLCOPYTEXTURESUBIMAGE1D (GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
GLCOPYTEXTURESUBIMAGE1D *glCopyTextureSubImage1D;
typedef  void __stdcall GLCOPYTEXTURESUBIMAGE2D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLCOPYTEXTURESUBIMAGE2D *glCopyTextureSubImage2D;
typedef  void __stdcall GLCOPYTEXTURESUBIMAGE3D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLCOPYTEXTURESUBIMAGE3D *glCopyTextureSubImage3D;
typedef  void __stdcall GLTEXTUREPARAMETERF (GLuint texture, GLenum pname, GLfloat param);
GLTEXTUREPARAMETERF *glTextureParameterf;
typedef  void __stdcall GLTEXTUREPARAMETERFV (GLuint texture, GLenum pname, const GLfloat *param);
GLTEXTUREPARAMETERFV *glTextureParameterfv;
typedef  void __stdcall GLTEXTUREPARAMETERI (GLuint texture, GLenum pname, GLint param);
GLTEXTUREPARAMETERI *glTextureParameteri;
typedef  void __stdcall GLTEXTUREPARAMETERIIV (GLuint texture, GLenum pname, const GLint *params);
GLTEXTUREPARAMETERIIV *glTextureParameterIiv;
typedef  void __stdcall GLTEXTUREPARAMETERIUIV (GLuint texture, GLenum pname, const GLuint *params);
GLTEXTUREPARAMETERIUIV *glTextureParameterIuiv;
typedef  void __stdcall GLTEXTUREPARAMETERIV (GLuint texture, GLenum pname, const GLint *param);
GLTEXTUREPARAMETERIV *glTextureParameteriv;
typedef  void __stdcall GLGENERATETEXTUREMIPMAP (GLuint texture);
GLGENERATETEXTUREMIPMAP *glGenerateTextureMipmap;
typedef  void __stdcall GLBINDTEXTUREUNIT (GLuint unit, GLuint texture);
GLBINDTEXTUREUNIT *glBindTextureUnit;
typedef  void __stdcall GLGETTEXTUREIMAGE (GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
GLGETTEXTUREIMAGE *glGetTextureImage;
typedef  void __stdcall GLGETCOMPRESSEDTEXTUREIMAGE (GLuint texture, GLint level, GLsizei bufSize, void *pixels);
GLGETCOMPRESSEDTEXTUREIMAGE *glGetCompressedTextureImage;
typedef  void __stdcall GLGETTEXTURELEVELPARAMETERFV (GLuint texture, GLint level, GLenum pname, GLfloat *params);
GLGETTEXTURELEVELPARAMETERFV *glGetTextureLevelParameterfv;
typedef  void __stdcall GLGETTEXTURELEVELPARAMETERIV (GLuint texture, GLint level, GLenum pname, GLint *params);
GLGETTEXTURELEVELPARAMETERIV *glGetTextureLevelParameteriv;
typedef  void __stdcall GLGETTEXTUREPARAMETERFV (GLuint texture, GLenum pname, GLfloat *params);
GLGETTEXTUREPARAMETERFV *glGetTextureParameterfv;
typedef  void __stdcall GLGETTEXTUREPARAMETERIIV (GLuint texture, GLenum pname, GLint *params);
GLGETTEXTUREPARAMETERIIV *glGetTextureParameterIiv;
typedef  void __stdcall GLGETTEXTUREPARAMETERIUIV (GLuint texture, GLenum pname, GLuint *params);
GLGETTEXTUREPARAMETERIUIV *glGetTextureParameterIuiv;
typedef  void __stdcall GLGETTEXTUREPARAMETERIV (GLuint texture, GLenum pname, GLint *params);
GLGETTEXTUREPARAMETERIV *glGetTextureParameteriv;
typedef  void __stdcall GLCREATEVERTEXARRAYS (GLsizei n, GLuint *arrays);
GLCREATEVERTEXARRAYS *glCreateVertexArrays;
typedef  void __stdcall GLDISABLEVERTEXARRAYATTRIB (GLuint vaobj, GLuint index);
GLDISABLEVERTEXARRAYATTRIB *glDisableVertexArrayAttrib;
typedef  void __stdcall GLENABLEVERTEXARRAYATTRIB (GLuint vaobj, GLuint index);
GLENABLEVERTEXARRAYATTRIB *glEnableVertexArrayAttrib;
typedef  void __stdcall GLVERTEXARRAYELEMENTBUFFER (GLuint vaobj, GLuint buffer);
GLVERTEXARRAYELEMENTBUFFER *glVertexArrayElementBuffer;
typedef  void __stdcall GLVERTEXARRAYVERTEXBUFFER (GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
GLVERTEXARRAYVERTEXBUFFER *glVertexArrayVertexBuffer;
typedef  void __stdcall GLVERTEXARRAYVERTEXBUFFERS (GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
GLVERTEXARRAYVERTEXBUFFERS *glVertexArrayVertexBuffers;
typedef  void __stdcall GLVERTEXARRAYATTRIBBINDING (GLuint vaobj, GLuint attribindex, GLuint bindingindex);
GLVERTEXARRAYATTRIBBINDING *glVertexArrayAttribBinding;
typedef  void __stdcall GLVERTEXARRAYATTRIBFORMAT (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
GLVERTEXARRAYATTRIBFORMAT *glVertexArrayAttribFormat;
typedef  void __stdcall GLVERTEXARRAYATTRIBIFORMAT (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLVERTEXARRAYATTRIBIFORMAT *glVertexArrayAttribIFormat;
typedef  void __stdcall GLVERTEXARRAYATTRIBLFORMAT (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLVERTEXARRAYATTRIBLFORMAT *glVertexArrayAttribLFormat;
typedef  void __stdcall GLVERTEXARRAYBINDINGDIVISOR (GLuint vaobj, GLuint bindingindex, GLuint divisor);
GLVERTEXARRAYBINDINGDIVISOR *glVertexArrayBindingDivisor;
typedef  void __stdcall GLGETVERTEXARRAYIV (GLuint vaobj, GLenum pname, GLint *param);
GLGETVERTEXARRAYIV *glGetVertexArrayiv;
typedef  void __stdcall GLGETVERTEXARRAYINDEXEDIV (GLuint vaobj, GLuint index, GLenum pname, GLint *param);
GLGETVERTEXARRAYINDEXEDIV *glGetVertexArrayIndexediv;
typedef  void __stdcall GLGETVERTEXARRAYINDEXED64IV (GLuint vaobj, GLuint index, GLenum pname, GLint64 *param);
GLGETVERTEXARRAYINDEXED64IV *glGetVertexArrayIndexed64iv;
typedef  void __stdcall GLCREATESAMPLERS (GLsizei n, GLuint *samplers);
GLCREATESAMPLERS *glCreateSamplers;
typedef  void __stdcall GLCREATEPROGRAMPIPELINES (GLsizei n, GLuint *pipelines);
GLCREATEPROGRAMPIPELINES *glCreateProgramPipelines;
typedef  void __stdcall GLCREATEQUERIES (GLenum target, GLsizei n, GLuint *ids);
GLCREATEQUERIES *glCreateQueries;
typedef  void __stdcall GLGETQUERYBUFFEROBJECTI64V (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLGETQUERYBUFFEROBJECTI64V *glGetQueryBufferObjecti64v;
typedef  void __stdcall GLGETQUERYBUFFEROBJECTIV (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLGETQUERYBUFFEROBJECTIV *glGetQueryBufferObjectiv;
typedef  void __stdcall GLGETQUERYBUFFEROBJECTUI64V (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLGETQUERYBUFFEROBJECTUI64V *glGetQueryBufferObjectui64v;
typedef  void __stdcall GLGETQUERYBUFFEROBJECTUIV (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLGETQUERYBUFFEROBJECTUIV *glGetQueryBufferObjectuiv;
typedef  void __stdcall GLMEMORYBARRIERBYREGION (GLbitfield barriers);
GLMEMORYBARRIERBYREGION *glMemoryBarrierByRegion;
typedef  void __stdcall GLGETTEXTURESUBIMAGE (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
GLGETTEXTURESUBIMAGE *glGetTextureSubImage;
typedef  void __stdcall GLGETCOMPRESSEDTEXTURESUBIMAGE (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels);
GLGETCOMPRESSEDTEXTURESUBIMAGE *glGetCompressedTextureSubImage;
typedef  GLenum __stdcall GLGETGRAPHICSRESETSTATUS (void);
GLGETGRAPHICSRESETSTATUS *glGetGraphicsResetStatus;
typedef  void __stdcall GLGETNCOMPRESSEDTEXIMAGE (GLenum target, GLint lod, GLsizei bufSize, void *pixels);
GLGETNCOMPRESSEDTEXIMAGE *glGetnCompressedTexImage;
typedef  void __stdcall GLGETNTEXIMAGE (GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
GLGETNTEXIMAGE *glGetnTexImage;
typedef  void __stdcall GLGETNUNIFORMDV (GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
GLGETNUNIFORMDV *glGetnUniformdv;
typedef  void __stdcall GLGETNUNIFORMFV (GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
GLGETNUNIFORMFV *glGetnUniformfv;
typedef  void __stdcall GLGETNUNIFORMIV (GLuint program, GLint location, GLsizei bufSize, GLint *params);
GLGETNUNIFORMIV *glGetnUniformiv;
typedef  void __stdcall GLGETNUNIFORMUIV (GLuint program, GLint location, GLsizei bufSize, GLuint *params);
GLGETNUNIFORMUIV *glGetnUniformuiv;
typedef  void __stdcall GLREADNPIXELS (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
GLREADNPIXELS *glReadnPixels;
typedef  void __stdcall GLTEXTUREBARRIER (void);
GLTEXTUREBARRIER *glTextureBarrier;
typedef  GLuint64 __stdcall GLGETTEXTUREHANDLEARB (GLuint texture);
GLGETTEXTUREHANDLEARB *glGetTextureHandleARB;
typedef  GLuint64 __stdcall GLGETTEXTURESAMPLERHANDLEARB (GLuint texture, GLuint sampler);
GLGETTEXTURESAMPLERHANDLEARB *glGetTextureSamplerHandleARB;
typedef  void __stdcall GLMAKETEXTUREHANDLERESIDENTARB (GLuint64 handle);
GLMAKETEXTUREHANDLERESIDENTARB *glMakeTextureHandleResidentARB;
typedef  void __stdcall GLMAKETEXTUREHANDLENONRESIDENTARB (GLuint64 handle);
GLMAKETEXTUREHANDLENONRESIDENTARB *glMakeTextureHandleNonResidentARB;
typedef  GLuint64 __stdcall GLGETIMAGEHANDLEARB (GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
GLGETIMAGEHANDLEARB *glGetImageHandleARB;
typedef  void __stdcall GLMAKEIMAGEHANDLERESIDENTARB (GLuint64 handle, GLenum access);
GLMAKEIMAGEHANDLERESIDENTARB *glMakeImageHandleResidentARB;
typedef  void __stdcall GLMAKEIMAGEHANDLENONRESIDENTARB (GLuint64 handle);
GLMAKEIMAGEHANDLENONRESIDENTARB *glMakeImageHandleNonResidentARB;
typedef  void __stdcall GLUNIFORMHANDLEUI64ARB (GLint location, GLuint64 value);
GLUNIFORMHANDLEUI64ARB *glUniformHandleui64ARB;
typedef  void __stdcall GLUNIFORMHANDLEUI64VARB (GLint location, GLsizei count, const GLuint64 *value);
GLUNIFORMHANDLEUI64VARB *glUniformHandleui64vARB;
typedef  void __stdcall GLPROGRAMUNIFORMHANDLEUI64ARB (GLuint program, GLint location, GLuint64 value);
GLPROGRAMUNIFORMHANDLEUI64ARB *glProgramUniformHandleui64ARB;
typedef  void __stdcall GLPROGRAMUNIFORMHANDLEUI64VARB (GLuint program, GLint location, GLsizei count, const GLuint64 *values);
GLPROGRAMUNIFORMHANDLEUI64VARB *glProgramUniformHandleui64vARB;
typedef  GLboolean __stdcall GLISTEXTUREHANDLERESIDENTARB (GLuint64 handle);
GLISTEXTUREHANDLERESIDENTARB *glIsTextureHandleResidentARB;
typedef  GLboolean __stdcall GLISIMAGEHANDLERESIDENTARB (GLuint64 handle);
GLISIMAGEHANDLERESIDENTARB *glIsImageHandleResidentARB;
typedef  void __stdcall GLVERTEXATTRIBL1UI64ARB (GLuint index, GLuint64EXT x);
GLVERTEXATTRIBL1UI64ARB *glVertexAttribL1ui64ARB;
typedef  void __stdcall GLVERTEXATTRIBL1UI64VARB (GLuint index, const GLuint64EXT *v);
GLVERTEXATTRIBL1UI64VARB *glVertexAttribL1ui64vARB;
typedef  void __stdcall GLGETVERTEXATTRIBLUI64VARB (GLuint index, GLenum pname, GLuint64EXT *params);
GLGETVERTEXATTRIBLUI64VARB *glGetVertexAttribLui64vARB;
typedef  GLsync __stdcall GLCREATESYNCFROMCLEVENTARB (struct _cl_context *context, struct _cl_event *event, GLbitfield flags);
GLCREATESYNCFROMCLEVENTARB *glCreateSyncFromCLeventARB;
typedef  void __stdcall GLDISPATCHCOMPUTEGROUPSIZEARB (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLuint group_size_x, GLuint group_size_y, GLuint group_size_z);
GLDISPATCHCOMPUTEGROUPSIZEARB *glDispatchComputeGroupSizeARB;
typedef  void __stdcall GLDEBUGMESSAGECONTROLARB (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
GLDEBUGMESSAGECONTROLARB *glDebugMessageControlARB;
typedef  void __stdcall GLDEBUGMESSAGEINSERTARB (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
GLDEBUGMESSAGEINSERTARB *glDebugMessageInsertARB;
typedef  void __stdcall GLDEBUGMESSAGECALLBACKARB (GLDEBUGPROCARB callback, const void *userParam);
GLDEBUGMESSAGECALLBACKARB *glDebugMessageCallbackARB;
typedef  GLuint __stdcall GLGETDEBUGMESSAGELOGARB (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
GLGETDEBUGMESSAGELOGARB *glGetDebugMessageLogARB;
typedef  void __stdcall GLBLENDEQUATIONIARB (GLuint buf, GLenum mode);
GLBLENDEQUATIONIARB *glBlendEquationiARB;
typedef  void __stdcall GLBLENDEQUATIONSEPARATEIARB (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
GLBLENDEQUATIONSEPARATEIARB *glBlendEquationSeparateiARB;
typedef  void __stdcall GLBLENDFUNCIARB (GLuint buf, GLenum src, GLenum dst);
GLBLENDFUNCIARB *glBlendFunciARB;
typedef  void __stdcall GLBLENDFUNCSEPARATEIARB (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
GLBLENDFUNCSEPARATEIARB *glBlendFuncSeparateiARB;
typedef  void __stdcall GLMULTIDRAWARRAYSINDIRECTCOUNTARB (GLenum mode, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
GLMULTIDRAWARRAYSINDIRECTCOUNTARB *glMultiDrawArraysIndirectCountARB;
typedef  void __stdcall GLMULTIDRAWELEMENTSINDIRECTCOUNTARB (GLenum mode, GLenum type, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
GLMULTIDRAWELEMENTSINDIRECTCOUNTARB *glMultiDrawElementsIndirectCountARB;
typedef  GLenum __stdcall GLGETGRAPHICSRESETSTATUSARB (void);
GLGETGRAPHICSRESETSTATUSARB *glGetGraphicsResetStatusARB;
typedef  void __stdcall GLGETNTEXIMAGEARB (GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *img);
GLGETNTEXIMAGEARB *glGetnTexImageARB;
typedef  void __stdcall GLREADNPIXELSARB (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
GLREADNPIXELSARB *glReadnPixelsARB;
typedef  void __stdcall GLGETNCOMPRESSEDTEXIMAGEARB (GLenum target, GLint lod, GLsizei bufSize, void *img);
GLGETNCOMPRESSEDTEXIMAGEARB *glGetnCompressedTexImageARB;
typedef  void __stdcall GLGETNUNIFORMFVARB (GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
GLGETNUNIFORMFVARB *glGetnUniformfvARB;
typedef  void __stdcall GLGETNUNIFORMIVARB (GLuint program, GLint location, GLsizei bufSize, GLint *params);
GLGETNUNIFORMIVARB *glGetnUniformivARB;
typedef  void __stdcall GLGETNUNIFORMUIVARB (GLuint program, GLint location, GLsizei bufSize, GLuint *params);
GLGETNUNIFORMUIVARB *glGetnUniformuivARB;
typedef  void __stdcall GLGETNUNIFORMDVARB (GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
GLGETNUNIFORMDVARB *glGetnUniformdvARB;
typedef  void __stdcall GLMINSAMPLESHADINGARB (GLfloat value);
GLMINSAMPLESHADINGARB *glMinSampleShadingARB;
typedef  void __stdcall GLNAMEDSTRINGARB (GLenum type, GLint namelen, const GLchar *name, GLint stringlen, const GLchar *string);
GLNAMEDSTRINGARB *glNamedStringARB;
typedef  void __stdcall GLDELETENAMEDSTRINGARB (GLint namelen, const GLchar *name);
GLDELETENAMEDSTRINGARB *glDeleteNamedStringARB;
typedef  void __stdcall GLCOMPILESHADERINCLUDEARB (GLuint shader, GLsizei count, const GLchar *const*path, const GLint *length);
GLCOMPILESHADERINCLUDEARB *glCompileShaderIncludeARB;
typedef  GLboolean __stdcall GLISNAMEDSTRINGARB (GLint namelen, const GLchar *name);
GLISNAMEDSTRINGARB *glIsNamedStringARB;
typedef  void __stdcall GLGETNAMEDSTRINGARB (GLint namelen, const GLchar *name, GLsizei bufSize, GLint *stringlen, GLchar *string);
GLGETNAMEDSTRINGARB *glGetNamedStringARB;
typedef  void __stdcall GLGETNAMEDSTRINGIVARB (GLint namelen, const GLchar *name, GLenum pname, GLint *params);
GLGETNAMEDSTRINGIVARB *glGetNamedStringivARB;
typedef  void __stdcall GLBUFFERPAGECOMMITMENTARB (GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit);
GLBUFFERPAGECOMMITMENTARB *glBufferPageCommitmentARB;
typedef  void __stdcall GLNAMEDBUFFERPAGECOMMITMENTEXT (GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
GLNAMEDBUFFERPAGECOMMITMENTEXT *glNamedBufferPageCommitmentEXT;
typedef  void __stdcall GLNAMEDBUFFERPAGECOMMITMENTARB (GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
GLNAMEDBUFFERPAGECOMMITMENTARB *glNamedBufferPageCommitmentARB;
typedef  void __stdcall GLTEXPAGECOMMITMENTARB (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
GLTEXPAGECOMMITMENTARB *glTexPageCommitmentARB;
typedef  void __stdcall GLBLENDBARRIERKHR (void);
GLBLENDBARRIERKHR *glBlendBarrierKHR;
typedef  void __stdcall GLGETPERFMONITORGROUPSAMD (GLint *numGroups, GLsizei groupsSize, GLuint *groups);
GLGETPERFMONITORGROUPSAMD *glGetPerfMonitorGroupsAMD;
typedef  void __stdcall GLGETPERFMONITORCOUNTERSAMD (GLuint group, GLint *numCounters, GLint *maxActiveCounters, GLsizei counterSize, GLuint *counters);
GLGETPERFMONITORCOUNTERSAMD *glGetPerfMonitorCountersAMD;
typedef  void __stdcall GLGETPERFMONITORGROUPSTRINGAMD (GLuint group, GLsizei bufSize, GLsizei *length, GLchar *groupString);
GLGETPERFMONITORGROUPSTRINGAMD *glGetPerfMonitorGroupStringAMD;
typedef  void __stdcall GLGETPERFMONITORCOUNTERSTRINGAMD (GLuint group, GLuint counter, GLsizei bufSize, GLsizei *length, GLchar *counterString);
GLGETPERFMONITORCOUNTERSTRINGAMD *glGetPerfMonitorCounterStringAMD;
typedef  void __stdcall GLGETPERFMONITORCOUNTERINFOAMD (GLuint group, GLuint counter, GLenum pname, void *data);
GLGETPERFMONITORCOUNTERINFOAMD *glGetPerfMonitorCounterInfoAMD;
typedef  void __stdcall GLGENPERFMONITORSAMD (GLsizei n, GLuint *monitors);
GLGENPERFMONITORSAMD *glGenPerfMonitorsAMD;
typedef  void __stdcall GLDELETEPERFMONITORSAMD (GLsizei n, GLuint *monitors);
GLDELETEPERFMONITORSAMD *glDeletePerfMonitorsAMD;
typedef  void __stdcall GLSELECTPERFMONITORCOUNTERSAMD (GLuint monitor, GLboolean enable, GLuint group, GLint numCounters, GLuint *counterList);
GLSELECTPERFMONITORCOUNTERSAMD *glSelectPerfMonitorCountersAMD;
typedef  void __stdcall GLBEGINPERFMONITORAMD (GLuint monitor);
GLBEGINPERFMONITORAMD *glBeginPerfMonitorAMD;
typedef  void __stdcall GLENDPERFMONITORAMD (GLuint monitor);
GLENDPERFMONITORAMD *glEndPerfMonitorAMD;
typedef  void __stdcall GLGETPERFMONITORCOUNTERDATAAMD (GLuint monitor, GLenum pname, GLsizei dataSize, GLuint *data, GLint *bytesWritten);
GLGETPERFMONITORCOUNTERDATAAMD *glGetPerfMonitorCounterDataAMD;
typedef  void __stdcall GLLABELOBJECTEXT (GLenum type, GLuint object, GLsizei length, const GLchar *label);
GLLABELOBJECTEXT *glLabelObjectEXT;
typedef  void __stdcall GLGETOBJECTLABELEXT (GLenum type, GLuint object, GLsizei bufSize, GLsizei *length, GLchar *label);
GLGETOBJECTLABELEXT *glGetObjectLabelEXT;
typedef  void __stdcall GLINSERTEVENTMARKEREXT (GLsizei length, const GLchar *marker);
GLINSERTEVENTMARKEREXT *glInsertEventMarkerEXT;
typedef  void __stdcall GLPUSHGROUPMARKEREXT (GLsizei length, const GLchar *marker);
GLPUSHGROUPMARKEREXT *glPushGroupMarkerEXT;
typedef  void __stdcall GLPOPGROUPMARKEREXT (void);
GLPOPGROUPMARKEREXT *glPopGroupMarkerEXT;
typedef  void __stdcall GLMATRIXLOADFEXT (GLenum mode, const GLfloat *m);
GLMATRIXLOADFEXT *glMatrixLoadfEXT;
typedef  void __stdcall GLMATRIXLOADDEXT (GLenum mode, const GLdouble *m);
GLMATRIXLOADDEXT *glMatrixLoaddEXT;
typedef  void __stdcall GLMATRIXMULTFEXT (GLenum mode, const GLfloat *m);
GLMATRIXMULTFEXT *glMatrixMultfEXT;
typedef  void __stdcall GLMATRIXMULTDEXT (GLenum mode, const GLdouble *m);
GLMATRIXMULTDEXT *glMatrixMultdEXT;
typedef  void __stdcall GLMATRIXLOADIDENTITYEXT (GLenum mode);
GLMATRIXLOADIDENTITYEXT *glMatrixLoadIdentityEXT;
typedef  void __stdcall GLMATRIXROTATEFEXT (GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
GLMATRIXROTATEFEXT *glMatrixRotatefEXT;
typedef  void __stdcall GLMATRIXROTATEDEXT (GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
GLMATRIXROTATEDEXT *glMatrixRotatedEXT;
typedef  void __stdcall GLMATRIXSCALEFEXT (GLenum mode, GLfloat x, GLfloat y, GLfloat z);
GLMATRIXSCALEFEXT *glMatrixScalefEXT;
typedef  void __stdcall GLMATRIXSCALEDEXT (GLenum mode, GLdouble x, GLdouble y, GLdouble z);
GLMATRIXSCALEDEXT *glMatrixScaledEXT;
typedef  void __stdcall GLMATRIXTRANSLATEFEXT (GLenum mode, GLfloat x, GLfloat y, GLfloat z);
GLMATRIXTRANSLATEFEXT *glMatrixTranslatefEXT;
typedef  void __stdcall GLMATRIXTRANSLATEDEXT (GLenum mode, GLdouble x, GLdouble y, GLdouble z);
GLMATRIXTRANSLATEDEXT *glMatrixTranslatedEXT;
typedef  void __stdcall GLMATRIXFRUSTUMEXT (GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
GLMATRIXFRUSTUMEXT *glMatrixFrustumEXT;
typedef  void __stdcall GLMATRIXORTHOEXT (GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
GLMATRIXORTHOEXT *glMatrixOrthoEXT;
typedef  void __stdcall GLMATRIXPOPEXT (GLenum mode);
GLMATRIXPOPEXT *glMatrixPopEXT;
typedef  void __stdcall GLMATRIXPUSHEXT (GLenum mode);
GLMATRIXPUSHEXT *glMatrixPushEXT;
typedef  void __stdcall GLCLIENTATTRIBDEFAULTEXT (GLbitfield mask);
GLCLIENTATTRIBDEFAULTEXT *glClientAttribDefaultEXT;
typedef  void __stdcall GLPUSHCLIENTATTRIBDEFAULTEXT (GLbitfield mask);
GLPUSHCLIENTATTRIBDEFAULTEXT *glPushClientAttribDefaultEXT;
typedef  void __stdcall GLTEXTUREPARAMETERFEXT (GLuint texture, GLenum target, GLenum pname, GLfloat param);
GLTEXTUREPARAMETERFEXT *glTextureParameterfEXT;
typedef  void __stdcall GLTEXTUREPARAMETERFVEXT (GLuint texture, GLenum target, GLenum pname, const GLfloat *params);
GLTEXTUREPARAMETERFVEXT *glTextureParameterfvEXT;
typedef  void __stdcall GLTEXTUREPARAMETERIEXT (GLuint texture, GLenum target, GLenum pname, GLint param);
GLTEXTUREPARAMETERIEXT *glTextureParameteriEXT;
typedef  void __stdcall GLTEXTUREPARAMETERIVEXT (GLuint texture, GLenum target, GLenum pname, const GLint *params);
GLTEXTUREPARAMETERIVEXT *glTextureParameterivEXT;
typedef  void __stdcall GLTEXTUREIMAGE1DEXT (GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
GLTEXTUREIMAGE1DEXT *glTextureImage1DEXT;
typedef  void __stdcall GLTEXTUREIMAGE2DEXT (GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
GLTEXTUREIMAGE2DEXT *glTextureImage2DEXT;
typedef  void __stdcall GLTEXTURESUBIMAGE1DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
GLTEXTURESUBIMAGE1DEXT *glTextureSubImage1DEXT;
typedef  void __stdcall GLTEXTURESUBIMAGE2DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
GLTEXTURESUBIMAGE2DEXT *glTextureSubImage2DEXT;
typedef  void __stdcall GLCOPYTEXTUREIMAGE1DEXT (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
GLCOPYTEXTUREIMAGE1DEXT *glCopyTextureImage1DEXT;
typedef  void __stdcall GLCOPYTEXTUREIMAGE2DEXT (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
GLCOPYTEXTUREIMAGE2DEXT *glCopyTextureImage2DEXT;
typedef  void __stdcall GLCOPYTEXTURESUBIMAGE1DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
GLCOPYTEXTURESUBIMAGE1DEXT *glCopyTextureSubImage1DEXT;
typedef  void __stdcall GLCOPYTEXTURESUBIMAGE2DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLCOPYTEXTURESUBIMAGE2DEXT *glCopyTextureSubImage2DEXT;
typedef  void __stdcall GLGETTEXTUREIMAGEEXT (GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
GLGETTEXTUREIMAGEEXT *glGetTextureImageEXT;
typedef  void __stdcall GLGETTEXTUREPARAMETERFVEXT (GLuint texture, GLenum target, GLenum pname, GLfloat *params);
GLGETTEXTUREPARAMETERFVEXT *glGetTextureParameterfvEXT;
typedef  void __stdcall GLGETTEXTUREPARAMETERIVEXT (GLuint texture, GLenum target, GLenum pname, GLint *params);
GLGETTEXTUREPARAMETERIVEXT *glGetTextureParameterivEXT;
typedef  void __stdcall GLGETTEXTURELEVELPARAMETERFVEXT (GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat *params);
GLGETTEXTURELEVELPARAMETERFVEXT *glGetTextureLevelParameterfvEXT;
typedef  void __stdcall GLGETTEXTURELEVELPARAMETERIVEXT (GLuint texture, GLenum target, GLint level, GLenum pname, GLint *params);
GLGETTEXTURELEVELPARAMETERIVEXT *glGetTextureLevelParameterivEXT;
typedef  void __stdcall GLTEXTUREIMAGE3DEXT (GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
GLTEXTUREIMAGE3DEXT *glTextureImage3DEXT;
typedef  void __stdcall GLTEXTURESUBIMAGE3DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
GLTEXTURESUBIMAGE3DEXT *glTextureSubImage3DEXT;
typedef  void __stdcall GLCOPYTEXTURESUBIMAGE3DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLCOPYTEXTURESUBIMAGE3DEXT *glCopyTextureSubImage3DEXT;
typedef  void __stdcall GLBINDMULTITEXTUREEXT (GLenum texunit, GLenum target, GLuint texture);
GLBINDMULTITEXTUREEXT *glBindMultiTextureEXT;
typedef  void __stdcall GLMULTITEXCOORDPOINTEREXT (GLenum texunit, GLint size, GLenum type, GLsizei stride, const void *pointer);
GLMULTITEXCOORDPOINTEREXT *glMultiTexCoordPointerEXT;
typedef  void __stdcall GLMULTITEXENVFEXT (GLenum texunit, GLenum target, GLenum pname, GLfloat param);
GLMULTITEXENVFEXT *glMultiTexEnvfEXT;
typedef  void __stdcall GLMULTITEXENVFVEXT (GLenum texunit, GLenum target, GLenum pname, const GLfloat *params);
GLMULTITEXENVFVEXT *glMultiTexEnvfvEXT;
typedef  void __stdcall GLMULTITEXENVIEXT (GLenum texunit, GLenum target, GLenum pname, GLint param);
GLMULTITEXENVIEXT *glMultiTexEnviEXT;
typedef  void __stdcall GLMULTITEXENVIVEXT (GLenum texunit, GLenum target, GLenum pname, const GLint *params);
GLMULTITEXENVIVEXT *glMultiTexEnvivEXT;
typedef  void __stdcall GLMULTITEXGENDEXT (GLenum texunit, GLenum coord, GLenum pname, GLdouble param);
GLMULTITEXGENDEXT *glMultiTexGendEXT;
typedef  void __stdcall GLMULTITEXGENDVEXT (GLenum texunit, GLenum coord, GLenum pname, const GLdouble *params);
GLMULTITEXGENDVEXT *glMultiTexGendvEXT;
typedef  void __stdcall GLMULTITEXGENFEXT (GLenum texunit, GLenum coord, GLenum pname, GLfloat param);
GLMULTITEXGENFEXT *glMultiTexGenfEXT;
typedef  void __stdcall GLMULTITEXGENFVEXT (GLenum texunit, GLenum coord, GLenum pname, const GLfloat *params);
GLMULTITEXGENFVEXT *glMultiTexGenfvEXT;
typedef  void __stdcall GLMULTITEXGENIEXT (GLenum texunit, GLenum coord, GLenum pname, GLint param);
GLMULTITEXGENIEXT *glMultiTexGeniEXT;
typedef  void __stdcall GLMULTITEXGENIVEXT (GLenum texunit, GLenum coord, GLenum pname, const GLint *params);
GLMULTITEXGENIVEXT *glMultiTexGenivEXT;
typedef  void __stdcall GLGETMULTITEXENVFVEXT (GLenum texunit, GLenum target, GLenum pname, GLfloat *params);
GLGETMULTITEXENVFVEXT *glGetMultiTexEnvfvEXT;
typedef  void __stdcall GLGETMULTITEXENVIVEXT (GLenum texunit, GLenum target, GLenum pname, GLint *params);
GLGETMULTITEXENVIVEXT *glGetMultiTexEnvivEXT;
typedef  void __stdcall GLGETMULTITEXGENDVEXT (GLenum texunit, GLenum coord, GLenum pname, GLdouble *params);
GLGETMULTITEXGENDVEXT *glGetMultiTexGendvEXT;
typedef  void __stdcall GLGETMULTITEXGENFVEXT (GLenum texunit, GLenum coord, GLenum pname, GLfloat *params);
GLGETMULTITEXGENFVEXT *glGetMultiTexGenfvEXT;
typedef  void __stdcall GLGETMULTITEXGENIVEXT (GLenum texunit, GLenum coord, GLenum pname, GLint *params);
GLGETMULTITEXGENIVEXT *glGetMultiTexGenivEXT;
typedef  void __stdcall GLMULTITEXPARAMETERIEXT (GLenum texunit, GLenum target, GLenum pname, GLint param);
GLMULTITEXPARAMETERIEXT *glMultiTexParameteriEXT;
typedef  void __stdcall GLMULTITEXPARAMETERIVEXT (GLenum texunit, GLenum target, GLenum pname, const GLint *params);
GLMULTITEXPARAMETERIVEXT *glMultiTexParameterivEXT;
typedef  void __stdcall GLMULTITEXPARAMETERFEXT (GLenum texunit, GLenum target, GLenum pname, GLfloat param);
GLMULTITEXPARAMETERFEXT *glMultiTexParameterfEXT;
typedef  void __stdcall GLMULTITEXPARAMETERFVEXT (GLenum texunit, GLenum target, GLenum pname, const GLfloat *params);
GLMULTITEXPARAMETERFVEXT *glMultiTexParameterfvEXT;
typedef  void __stdcall GLMULTITEXIMAGE1DEXT (GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
GLMULTITEXIMAGE1DEXT *glMultiTexImage1DEXT;
typedef  void __stdcall GLMULTITEXIMAGE2DEXT (GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
GLMULTITEXIMAGE2DEXT *glMultiTexImage2DEXT;
typedef  void __stdcall GLMULTITEXSUBIMAGE1DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
GLMULTITEXSUBIMAGE1DEXT *glMultiTexSubImage1DEXT;
typedef  void __stdcall GLMULTITEXSUBIMAGE2DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
GLMULTITEXSUBIMAGE2DEXT *glMultiTexSubImage2DEXT;
typedef  void __stdcall GLCOPYMULTITEXIMAGE1DEXT (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
GLCOPYMULTITEXIMAGE1DEXT *glCopyMultiTexImage1DEXT;
typedef  void __stdcall GLCOPYMULTITEXIMAGE2DEXT (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
GLCOPYMULTITEXIMAGE2DEXT *glCopyMultiTexImage2DEXT;
typedef  void __stdcall GLCOPYMULTITEXSUBIMAGE1DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
GLCOPYMULTITEXSUBIMAGE1DEXT *glCopyMultiTexSubImage1DEXT;
typedef  void __stdcall GLCOPYMULTITEXSUBIMAGE2DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLCOPYMULTITEXSUBIMAGE2DEXT *glCopyMultiTexSubImage2DEXT;
typedef  void __stdcall GLGETMULTITEXIMAGEEXT (GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
GLGETMULTITEXIMAGEEXT *glGetMultiTexImageEXT;
typedef  void __stdcall GLGETMULTITEXPARAMETERFVEXT (GLenum texunit, GLenum target, GLenum pname, GLfloat *params);
GLGETMULTITEXPARAMETERFVEXT *glGetMultiTexParameterfvEXT;
typedef  void __stdcall GLGETMULTITEXPARAMETERIVEXT (GLenum texunit, GLenum target, GLenum pname, GLint *params);
GLGETMULTITEXPARAMETERIVEXT *glGetMultiTexParameterivEXT;
typedef  void __stdcall GLGETMULTITEXLEVELPARAMETERFVEXT (GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat *params);
GLGETMULTITEXLEVELPARAMETERFVEXT *glGetMultiTexLevelParameterfvEXT;
typedef  void __stdcall GLGETMULTITEXLEVELPARAMETERIVEXT (GLenum texunit, GLenum target, GLint level, GLenum pname, GLint *params);
GLGETMULTITEXLEVELPARAMETERIVEXT *glGetMultiTexLevelParameterivEXT;
typedef  void __stdcall GLMULTITEXIMAGE3DEXT (GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
GLMULTITEXIMAGE3DEXT *glMultiTexImage3DEXT;
typedef  void __stdcall GLMULTITEXSUBIMAGE3DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
GLMULTITEXSUBIMAGE3DEXT *glMultiTexSubImage3DEXT;
typedef  void __stdcall GLCOPYMULTITEXSUBIMAGE3DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLCOPYMULTITEXSUBIMAGE3DEXT *glCopyMultiTexSubImage3DEXT;
typedef  void __stdcall GLENABLECLIENTSTATEINDEXEDEXT (GLenum array, GLuint index);
GLENABLECLIENTSTATEINDEXEDEXT *glEnableClientStateIndexedEXT;
typedef  void __stdcall GLDISABLECLIENTSTATEINDEXEDEXT (GLenum array, GLuint index);
GLDISABLECLIENTSTATEINDEXEDEXT *glDisableClientStateIndexedEXT;
typedef  void __stdcall GLGETFLOATINDEXEDVEXT (GLenum target, GLuint index, GLfloat *data);
GLGETFLOATINDEXEDVEXT *glGetFloatIndexedvEXT;
typedef  void __stdcall GLGETDOUBLEINDEXEDVEXT (GLenum target, GLuint index, GLdouble *data);
GLGETDOUBLEINDEXEDVEXT *glGetDoubleIndexedvEXT;
typedef  void __stdcall GLGETPOINTERINDEXEDVEXT (GLenum target, GLuint index, void **data);
GLGETPOINTERINDEXEDVEXT *glGetPointerIndexedvEXT;
typedef  void __stdcall GLENABLEINDEXEDEXT (GLenum target, GLuint index);
GLENABLEINDEXEDEXT *glEnableIndexedEXT;
typedef  void __stdcall GLDISABLEINDEXEDEXT (GLenum target, GLuint index);
GLDISABLEINDEXEDEXT *glDisableIndexedEXT;
typedef  GLboolean __stdcall GLISENABLEDINDEXEDEXT (GLenum target, GLuint index);
GLISENABLEDINDEXEDEXT *glIsEnabledIndexedEXT;
typedef  void __stdcall GLGETINTEGERINDEXEDVEXT (GLenum target, GLuint index, GLint *data);
GLGETINTEGERINDEXEDVEXT *glGetIntegerIndexedvEXT;
typedef  void __stdcall GLGETBOOLEANINDEXEDVEXT (GLenum target, GLuint index, GLboolean *data);
GLGETBOOLEANINDEXEDVEXT *glGetBooleanIndexedvEXT;
typedef  void __stdcall GLCOMPRESSEDTEXTUREIMAGE3DEXT (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *bits);
GLCOMPRESSEDTEXTUREIMAGE3DEXT *glCompressedTextureImage3DEXT;
typedef  void __stdcall GLCOMPRESSEDTEXTUREIMAGE2DEXT (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *bits);
GLCOMPRESSEDTEXTUREIMAGE2DEXT *glCompressedTextureImage2DEXT;
typedef  void __stdcall GLCOMPRESSEDTEXTUREIMAGE1DEXT (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *bits);
GLCOMPRESSEDTEXTUREIMAGE1DEXT *glCompressedTextureImage1DEXT;
typedef  void __stdcall GLCOMPRESSEDTEXTURESUBIMAGE3DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *bits);
GLCOMPRESSEDTEXTURESUBIMAGE3DEXT *glCompressedTextureSubImage3DEXT;
typedef  void __stdcall GLCOMPRESSEDTEXTURESUBIMAGE2DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *bits);
GLCOMPRESSEDTEXTURESUBIMAGE2DEXT *glCompressedTextureSubImage2DEXT;
typedef  void __stdcall GLCOMPRESSEDTEXTURESUBIMAGE1DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *bits);
GLCOMPRESSEDTEXTURESUBIMAGE1DEXT *glCompressedTextureSubImage1DEXT;
typedef  void __stdcall GLGETCOMPRESSEDTEXTUREIMAGEEXT (GLuint texture, GLenum target, GLint lod, void *img);
GLGETCOMPRESSEDTEXTUREIMAGEEXT *glGetCompressedTextureImageEXT;
typedef  void __stdcall GLCOMPRESSEDMULTITEXIMAGE3DEXT (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *bits);
GLCOMPRESSEDMULTITEXIMAGE3DEXT *glCompressedMultiTexImage3DEXT;
typedef  void __stdcall GLCOMPRESSEDMULTITEXIMAGE2DEXT (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *bits);
GLCOMPRESSEDMULTITEXIMAGE2DEXT *glCompressedMultiTexImage2DEXT;
typedef  void __stdcall GLCOMPRESSEDMULTITEXIMAGE1DEXT (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *bits);
GLCOMPRESSEDMULTITEXIMAGE1DEXT *glCompressedMultiTexImage1DEXT;
typedef  void __stdcall GLCOMPRESSEDMULTITEXSUBIMAGE3DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *bits);
GLCOMPRESSEDMULTITEXSUBIMAGE3DEXT *glCompressedMultiTexSubImage3DEXT;
typedef  void __stdcall GLCOMPRESSEDMULTITEXSUBIMAGE2DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *bits);
GLCOMPRESSEDMULTITEXSUBIMAGE2DEXT *glCompressedMultiTexSubImage2DEXT;
typedef  void __stdcall GLCOMPRESSEDMULTITEXSUBIMAGE1DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *bits);
GLCOMPRESSEDMULTITEXSUBIMAGE1DEXT *glCompressedMultiTexSubImage1DEXT;
typedef  void __stdcall GLGETCOMPRESSEDMULTITEXIMAGEEXT (GLenum texunit, GLenum target, GLint lod, void *img);
GLGETCOMPRESSEDMULTITEXIMAGEEXT *glGetCompressedMultiTexImageEXT;
typedef  void __stdcall GLMATRIXLOADTRANSPOSEFEXT (GLenum mode, const GLfloat *m);
GLMATRIXLOADTRANSPOSEFEXT *glMatrixLoadTransposefEXT;
typedef  void __stdcall GLMATRIXLOADTRANSPOSEDEXT (GLenum mode, const GLdouble *m);
GLMATRIXLOADTRANSPOSEDEXT *glMatrixLoadTransposedEXT;
typedef  void __stdcall GLMATRIXMULTTRANSPOSEFEXT (GLenum mode, const GLfloat *m);
GLMATRIXMULTTRANSPOSEFEXT *glMatrixMultTransposefEXT;
typedef  void __stdcall GLMATRIXMULTTRANSPOSEDEXT (GLenum mode, const GLdouble *m);
GLMATRIXMULTTRANSPOSEDEXT *glMatrixMultTransposedEXT;
typedef  void __stdcall GLNAMEDBUFFERDATAEXT (GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
GLNAMEDBUFFERDATAEXT *glNamedBufferDataEXT;
typedef  void __stdcall GLNAMEDBUFFERSUBDATAEXT (GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
GLNAMEDBUFFERSUBDATAEXT *glNamedBufferSubDataEXT;
typedef  void  __stdcall GLMAPNAMEDBUFFEREXT (GLuint buffer, GLenum access);
GLMAPNAMEDBUFFEREXT *glMapNamedBufferEXT;
typedef  GLboolean __stdcall GLUNMAPNAMEDBUFFEREXT (GLuint buffer);
GLUNMAPNAMEDBUFFEREXT *glUnmapNamedBufferEXT;
typedef  void __stdcall GLGETNAMEDBUFFERPARAMETERIVEXT (GLuint buffer, GLenum pname, GLint *params);
GLGETNAMEDBUFFERPARAMETERIVEXT *glGetNamedBufferParameterivEXT;
typedef  void __stdcall GLGETNAMEDBUFFERPOINTERVEXT (GLuint buffer, GLenum pname, void **params);
GLGETNAMEDBUFFERPOINTERVEXT *glGetNamedBufferPointervEXT;
typedef  void __stdcall GLGETNAMEDBUFFERSUBDATAEXT (GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
GLGETNAMEDBUFFERSUBDATAEXT *glGetNamedBufferSubDataEXT;
typedef  void __stdcall GLPROGRAMUNIFORM1FEXT (GLuint program, GLint location, GLfloat v0);
GLPROGRAMUNIFORM1FEXT *glProgramUniform1fEXT;
typedef  void __stdcall GLPROGRAMUNIFORM2FEXT (GLuint program, GLint location, GLfloat v0, GLfloat v1);
GLPROGRAMUNIFORM2FEXT *glProgramUniform2fEXT;
typedef  void __stdcall GLPROGRAMUNIFORM3FEXT (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
GLPROGRAMUNIFORM3FEXT *glProgramUniform3fEXT;
typedef  void __stdcall GLPROGRAMUNIFORM4FEXT (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
GLPROGRAMUNIFORM4FEXT *glProgramUniform4fEXT;
typedef  void __stdcall GLPROGRAMUNIFORM1IEXT (GLuint program, GLint location, GLint v0);
GLPROGRAMUNIFORM1IEXT *glProgramUniform1iEXT;
typedef  void __stdcall GLPROGRAMUNIFORM2IEXT (GLuint program, GLint location, GLint v0, GLint v1);
GLPROGRAMUNIFORM2IEXT *glProgramUniform2iEXT;
typedef  void __stdcall GLPROGRAMUNIFORM3IEXT (GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
GLPROGRAMUNIFORM3IEXT *glProgramUniform3iEXT;
typedef  void __stdcall GLPROGRAMUNIFORM4IEXT (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
GLPROGRAMUNIFORM4IEXT *glProgramUniform4iEXT;
typedef  void __stdcall GLPROGRAMUNIFORM1FVEXT (GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLPROGRAMUNIFORM1FVEXT *glProgramUniform1fvEXT;
typedef  void __stdcall GLPROGRAMUNIFORM2FVEXT (GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLPROGRAMUNIFORM2FVEXT *glProgramUniform2fvEXT;
typedef  void __stdcall GLPROGRAMUNIFORM3FVEXT (GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLPROGRAMUNIFORM3FVEXT *glProgramUniform3fvEXT;
typedef  void __stdcall GLPROGRAMUNIFORM4FVEXT (GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLPROGRAMUNIFORM4FVEXT *glProgramUniform4fvEXT;
typedef  void __stdcall GLPROGRAMUNIFORM1IVEXT (GLuint program, GLint location, GLsizei count, const GLint *value);
GLPROGRAMUNIFORM1IVEXT *glProgramUniform1ivEXT;
typedef  void __stdcall GLPROGRAMUNIFORM2IVEXT (GLuint program, GLint location, GLsizei count, const GLint *value);
GLPROGRAMUNIFORM2IVEXT *glProgramUniform2ivEXT;
typedef  void __stdcall GLPROGRAMUNIFORM3IVEXT (GLuint program, GLint location, GLsizei count, const GLint *value);
GLPROGRAMUNIFORM3IVEXT *glProgramUniform3ivEXT;
typedef  void __stdcall GLPROGRAMUNIFORM4IVEXT (GLuint program, GLint location, GLsizei count, const GLint *value);
GLPROGRAMUNIFORM4IVEXT *glProgramUniform4ivEXT;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX2FVEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLPROGRAMUNIFORMMATRIX2FVEXT *glProgramUniformMatrix2fvEXT;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX3FVEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLPROGRAMUNIFORMMATRIX3FVEXT *glProgramUniformMatrix3fvEXT;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX4FVEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLPROGRAMUNIFORMMATRIX4FVEXT *glProgramUniformMatrix4fvEXT;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX2X3FVEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLPROGRAMUNIFORMMATRIX2X3FVEXT *glProgramUniformMatrix2x3fvEXT;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX3X2FVEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLPROGRAMUNIFORMMATRIX3X2FVEXT *glProgramUniformMatrix3x2fvEXT;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX2X4FVEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLPROGRAMUNIFORMMATRIX2X4FVEXT *glProgramUniformMatrix2x4fvEXT;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX4X2FVEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLPROGRAMUNIFORMMATRIX4X2FVEXT *glProgramUniformMatrix4x2fvEXT;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX3X4FVEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLPROGRAMUNIFORMMATRIX3X4FVEXT *glProgramUniformMatrix3x4fvEXT;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX4X3FVEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLPROGRAMUNIFORMMATRIX4X3FVEXT *glProgramUniformMatrix4x3fvEXT;
typedef  void __stdcall GLTEXTUREBUFFEREXT (GLuint texture, GLenum target, GLenum internalformat, GLuint buffer);
GLTEXTUREBUFFEREXT *glTextureBufferEXT;
typedef  void __stdcall GLMULTITEXBUFFEREXT (GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer);
GLMULTITEXBUFFEREXT *glMultiTexBufferEXT;
typedef  void __stdcall GLTEXTUREPARAMETERIIVEXT (GLuint texture, GLenum target, GLenum pname, const GLint *params);
GLTEXTUREPARAMETERIIVEXT *glTextureParameterIivEXT;
typedef  void __stdcall GLTEXTUREPARAMETERIUIVEXT (GLuint texture, GLenum target, GLenum pname, const GLuint *params);
GLTEXTUREPARAMETERIUIVEXT *glTextureParameterIuivEXT;
typedef  void __stdcall GLGETTEXTUREPARAMETERIIVEXT (GLuint texture, GLenum target, GLenum pname, GLint *params);
GLGETTEXTUREPARAMETERIIVEXT *glGetTextureParameterIivEXT;
typedef  void __stdcall GLGETTEXTUREPARAMETERIUIVEXT (GLuint texture, GLenum target, GLenum pname, GLuint *params);
GLGETTEXTUREPARAMETERIUIVEXT *glGetTextureParameterIuivEXT;
typedef  void __stdcall GLMULTITEXPARAMETERIIVEXT (GLenum texunit, GLenum target, GLenum pname, const GLint *params);
GLMULTITEXPARAMETERIIVEXT *glMultiTexParameterIivEXT;
typedef  void __stdcall GLMULTITEXPARAMETERIUIVEXT (GLenum texunit, GLenum target, GLenum pname, const GLuint *params);
GLMULTITEXPARAMETERIUIVEXT *glMultiTexParameterIuivEXT;
typedef  void __stdcall GLGETMULTITEXPARAMETERIIVEXT (GLenum texunit, GLenum target, GLenum pname, GLint *params);
GLGETMULTITEXPARAMETERIIVEXT *glGetMultiTexParameterIivEXT;
typedef  void __stdcall GLGETMULTITEXPARAMETERIUIVEXT (GLenum texunit, GLenum target, GLenum pname, GLuint *params);
GLGETMULTITEXPARAMETERIUIVEXT *glGetMultiTexParameterIuivEXT;
typedef  void __stdcall GLPROGRAMUNIFORM1UIEXT (GLuint program, GLint location, GLuint v0);
GLPROGRAMUNIFORM1UIEXT *glProgramUniform1uiEXT;
typedef  void __stdcall GLPROGRAMUNIFORM2UIEXT (GLuint program, GLint location, GLuint v0, GLuint v1);
GLPROGRAMUNIFORM2UIEXT *glProgramUniform2uiEXT;
typedef  void __stdcall GLPROGRAMUNIFORM3UIEXT (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
GLPROGRAMUNIFORM3UIEXT *glProgramUniform3uiEXT;
typedef  void __stdcall GLPROGRAMUNIFORM4UIEXT (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
GLPROGRAMUNIFORM4UIEXT *glProgramUniform4uiEXT;
typedef  void __stdcall GLPROGRAMUNIFORM1UIVEXT (GLuint program, GLint location, GLsizei count, const GLuint *value);
GLPROGRAMUNIFORM1UIVEXT *glProgramUniform1uivEXT;
typedef  void __stdcall GLPROGRAMUNIFORM2UIVEXT (GLuint program, GLint location, GLsizei count, const GLuint *value);
GLPROGRAMUNIFORM2UIVEXT *glProgramUniform2uivEXT;
typedef  void __stdcall GLPROGRAMUNIFORM3UIVEXT (GLuint program, GLint location, GLsizei count, const GLuint *value);
GLPROGRAMUNIFORM3UIVEXT *glProgramUniform3uivEXT;
typedef  void __stdcall GLPROGRAMUNIFORM4UIVEXT (GLuint program, GLint location, GLsizei count, const GLuint *value);
GLPROGRAMUNIFORM4UIVEXT *glProgramUniform4uivEXT;
typedef  void __stdcall GLNAMEDPROGRAMLOCALPARAMETERS4FVEXT (GLuint program, GLenum target, GLuint index, GLsizei count, const GLfloat *params);
GLNAMEDPROGRAMLOCALPARAMETERS4FVEXT *glNamedProgramLocalParameters4fvEXT;
typedef  void __stdcall GLNAMEDPROGRAMLOCALPARAMETERI4IEXT (GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
GLNAMEDPROGRAMLOCALPARAMETERI4IEXT *glNamedProgramLocalParameterI4iEXT;
typedef  void __stdcall GLNAMEDPROGRAMLOCALPARAMETERI4IVEXT (GLuint program, GLenum target, GLuint index, const GLint *params);
GLNAMEDPROGRAMLOCALPARAMETERI4IVEXT *glNamedProgramLocalParameterI4ivEXT;
typedef  void __stdcall GLNAMEDPROGRAMLOCALPARAMETERSI4IVEXT (GLuint program, GLenum target, GLuint index, GLsizei count, const GLint *params);
GLNAMEDPROGRAMLOCALPARAMETERSI4IVEXT *glNamedProgramLocalParametersI4ivEXT;
typedef  void __stdcall GLNAMEDPROGRAMLOCALPARAMETERI4UIEXT (GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
GLNAMEDPROGRAMLOCALPARAMETERI4UIEXT *glNamedProgramLocalParameterI4uiEXT;
typedef  void __stdcall GLNAMEDPROGRAMLOCALPARAMETERI4UIVEXT (GLuint program, GLenum target, GLuint index, const GLuint *params);
GLNAMEDPROGRAMLOCALPARAMETERI4UIVEXT *glNamedProgramLocalParameterI4uivEXT;
typedef  void __stdcall GLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXT (GLuint program, GLenum target, GLuint index, GLsizei count, const GLuint *params);
GLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXT *glNamedProgramLocalParametersI4uivEXT;
typedef  void __stdcall GLGETNAMEDPROGRAMLOCALPARAMETERIIVEXT (GLuint program, GLenum target, GLuint index, GLint *params);
GLGETNAMEDPROGRAMLOCALPARAMETERIIVEXT *glGetNamedProgramLocalParameterIivEXT;
typedef  void __stdcall GLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXT (GLuint program, GLenum target, GLuint index, GLuint *params);
GLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXT *glGetNamedProgramLocalParameterIuivEXT;
typedef  void __stdcall GLENABLECLIENTSTATEIEXT (GLenum array, GLuint index);
GLENABLECLIENTSTATEIEXT *glEnableClientStateiEXT;
typedef  void __stdcall GLDISABLECLIENTSTATEIEXT (GLenum array, GLuint index);
GLDISABLECLIENTSTATEIEXT *glDisableClientStateiEXT;
typedef  void __stdcall GLGETFLOATI_VEXT (GLenum pname, GLuint index, GLfloat *params);
GLGETFLOATI_VEXT *glGetFloati_vEXT;
typedef  void __stdcall GLGETDOUBLEI_VEXT (GLenum pname, GLuint index, GLdouble *params);
GLGETDOUBLEI_VEXT *glGetDoublei_vEXT;
typedef  void __stdcall GLGETPOINTERI_VEXT (GLenum pname, GLuint index, void **params);
GLGETPOINTERI_VEXT *glGetPointeri_vEXT;
typedef  void __stdcall GLNAMEDPROGRAMSTRINGEXT (GLuint program, GLenum target, GLenum format, GLsizei len, const void *string);
GLNAMEDPROGRAMSTRINGEXT *glNamedProgramStringEXT;
typedef  void __stdcall GLNAMEDPROGRAMLOCALPARAMETER4DEXT (GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLNAMEDPROGRAMLOCALPARAMETER4DEXT *glNamedProgramLocalParameter4dEXT;
typedef  void __stdcall GLNAMEDPROGRAMLOCALPARAMETER4DVEXT (GLuint program, GLenum target, GLuint index, const GLdouble *params);
GLNAMEDPROGRAMLOCALPARAMETER4DVEXT *glNamedProgramLocalParameter4dvEXT;
typedef  void __stdcall GLNAMEDPROGRAMLOCALPARAMETER4FEXT (GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLNAMEDPROGRAMLOCALPARAMETER4FEXT *glNamedProgramLocalParameter4fEXT;
typedef  void __stdcall GLNAMEDPROGRAMLOCALPARAMETER4FVEXT (GLuint program, GLenum target, GLuint index, const GLfloat *params);
GLNAMEDPROGRAMLOCALPARAMETER4FVEXT *glNamedProgramLocalParameter4fvEXT;
typedef  void __stdcall GLGETNAMEDPROGRAMLOCALPARAMETERDVEXT (GLuint program, GLenum target, GLuint index, GLdouble *params);
GLGETNAMEDPROGRAMLOCALPARAMETERDVEXT *glGetNamedProgramLocalParameterdvEXT;
typedef  void __stdcall GLGETNAMEDPROGRAMLOCALPARAMETERFVEXT (GLuint program, GLenum target, GLuint index, GLfloat *params);
GLGETNAMEDPROGRAMLOCALPARAMETERFVEXT *glGetNamedProgramLocalParameterfvEXT;
typedef  void __stdcall GLGETNAMEDPROGRAMIVEXT (GLuint program, GLenum target, GLenum pname, GLint *params);
GLGETNAMEDPROGRAMIVEXT *glGetNamedProgramivEXT;
typedef  void __stdcall GLGETNAMEDPROGRAMSTRINGEXT (GLuint program, GLenum target, GLenum pname, void *string);
GLGETNAMEDPROGRAMSTRINGEXT *glGetNamedProgramStringEXT;
typedef  void __stdcall GLNAMEDRENDERBUFFERSTORAGEEXT (GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
GLNAMEDRENDERBUFFERSTORAGEEXT *glNamedRenderbufferStorageEXT;
typedef  void __stdcall GLGETNAMEDRENDERBUFFERPARAMETERIVEXT (GLuint renderbuffer, GLenum pname, GLint *params);
GLGETNAMEDRENDERBUFFERPARAMETERIVEXT *glGetNamedRenderbufferParameterivEXT;
typedef  void __stdcall GLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXT (GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
GLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXT *glNamedRenderbufferStorageMultisampleEXT;
typedef  void __stdcall GLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXT (GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
GLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXT *glNamedRenderbufferStorageMultisampleCoverageEXT;
typedef  GLenum __stdcall GLCHECKNAMEDFRAMEBUFFERSTATUSEXT (GLuint framebuffer, GLenum target);
GLCHECKNAMEDFRAMEBUFFERSTATUSEXT *glCheckNamedFramebufferStatusEXT;
typedef  void __stdcall GLNAMEDFRAMEBUFFERTEXTURE1DEXT (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLNAMEDFRAMEBUFFERTEXTURE1DEXT *glNamedFramebufferTexture1DEXT;
typedef  void __stdcall GLNAMEDFRAMEBUFFERTEXTURE2DEXT (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLNAMEDFRAMEBUFFERTEXTURE2DEXT *glNamedFramebufferTexture2DEXT;
typedef  void __stdcall GLNAMEDFRAMEBUFFERTEXTURE3DEXT (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
GLNAMEDFRAMEBUFFERTEXTURE3DEXT *glNamedFramebufferTexture3DEXT;
typedef  void __stdcall GLNAMEDFRAMEBUFFERRENDERBUFFEREXT (GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
GLNAMEDFRAMEBUFFERRENDERBUFFEREXT *glNamedFramebufferRenderbufferEXT;
typedef  void __stdcall GLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXT (GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
GLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXT *glGetNamedFramebufferAttachmentParameterivEXT;
typedef  void __stdcall GLGENERATETEXTUREMIPMAPEXT (GLuint texture, GLenum target);
GLGENERATETEXTUREMIPMAPEXT *glGenerateTextureMipmapEXT;
typedef  void __stdcall GLGENERATEMULTITEXMIPMAPEXT (GLenum texunit, GLenum target);
GLGENERATEMULTITEXMIPMAPEXT *glGenerateMultiTexMipmapEXT;
typedef  void __stdcall GLFRAMEBUFFERDRAWBUFFEREXT (GLuint framebuffer, GLenum mode);
GLFRAMEBUFFERDRAWBUFFEREXT *glFramebufferDrawBufferEXT;
typedef  void __stdcall GLFRAMEBUFFERDRAWBUFFERSEXT (GLuint framebuffer, GLsizei n, const GLenum *bufs);
GLFRAMEBUFFERDRAWBUFFERSEXT *glFramebufferDrawBuffersEXT;
typedef  void __stdcall GLFRAMEBUFFERREADBUFFEREXT (GLuint framebuffer, GLenum mode);
GLFRAMEBUFFERREADBUFFEREXT *glFramebufferReadBufferEXT;
typedef  void __stdcall GLGETFRAMEBUFFERPARAMETERIVEXT (GLuint framebuffer, GLenum pname, GLint *params);
GLGETFRAMEBUFFERPARAMETERIVEXT *glGetFramebufferParameterivEXT;
typedef  void __stdcall GLNAMEDCOPYBUFFERSUBDATAEXT (GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
GLNAMEDCOPYBUFFERSUBDATAEXT *glNamedCopyBufferSubDataEXT;
typedef  void __stdcall GLNAMEDFRAMEBUFFERTEXTUREEXT (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
GLNAMEDFRAMEBUFFERTEXTUREEXT *glNamedFramebufferTextureEXT;
typedef  void __stdcall GLNAMEDFRAMEBUFFERTEXTURELAYEREXT (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLNAMEDFRAMEBUFFERTEXTURELAYEREXT *glNamedFramebufferTextureLayerEXT;
typedef  void __stdcall GLNAMEDFRAMEBUFFERTEXTUREFACEEXT (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face);
GLNAMEDFRAMEBUFFERTEXTUREFACEEXT *glNamedFramebufferTextureFaceEXT;
typedef  void __stdcall GLTEXTURERENDERBUFFEREXT (GLuint texture, GLenum target, GLuint renderbuffer);
GLTEXTURERENDERBUFFEREXT *glTextureRenderbufferEXT;
typedef  void __stdcall GLMULTITEXRENDERBUFFEREXT (GLenum texunit, GLenum target, GLuint renderbuffer);
GLMULTITEXRENDERBUFFEREXT *glMultiTexRenderbufferEXT;
typedef  void __stdcall GLVERTEXARRAYVERTEXOFFSETEXT (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
GLVERTEXARRAYVERTEXOFFSETEXT *glVertexArrayVertexOffsetEXT;
typedef  void __stdcall GLVERTEXARRAYCOLOROFFSETEXT (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
GLVERTEXARRAYCOLOROFFSETEXT *glVertexArrayColorOffsetEXT;
typedef  void __stdcall GLVERTEXARRAYEDGEFLAGOFFSETEXT (GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset);
GLVERTEXARRAYEDGEFLAGOFFSETEXT *glVertexArrayEdgeFlagOffsetEXT;
typedef  void __stdcall GLVERTEXARRAYINDEXOFFSETEXT (GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
GLVERTEXARRAYINDEXOFFSETEXT *glVertexArrayIndexOffsetEXT;
typedef  void __stdcall GLVERTEXARRAYNORMALOFFSETEXT (GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
GLVERTEXARRAYNORMALOFFSETEXT *glVertexArrayNormalOffsetEXT;
typedef  void __stdcall GLVERTEXARRAYTEXCOORDOFFSETEXT (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
GLVERTEXARRAYTEXCOORDOFFSETEXT *glVertexArrayTexCoordOffsetEXT;
typedef  void __stdcall GLVERTEXARRAYMULTITEXCOORDOFFSETEXT (GLuint vaobj, GLuint buffer, GLenum texunit, GLint size, GLenum type, GLsizei stride, GLintptr offset);
GLVERTEXARRAYMULTITEXCOORDOFFSETEXT *glVertexArrayMultiTexCoordOffsetEXT;
typedef  void __stdcall GLVERTEXARRAYFOGCOORDOFFSETEXT (GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
GLVERTEXARRAYFOGCOORDOFFSETEXT *glVertexArrayFogCoordOffsetEXT;
typedef  void __stdcall GLVERTEXARRAYSECONDARYCOLOROFFSETEXT (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
GLVERTEXARRAYSECONDARYCOLOROFFSETEXT *glVertexArraySecondaryColorOffsetEXT;
typedef  void __stdcall GLVERTEXARRAYVERTEXATTRIBOFFSETEXT (GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset);
GLVERTEXARRAYVERTEXATTRIBOFFSETEXT *glVertexArrayVertexAttribOffsetEXT;
typedef  void __stdcall GLVERTEXARRAYVERTEXATTRIBIOFFSETEXT (GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
GLVERTEXARRAYVERTEXATTRIBIOFFSETEXT *glVertexArrayVertexAttribIOffsetEXT;
typedef  void __stdcall GLENABLEVERTEXARRAYEXT (GLuint vaobj, GLenum array);
GLENABLEVERTEXARRAYEXT *glEnableVertexArrayEXT;
typedef  void __stdcall GLDISABLEVERTEXARRAYEXT (GLuint vaobj, GLenum array);
GLDISABLEVERTEXARRAYEXT *glDisableVertexArrayEXT;
typedef  void __stdcall GLENABLEVERTEXARRAYATTRIBEXT (GLuint vaobj, GLuint index);
GLENABLEVERTEXARRAYATTRIBEXT *glEnableVertexArrayAttribEXT;
typedef  void __stdcall GLDISABLEVERTEXARRAYATTRIBEXT (GLuint vaobj, GLuint index);
GLDISABLEVERTEXARRAYATTRIBEXT *glDisableVertexArrayAttribEXT;
typedef  void __stdcall GLGETVERTEXARRAYINTEGERVEXT (GLuint vaobj, GLenum pname, GLint *param);
GLGETVERTEXARRAYINTEGERVEXT *glGetVertexArrayIntegervEXT;
typedef  void __stdcall GLGETVERTEXARRAYPOINTERVEXT (GLuint vaobj, GLenum pname, void **param);
GLGETVERTEXARRAYPOINTERVEXT *glGetVertexArrayPointervEXT;
typedef  void __stdcall GLGETVERTEXARRAYINTEGERI_VEXT (GLuint vaobj, GLuint index, GLenum pname, GLint *param);
GLGETVERTEXARRAYINTEGERI_VEXT *glGetVertexArrayIntegeri_vEXT;
typedef  void __stdcall GLGETVERTEXARRAYPOINTERI_VEXT (GLuint vaobj, GLuint index, GLenum pname, void **param);
GLGETVERTEXARRAYPOINTERI_VEXT *glGetVertexArrayPointeri_vEXT;
typedef  void  __stdcall GLMAPNAMEDBUFFERRANGEEXT (GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
GLMAPNAMEDBUFFERRANGEEXT *glMapNamedBufferRangeEXT;
typedef  void __stdcall GLFLUSHMAPPEDNAMEDBUFFERRANGEEXT (GLuint buffer, GLintptr offset, GLsizeiptr length);
GLFLUSHMAPPEDNAMEDBUFFERRANGEEXT *glFlushMappedNamedBufferRangeEXT;
typedef  void __stdcall GLNAMEDBUFFERSTORAGEEXT (GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
GLNAMEDBUFFERSTORAGEEXT *glNamedBufferStorageEXT;
typedef  void __stdcall GLCLEARNAMEDBUFFERDATAEXT (GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
GLCLEARNAMEDBUFFERDATAEXT *glClearNamedBufferDataEXT;
typedef  void __stdcall GLCLEARNAMEDBUFFERSUBDATAEXT (GLuint buffer, GLenum internalformat, GLsizeiptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
GLCLEARNAMEDBUFFERSUBDATAEXT *glClearNamedBufferSubDataEXT;
typedef  void __stdcall GLNAMEDFRAMEBUFFERPARAMETERIEXT (GLuint framebuffer, GLenum pname, GLint param);
GLNAMEDFRAMEBUFFERPARAMETERIEXT *glNamedFramebufferParameteriEXT;
typedef  void __stdcall GLGETNAMEDFRAMEBUFFERPARAMETERIVEXT (GLuint framebuffer, GLenum pname, GLint *params);
GLGETNAMEDFRAMEBUFFERPARAMETERIVEXT *glGetNamedFramebufferParameterivEXT;
typedef  void __stdcall GLPROGRAMUNIFORM1DEXT (GLuint program, GLint location, GLdouble x);
GLPROGRAMUNIFORM1DEXT *glProgramUniform1dEXT;
typedef  void __stdcall GLPROGRAMUNIFORM2DEXT (GLuint program, GLint location, GLdouble x, GLdouble y);
GLPROGRAMUNIFORM2DEXT *glProgramUniform2dEXT;
typedef  void __stdcall GLPROGRAMUNIFORM3DEXT (GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z);
GLPROGRAMUNIFORM3DEXT *glProgramUniform3dEXT;
typedef  void __stdcall GLPROGRAMUNIFORM4DEXT (GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLPROGRAMUNIFORM4DEXT *glProgramUniform4dEXT;
typedef  void __stdcall GLPROGRAMUNIFORM1DVEXT (GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLPROGRAMUNIFORM1DVEXT *glProgramUniform1dvEXT;
typedef  void __stdcall GLPROGRAMUNIFORM2DVEXT (GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLPROGRAMUNIFORM2DVEXT *glProgramUniform2dvEXT;
typedef  void __stdcall GLPROGRAMUNIFORM3DVEXT (GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLPROGRAMUNIFORM3DVEXT *glProgramUniform3dvEXT;
typedef  void __stdcall GLPROGRAMUNIFORM4DVEXT (GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLPROGRAMUNIFORM4DVEXT *glProgramUniform4dvEXT;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX2DVEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLPROGRAMUNIFORMMATRIX2DVEXT *glProgramUniformMatrix2dvEXT;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX3DVEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLPROGRAMUNIFORMMATRIX3DVEXT *glProgramUniformMatrix3dvEXT;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX4DVEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLPROGRAMUNIFORMMATRIX4DVEXT *glProgramUniformMatrix4dvEXT;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX2X3DVEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLPROGRAMUNIFORMMATRIX2X3DVEXT *glProgramUniformMatrix2x3dvEXT;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX2X4DVEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLPROGRAMUNIFORMMATRIX2X4DVEXT *glProgramUniformMatrix2x4dvEXT;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX3X2DVEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLPROGRAMUNIFORMMATRIX3X2DVEXT *glProgramUniformMatrix3x2dvEXT;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX3X4DVEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLPROGRAMUNIFORMMATRIX3X4DVEXT *glProgramUniformMatrix3x4dvEXT;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX4X2DVEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLPROGRAMUNIFORMMATRIX4X2DVEXT *glProgramUniformMatrix4x2dvEXT;
typedef  void __stdcall GLPROGRAMUNIFORMMATRIX4X3DVEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLPROGRAMUNIFORMMATRIX4X3DVEXT *glProgramUniformMatrix4x3dvEXT;
typedef  void __stdcall GLTEXTUREBUFFERRANGEEXT (GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLTEXTUREBUFFERRANGEEXT *glTextureBufferRangeEXT;
typedef  void __stdcall GLTEXTURESTORAGE1DEXT (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
GLTEXTURESTORAGE1DEXT *glTextureStorage1DEXT;
typedef  void __stdcall GLTEXTURESTORAGE2DEXT (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
GLTEXTURESTORAGE2DEXT *glTextureStorage2DEXT;
typedef  void __stdcall GLTEXTURESTORAGE3DEXT (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
GLTEXTURESTORAGE3DEXT *glTextureStorage3DEXT;
typedef  void __stdcall GLTEXTURESTORAGE2DMULTISAMPLEEXT (GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLTEXTURESTORAGE2DMULTISAMPLEEXT *glTextureStorage2DMultisampleEXT;
typedef  void __stdcall GLTEXTURESTORAGE3DMULTISAMPLEEXT (GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
GLTEXTURESTORAGE3DMULTISAMPLEEXT *glTextureStorage3DMultisampleEXT;
typedef  void __stdcall GLVERTEXARRAYBINDVERTEXBUFFEREXT (GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
GLVERTEXARRAYBINDVERTEXBUFFEREXT *glVertexArrayBindVertexBufferEXT;
typedef  void __stdcall GLVERTEXARRAYVERTEXATTRIBFORMATEXT (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
GLVERTEXARRAYVERTEXATTRIBFORMATEXT *glVertexArrayVertexAttribFormatEXT;
typedef  void __stdcall GLVERTEXARRAYVERTEXATTRIBIFORMATEXT (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLVERTEXARRAYVERTEXATTRIBIFORMATEXT *glVertexArrayVertexAttribIFormatEXT;
typedef  void __stdcall GLVERTEXARRAYVERTEXATTRIBLFORMATEXT (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLVERTEXARRAYVERTEXATTRIBLFORMATEXT *glVertexArrayVertexAttribLFormatEXT;
typedef  void __stdcall GLVERTEXARRAYVERTEXATTRIBBINDINGEXT (GLuint vaobj, GLuint attribindex, GLuint bindingindex);
GLVERTEXARRAYVERTEXATTRIBBINDINGEXT *glVertexArrayVertexAttribBindingEXT;
typedef  void __stdcall GLVERTEXARRAYVERTEXBINDINGDIVISOREXT (GLuint vaobj, GLuint bindingindex, GLuint divisor);
GLVERTEXARRAYVERTEXBINDINGDIVISOREXT *glVertexArrayVertexBindingDivisorEXT;
typedef  void __stdcall GLVERTEXARRAYVERTEXATTRIBLOFFSETEXT (GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
GLVERTEXARRAYVERTEXATTRIBLOFFSETEXT *glVertexArrayVertexAttribLOffsetEXT;
typedef  void __stdcall GLTEXTUREPAGECOMMITMENTEXT (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
GLTEXTUREPAGECOMMITMENTEXT *glTexturePageCommitmentEXT;
typedef  void __stdcall GLVERTEXARRAYVERTEXATTRIBDIVISOREXT (GLuint vaobj, GLuint index, GLuint divisor);
GLVERTEXARRAYVERTEXATTRIBDIVISOREXT *glVertexArrayVertexAttribDivisorEXT;
typedef  void __stdcall GLDRAWARRAYSINSTANCEDEXT (GLenum mode, GLint start, GLsizei count, GLsizei primcount);
GLDRAWARRAYSINSTANCEDEXT *glDrawArraysInstancedEXT;
typedef  void __stdcall GLDRAWELEMENTSINSTANCEDEXT (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount);
GLDRAWELEMENTSINSTANCEDEXT *glDrawElementsInstancedEXT;
typedef  void __stdcall GLPOLYGONOFFSETCLAMPEXT (GLfloat factor, GLfloat units, GLfloat clamp);
GLPOLYGONOFFSETCLAMPEXT *glPolygonOffsetClampEXT;
typedef  void __stdcall GLRASTERSAMPLESEXT (GLuint samples, GLboolean fixedsamplelocations);
GLRASTERSAMPLESEXT *glRasterSamplesEXT;
typedef  void __stdcall GLUSESHADERPROGRAMEXT (GLenum type, GLuint program);
GLUSESHADERPROGRAMEXT *glUseShaderProgramEXT;
typedef  void __stdcall GLACTIVEPROGRAMEXT (GLuint program);
GLACTIVEPROGRAMEXT *glActiveProgramEXT;
typedef  GLuint __stdcall GLCREATESHADERPROGRAMEXT (GLenum type, const GLchar *string);
GLCREATESHADERPROGRAMEXT *glCreateShaderProgramEXT;
typedef  void __stdcall GLWINDOWRECTANGLESEXT (GLenum mode, GLsizei count, const GLint *box);
GLWINDOWRECTANGLESEXT *glWindowRectanglesEXT;
typedef  void __stdcall GLAPPLYFRAMEBUFFERATTACHMENTCMAAINTEL (void);
GLAPPLYFRAMEBUFFERATTACHMENTCMAAINTEL *glApplyFramebufferAttachmentCMAAINTEL;
typedef  void __stdcall GLBEGINPERFQUERYINTEL (GLuint queryHandle);
GLBEGINPERFQUERYINTEL *glBeginPerfQueryINTEL;
typedef  void __stdcall GLCREATEPERFQUERYINTEL (GLuint queryId, GLuint *queryHandle);
GLCREATEPERFQUERYINTEL *glCreatePerfQueryINTEL;
typedef  void __stdcall GLDELETEPERFQUERYINTEL (GLuint queryHandle);
GLDELETEPERFQUERYINTEL *glDeletePerfQueryINTEL;
typedef  void __stdcall GLENDPERFQUERYINTEL (GLuint queryHandle);
GLENDPERFQUERYINTEL *glEndPerfQueryINTEL;
typedef  void __stdcall GLGETFIRSTPERFQUERYIDINTEL (GLuint *queryId);
GLGETFIRSTPERFQUERYIDINTEL *glGetFirstPerfQueryIdINTEL;
typedef  void __stdcall GLGETNEXTPERFQUERYIDINTEL (GLuint queryId, GLuint *nextQueryId);
GLGETNEXTPERFQUERYIDINTEL *glGetNextPerfQueryIdINTEL;
typedef  void __stdcall GLGETPERFCOUNTERINFOINTEL (GLuint queryId, GLuint counterId, GLuint counterNameLength, GLchar *counterName, GLuint counterDescLength, GLchar *counterDesc, GLuint *counterOffset, GLuint *counterDataSize, GLuint *counterTypeEnum, GLuint *counterDataTypeEnum, GLuint64 *rawCounterMaxValue);
GLGETPERFCOUNTERINFOINTEL *glGetPerfCounterInfoINTEL;
typedef  void __stdcall GLGETPERFQUERYDATAINTEL (GLuint queryHandle, GLuint flags, GLsizei dataSize, GLvoid *data, GLuint *bytesWritten);
GLGETPERFQUERYDATAINTEL *glGetPerfQueryDataINTEL;
typedef  void __stdcall GLGETPERFQUERYIDBYNAMEINTEL (GLchar *queryName, GLuint *queryId);
GLGETPERFQUERYIDBYNAMEINTEL *glGetPerfQueryIdByNameINTEL;
typedef  void __stdcall GLGETPERFQUERYINFOINTEL (GLuint queryId, GLuint queryNameLength, GLchar *queryName, GLuint *dataSize, GLuint *noCounters, GLuint *noInstances, GLuint *capsMask);
GLGETPERFQUERYINFOINTEL *glGetPerfQueryInfoINTEL;
typedef  GLuint64 __stdcall GLGETTEXTUREHANDLENV (GLuint texture);
GLGETTEXTUREHANDLENV *glGetTextureHandleNV;
typedef  GLuint64 __stdcall GLGETTEXTURESAMPLERHANDLENV (GLuint texture, GLuint sampler);
GLGETTEXTURESAMPLERHANDLENV *glGetTextureSamplerHandleNV;
typedef  void __stdcall GLMAKETEXTUREHANDLERESIDENTNV (GLuint64 handle);
GLMAKETEXTUREHANDLERESIDENTNV *glMakeTextureHandleResidentNV;
typedef  void __stdcall GLMAKETEXTUREHANDLENONRESIDENTNV (GLuint64 handle);
GLMAKETEXTUREHANDLENONRESIDENTNV *glMakeTextureHandleNonResidentNV;
typedef  GLuint64 __stdcall GLGETIMAGEHANDLENV (GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
GLGETIMAGEHANDLENV *glGetImageHandleNV;
typedef  void __stdcall GLMAKEIMAGEHANDLERESIDENTNV (GLuint64 handle, GLenum access);
GLMAKEIMAGEHANDLERESIDENTNV *glMakeImageHandleResidentNV;
typedef  void __stdcall GLMAKEIMAGEHANDLENONRESIDENTNV (GLuint64 handle);
GLMAKEIMAGEHANDLENONRESIDENTNV *glMakeImageHandleNonResidentNV;
typedef  void __stdcall GLUNIFORMHANDLEUI64NV (GLint location, GLuint64 value);
GLUNIFORMHANDLEUI64NV *glUniformHandleui64NV;
typedef  void __stdcall GLUNIFORMHANDLEUI64VNV (GLint location, GLsizei count, const GLuint64 *value);
GLUNIFORMHANDLEUI64VNV *glUniformHandleui64vNV;
typedef  void __stdcall GLPROGRAMUNIFORMHANDLEUI64NV (GLuint program, GLint location, GLuint64 value);
GLPROGRAMUNIFORMHANDLEUI64NV *glProgramUniformHandleui64NV;
typedef  void __stdcall GLPROGRAMUNIFORMHANDLEUI64VNV (GLuint program, GLint location, GLsizei count, const GLuint64 *values);
GLPROGRAMUNIFORMHANDLEUI64VNV *glProgramUniformHandleui64vNV;
typedef  GLboolean __stdcall GLISTEXTUREHANDLERESIDENTNV (GLuint64 handle);
GLISTEXTUREHANDLERESIDENTNV *glIsTextureHandleResidentNV;
typedef  GLboolean __stdcall GLISIMAGEHANDLERESIDENTNV (GLuint64 handle);
GLISIMAGEHANDLERESIDENTNV *glIsImageHandleResidentNV;
typedef  void __stdcall GLBLENDPARAMETERINV (GLenum pname, GLint value);
GLBLENDPARAMETERINV *glBlendParameteriNV;
typedef  void __stdcall GLBLENDBARRIERNV (void);
GLBLENDBARRIERNV *glBlendBarrierNV;
typedef  void __stdcall GLBEGINCONDITIONALRENDERNV (GLuint id, GLenum mode);
GLBEGINCONDITIONALRENDERNV *glBeginConditionalRenderNV;
typedef  void __stdcall GLENDCONDITIONALRENDERNV (void);
GLENDCONDITIONALRENDERNV *glEndConditionalRenderNV;
typedef  void __stdcall GLSUBPIXELPRECISIONBIASNV (GLuint xbits, GLuint ybits);
GLSUBPIXELPRECISIONBIASNV *glSubpixelPrecisionBiasNV;
typedef  void __stdcall GLCONSERVATIVERASTERPARAMETERINV (GLenum pname, GLint param);
GLCONSERVATIVERASTERPARAMETERINV *glConservativeRasterParameteriNV;
typedef  void __stdcall GLDRAWVKIMAGENV (GLuint64 vkImage, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1);
GLDRAWVKIMAGENV *glDrawVkImageNV;
typedef  GLVULKANPROCNV __stdcall GLGETVKPROCADDRNV (const GLchar *name);
GLGETVKPROCADDRNV *glGetVkProcAddrNV;
typedef  void __stdcall GLWAITVKSEMAPHORENV (GLuint64 vkSemaphore);
GLWAITVKSEMAPHORENV *glWaitVkSemaphoreNV;
typedef  void __stdcall GLSIGNALVKSEMAPHORENV (GLuint64 vkSemaphore);
GLSIGNALVKSEMAPHORENV *glSignalVkSemaphoreNV;
typedef  void __stdcall GLSIGNALVKFENCENV (GLuint64 vkFence);
GLSIGNALVKFENCENV *glSignalVkFenceNV;
typedef  void __stdcall GLFRAGMENTCOVERAGECOLORNV (GLuint color);
GLFRAGMENTCOVERAGECOLORNV *glFragmentCoverageColorNV;
typedef  void __stdcall GLCOVERAGEMODULATIONTABLENV (GLsizei n, const GLfloat *v);
GLCOVERAGEMODULATIONTABLENV *glCoverageModulationTableNV;
typedef  void __stdcall GLGETCOVERAGEMODULATIONTABLENV (GLsizei bufsize, GLfloat *v);
GLGETCOVERAGEMODULATIONTABLENV *glGetCoverageModulationTableNV;
typedef  void __stdcall GLCOVERAGEMODULATIONNV (GLenum components);
GLCOVERAGEMODULATIONNV *glCoverageModulationNV;
typedef  void __stdcall GLUNIFORM1I64NV (GLint location, GLint64EXT x);
GLUNIFORM1I64NV *glUniform1i64NV;
typedef  void __stdcall GLUNIFORM2I64NV (GLint location, GLint64EXT x, GLint64EXT y);
GLUNIFORM2I64NV *glUniform2i64NV;
typedef  void __stdcall GLUNIFORM3I64NV (GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
GLUNIFORM3I64NV *glUniform3i64NV;
typedef  void __stdcall GLUNIFORM4I64NV (GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
GLUNIFORM4I64NV *glUniform4i64NV;
typedef  void __stdcall GLUNIFORM1I64VNV (GLint location, GLsizei count, const GLint64EXT *value);
GLUNIFORM1I64VNV *glUniform1i64vNV;
typedef  void __stdcall GLUNIFORM2I64VNV (GLint location, GLsizei count, const GLint64EXT *value);
GLUNIFORM2I64VNV *glUniform2i64vNV;
typedef  void __stdcall GLUNIFORM3I64VNV (GLint location, GLsizei count, const GLint64EXT *value);
GLUNIFORM3I64VNV *glUniform3i64vNV;
typedef  void __stdcall GLUNIFORM4I64VNV (GLint location, GLsizei count, const GLint64EXT *value);
GLUNIFORM4I64VNV *glUniform4i64vNV;
typedef  void __stdcall GLUNIFORM1UI64NV (GLint location, GLuint64EXT x);
GLUNIFORM1UI64NV *glUniform1ui64NV;
typedef  void __stdcall GLUNIFORM2UI64NV (GLint location, GLuint64EXT x, GLuint64EXT y);
GLUNIFORM2UI64NV *glUniform2ui64NV;
typedef  void __stdcall GLUNIFORM3UI64NV (GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
GLUNIFORM3UI64NV *glUniform3ui64NV;
typedef  void __stdcall GLUNIFORM4UI64NV (GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
GLUNIFORM4UI64NV *glUniform4ui64NV;
typedef  void __stdcall GLUNIFORM1UI64VNV (GLint location, GLsizei count, const GLuint64EXT *value);
GLUNIFORM1UI64VNV *glUniform1ui64vNV;
typedef  void __stdcall GLUNIFORM2UI64VNV (GLint location, GLsizei count, const GLuint64EXT *value);
GLUNIFORM2UI64VNV *glUniform2ui64vNV;
typedef  void __stdcall GLUNIFORM3UI64VNV (GLint location, GLsizei count, const GLuint64EXT *value);
GLUNIFORM3UI64VNV *glUniform3ui64vNV;
typedef  void __stdcall GLUNIFORM4UI64VNV (GLint location, GLsizei count, const GLuint64EXT *value);
GLUNIFORM4UI64VNV *glUniform4ui64vNV;
typedef  void __stdcall GLGETUNIFORMI64VNV (GLuint program, GLint location, GLint64EXT *params);
GLGETUNIFORMI64VNV *glGetUniformi64vNV;
typedef  void __stdcall GLPROGRAMUNIFORM1I64NV (GLuint program, GLint location, GLint64EXT x);
GLPROGRAMUNIFORM1I64NV *glProgramUniform1i64NV;
typedef  void __stdcall GLPROGRAMUNIFORM2I64NV (GLuint program, GLint location, GLint64EXT x, GLint64EXT y);
GLPROGRAMUNIFORM2I64NV *glProgramUniform2i64NV;
typedef  void __stdcall GLPROGRAMUNIFORM3I64NV (GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
GLPROGRAMUNIFORM3I64NV *glProgramUniform3i64NV;
typedef  void __stdcall GLPROGRAMUNIFORM4I64NV (GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
GLPROGRAMUNIFORM4I64NV *glProgramUniform4i64NV;
typedef  void __stdcall GLPROGRAMUNIFORM1I64VNV (GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
GLPROGRAMUNIFORM1I64VNV *glProgramUniform1i64vNV;
typedef  void __stdcall GLPROGRAMUNIFORM2I64VNV (GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
GLPROGRAMUNIFORM2I64VNV *glProgramUniform2i64vNV;
typedef  void __stdcall GLPROGRAMUNIFORM3I64VNV (GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
GLPROGRAMUNIFORM3I64VNV *glProgramUniform3i64vNV;
typedef  void __stdcall GLPROGRAMUNIFORM4I64VNV (GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
GLPROGRAMUNIFORM4I64VNV *glProgramUniform4i64vNV;
typedef  void __stdcall GLPROGRAMUNIFORM1UI64NV (GLuint program, GLint location, GLuint64EXT x);
GLPROGRAMUNIFORM1UI64NV *glProgramUniform1ui64NV;
typedef  void __stdcall GLPROGRAMUNIFORM2UI64NV (GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y);
GLPROGRAMUNIFORM2UI64NV *glProgramUniform2ui64NV;
typedef  void __stdcall GLPROGRAMUNIFORM3UI64NV (GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
GLPROGRAMUNIFORM3UI64NV *glProgramUniform3ui64NV;
typedef  void __stdcall GLPROGRAMUNIFORM4UI64NV (GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
GLPROGRAMUNIFORM4UI64NV *glProgramUniform4ui64NV;
typedef  void __stdcall GLPROGRAMUNIFORM1UI64VNV (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
GLPROGRAMUNIFORM1UI64VNV *glProgramUniform1ui64vNV;
typedef  void __stdcall GLPROGRAMUNIFORM2UI64VNV (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
GLPROGRAMUNIFORM2UI64VNV *glProgramUniform2ui64vNV;
typedef  void __stdcall GLPROGRAMUNIFORM3UI64VNV (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
GLPROGRAMUNIFORM3UI64VNV *glProgramUniform3ui64vNV;
typedef  void __stdcall GLPROGRAMUNIFORM4UI64VNV (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
GLPROGRAMUNIFORM4UI64VNV *glProgramUniform4ui64vNV;
typedef  void __stdcall GLGETINTERNALFORMATSAMPLEIVNV (GLenum target, GLenum internalformat, GLsizei samples, GLenum pname, GLsizei bufSize, GLint *params);
GLGETINTERNALFORMATSAMPLEIVNV *glGetInternalformatSampleivNV;
typedef  GLuint __stdcall GLGENPATHSNV (GLsizei range);
GLGENPATHSNV *glGenPathsNV;
typedef  void __stdcall GLDELETEPATHSNV (GLuint path, GLsizei range);
GLDELETEPATHSNV *glDeletePathsNV;
typedef  GLboolean __stdcall GLISPATHNV (GLuint path);
GLISPATHNV *glIsPathNV;
typedef  void __stdcall GLPATHCOMMANDSNV (GLuint path, GLsizei numCommands, const GLubyte *commands, GLsizei numCoords, GLenum coordType, const void *coords);
GLPATHCOMMANDSNV *glPathCommandsNV;
typedef  void __stdcall GLPATHCOORDSNV (GLuint path, GLsizei numCoords, GLenum coordType, const void *coords);
GLPATHCOORDSNV *glPathCoordsNV;
typedef  void __stdcall GLPATHSUBCOMMANDSNV (GLuint path, GLsizei commandStart, GLsizei commandsToDelete, GLsizei numCommands, const GLubyte *commands, GLsizei numCoords, GLenum coordType, const void *coords);
GLPATHSUBCOMMANDSNV *glPathSubCommandsNV;
typedef  void __stdcall GLPATHSUBCOORDSNV (GLuint path, GLsizei coordStart, GLsizei numCoords, GLenum coordType, const void *coords);
GLPATHSUBCOORDSNV *glPathSubCoordsNV;
typedef  void __stdcall GLPATHSTRINGNV (GLuint path, GLenum format, GLsizei length, const void *pathString);
GLPATHSTRINGNV *glPathStringNV;
typedef  void __stdcall GLPATHGLYPHSNV (GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLsizei numGlyphs, GLenum type, const void *charcodes, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
GLPATHGLYPHSNV *glPathGlyphsNV;
typedef  void __stdcall GLPATHGLYPHRANGENV (GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint firstGlyph, GLsizei numGlyphs, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
GLPATHGLYPHRANGENV *glPathGlyphRangeNV;
typedef  void __stdcall GLWEIGHTPATHSNV (GLuint resultPath, GLsizei numPaths, const GLuint *paths, const GLfloat *weights);
GLWEIGHTPATHSNV *glWeightPathsNV;
typedef  void __stdcall GLCOPYPATHNV (GLuint resultPath, GLuint srcPath);
GLCOPYPATHNV *glCopyPathNV;
typedef  void __stdcall GLINTERPOLATEPATHSNV (GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight);
GLINTERPOLATEPATHSNV *glInterpolatePathsNV;
typedef  void __stdcall GLTRANSFORMPATHNV (GLuint resultPath, GLuint srcPath, GLenum transformType, const GLfloat *transformValues);
GLTRANSFORMPATHNV *glTransformPathNV;
typedef  void __stdcall GLPATHPARAMETERIVNV (GLuint path, GLenum pname, const GLint *value);
GLPATHPARAMETERIVNV *glPathParameterivNV;
typedef  void __stdcall GLPATHPARAMETERINV (GLuint path, GLenum pname, GLint value);
GLPATHPARAMETERINV *glPathParameteriNV;
typedef  void __stdcall GLPATHPARAMETERFVNV (GLuint path, GLenum pname, const GLfloat *value);
GLPATHPARAMETERFVNV *glPathParameterfvNV;
typedef  void __stdcall GLPATHPARAMETERFNV (GLuint path, GLenum pname, GLfloat value);
GLPATHPARAMETERFNV *glPathParameterfNV;
typedef  void __stdcall GLPATHDASHARRAYNV (GLuint path, GLsizei dashCount, const GLfloat *dashArray);
GLPATHDASHARRAYNV *glPathDashArrayNV;
typedef  void __stdcall GLPATHSTENCILFUNCNV (GLenum func, GLint ref, GLuint mask);
GLPATHSTENCILFUNCNV *glPathStencilFuncNV;
typedef  void __stdcall GLPATHSTENCILDEPTHOFFSETNV (GLfloat factor, GLfloat units);
GLPATHSTENCILDEPTHOFFSETNV *glPathStencilDepthOffsetNV;
typedef  void __stdcall GLSTENCILFILLPATHNV (GLuint path, GLenum fillMode, GLuint mask);
GLSTENCILFILLPATHNV *glStencilFillPathNV;
typedef  void __stdcall GLSTENCILSTROKEPATHNV (GLuint path, GLint reference, GLuint mask);
GLSTENCILSTROKEPATHNV *glStencilStrokePathNV;
typedef  void __stdcall GLSTENCILFILLPATHINSTANCEDNV (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum transformType, const GLfloat *transformValues);
GLSTENCILFILLPATHINSTANCEDNV *glStencilFillPathInstancedNV;
typedef  void __stdcall GLSTENCILSTROKEPATHINSTANCEDNV (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLint reference, GLuint mask, GLenum transformType, const GLfloat *transformValues);
GLSTENCILSTROKEPATHINSTANCEDNV *glStencilStrokePathInstancedNV;
typedef  void __stdcall GLPATHCOVERDEPTHFUNCNV (GLenum func);
GLPATHCOVERDEPTHFUNCNV *glPathCoverDepthFuncNV;
typedef  void __stdcall GLCOVERFILLPATHNV (GLuint path, GLenum coverMode);
GLCOVERFILLPATHNV *glCoverFillPathNV;
typedef  void __stdcall GLCOVERSTROKEPATHNV (GLuint path, GLenum coverMode);
GLCOVERSTROKEPATHNV *glCoverStrokePathNV;
typedef  void __stdcall GLCOVERFILLPATHINSTANCEDNV (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
GLCOVERFILLPATHINSTANCEDNV *glCoverFillPathInstancedNV;
typedef  void __stdcall GLCOVERSTROKEPATHINSTANCEDNV (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
GLCOVERSTROKEPATHINSTANCEDNV *glCoverStrokePathInstancedNV;
typedef  void __stdcall GLGETPATHPARAMETERIVNV (GLuint path, GLenum pname, GLint *value);
GLGETPATHPARAMETERIVNV *glGetPathParameterivNV;
typedef  void __stdcall GLGETPATHPARAMETERFVNV (GLuint path, GLenum pname, GLfloat *value);
GLGETPATHPARAMETERFVNV *glGetPathParameterfvNV;
typedef  void __stdcall GLGETPATHCOMMANDSNV (GLuint path, GLubyte *commands);
GLGETPATHCOMMANDSNV *glGetPathCommandsNV;
typedef  void __stdcall GLGETPATHCOORDSNV (GLuint path, GLfloat *coords);
GLGETPATHCOORDSNV *glGetPathCoordsNV;
typedef  void __stdcall GLGETPATHDASHARRAYNV (GLuint path, GLfloat *dashArray);
GLGETPATHDASHARRAYNV *glGetPathDashArrayNV;
typedef  void __stdcall GLGETPATHMETRICSNV (GLbitfield metricQueryMask, GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLsizei stride, GLfloat *metrics);
GLGETPATHMETRICSNV *glGetPathMetricsNV;
typedef  void __stdcall GLGETPATHMETRICRANGENV (GLbitfield metricQueryMask, GLuint firstPathName, GLsizei numPaths, GLsizei stride, GLfloat *metrics);
GLGETPATHMETRICRANGENV *glGetPathMetricRangeNV;
typedef  void __stdcall GLGETPATHSPACINGNV (GLenum pathListMode, GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLfloat advanceScale, GLfloat kerningScale, GLenum transformType, GLfloat *returnedSpacing);
GLGETPATHSPACINGNV *glGetPathSpacingNV;
typedef  GLboolean __stdcall GLISPOINTINFILLPATHNV (GLuint path, GLuint mask, GLfloat x, GLfloat y);
GLISPOINTINFILLPATHNV *glIsPointInFillPathNV;
typedef  GLboolean __stdcall GLISPOINTINSTROKEPATHNV (GLuint path, GLfloat x, GLfloat y);
GLISPOINTINSTROKEPATHNV *glIsPointInStrokePathNV;
typedef  GLfloat __stdcall GLGETPATHLENGTHNV (GLuint path, GLsizei startSegment, GLsizei numSegments);
GLGETPATHLENGTHNV *glGetPathLengthNV;
typedef  GLboolean __stdcall GLPOINTALONGPATHNV (GLuint path, GLsizei startSegment, GLsizei numSegments, GLfloat distance, GLfloat *x, GLfloat *y, GLfloat *tangentX, GLfloat *tangentY);
GLPOINTALONGPATHNV *glPointAlongPathNV;
typedef  void __stdcall GLMATRIXLOAD3X2FNV (GLenum matrixMode, const GLfloat *m);
GLMATRIXLOAD3X2FNV *glMatrixLoad3x2fNV;
typedef  void __stdcall GLMATRIXLOAD3X3FNV (GLenum matrixMode, const GLfloat *m);
GLMATRIXLOAD3X3FNV *glMatrixLoad3x3fNV;
typedef  void __stdcall GLMATRIXLOADTRANSPOSE3X3FNV (GLenum matrixMode, const GLfloat *m);
GLMATRIXLOADTRANSPOSE3X3FNV *glMatrixLoadTranspose3x3fNV;
typedef  void __stdcall GLMATRIXMULT3X2FNV (GLenum matrixMode, const GLfloat *m);
GLMATRIXMULT3X2FNV *glMatrixMult3x2fNV;
typedef  void __stdcall GLMATRIXMULT3X3FNV (GLenum matrixMode, const GLfloat *m);
GLMATRIXMULT3X3FNV *glMatrixMult3x3fNV;
typedef  void __stdcall GLMATRIXMULTTRANSPOSE3X3FNV (GLenum matrixMode, const GLfloat *m);
GLMATRIXMULTTRANSPOSE3X3FNV *glMatrixMultTranspose3x3fNV;
typedef  void __stdcall GLSTENCILTHENCOVERFILLPATHNV (GLuint path, GLenum fillMode, GLuint mask, GLenum coverMode);
GLSTENCILTHENCOVERFILLPATHNV *glStencilThenCoverFillPathNV;
typedef  void __stdcall GLSTENCILTHENCOVERSTROKEPATHNV (GLuint path, GLint reference, GLuint mask, GLenum coverMode);
GLSTENCILTHENCOVERSTROKEPATHNV *glStencilThenCoverStrokePathNV;
typedef  void __stdcall GLSTENCILTHENCOVERFILLPATHINSTANCEDNV (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
GLSTENCILTHENCOVERFILLPATHINSTANCEDNV *glStencilThenCoverFillPathInstancedNV;
typedef  void __stdcall GLSTENCILTHENCOVERSTROKEPATHINSTANCEDNV (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLint reference, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
GLSTENCILTHENCOVERSTROKEPATHINSTANCEDNV *glStencilThenCoverStrokePathInstancedNV;
typedef  GLenum __stdcall GLPATHGLYPHINDEXRANGENV (GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint pathParameterTemplate, GLfloat emScale, GLuint baseAndCount[2]);
GLPATHGLYPHINDEXRANGENV *glPathGlyphIndexRangeNV;
typedef  GLenum __stdcall GLPATHGLYPHINDEXARRAYNV (GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
GLPATHGLYPHINDEXARRAYNV *glPathGlyphIndexArrayNV;
typedef  GLenum __stdcall GLPATHMEMORYGLYPHINDEXARRAYNV (GLuint firstPathName, GLenum fontTarget, GLsizeiptr fontSize, const void *fontData, GLsizei faceIndex, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
GLPATHMEMORYGLYPHINDEXARRAYNV *glPathMemoryGlyphIndexArrayNV;
typedef  void __stdcall GLPROGRAMPATHFRAGMENTINPUTGENNV (GLuint program, GLint location, GLenum genMode, GLint components, const GLfloat *coeffs);
GLPROGRAMPATHFRAGMENTINPUTGENNV *glProgramPathFragmentInputGenNV;
typedef  void __stdcall GLGETPROGRAMRESOURCEFVNV (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLfloat *params);
GLGETPROGRAMRESOURCEFVNV *glGetProgramResourcefvNV;
typedef  void __stdcall GLFRAMEBUFFERSAMPLELOCATIONSFVNV (GLenum target, GLuint start, GLsizei count, const GLfloat *v);
GLFRAMEBUFFERSAMPLELOCATIONSFVNV *glFramebufferSampleLocationsfvNV;
typedef  void __stdcall GLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVNV (GLuint framebuffer, GLuint start, GLsizei count, const GLfloat *v);
GLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVNV *glNamedFramebufferSampleLocationsfvNV;
typedef  void __stdcall GLRESOLVEDEPTHVALUESNV (void);
GLRESOLVEDEPTHVALUESNV *glResolveDepthValuesNV;
typedef  void __stdcall GLVIEWPORTSWIZZLENV (GLuint index, GLenum swizzlex, GLenum swizzley, GLenum swizzlez, GLenum swizzlew);
GLVIEWPORTSWIZZLENV *glViewportSwizzleNV;
typedef  void __stdcall GLFRAMEBUFFERTEXTUREMULTIVIEWOVR (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint baseViewIndex, GLsizei numViews);
GLFRAMEBUFFERTEXTUREMULTIVIEWOVR *glFramebufferTextureMultiviewOVR;

typedef void *load_function(char *FunctionName);
void LoadGLFunctions(load_function *LoadFunction) {
    glCullFace = (GLCULLFACE*)LoadFunction("glCullFace");
    glFrontFace = (GLFRONTFACE*)LoadFunction("glFrontFace");
    glHint = (GLHINT*)LoadFunction("glHint");
    glLineWidth = (GLLINEWIDTH*)LoadFunction("glLineWidth");
    glPointSize = (GLPOINTSIZE*)LoadFunction("glPointSize");
    glPolygonMode = (GLPOLYGONMODE*)LoadFunction("glPolygonMode");
    glScissor = (GLSCISSOR*)LoadFunction("glScissor");
    glTexParameterf = (GLTEXPARAMETERF*)LoadFunction("glTexParameterf");
    glTexParameterfv = (GLTEXPARAMETERFV*)LoadFunction("glTexParameterfv");
    glTexParameteri = (GLTEXPARAMETERI*)LoadFunction("glTexParameteri");
    glTexParameteriv = (GLTEXPARAMETERIV*)LoadFunction("glTexParameteriv");
    glTexImage1D = (GLTEXIMAGE1D*)LoadFunction("glTexImage1D");
    glTexImage2D = (GLTEXIMAGE2D*)LoadFunction("glTexImage2D");
    glDrawBuffer = (GLDRAWBUFFER*)LoadFunction("glDrawBuffer");
    glClear = (GLCLEAR*)LoadFunction("glClear");
    glClearColor = (GLCLEARCOLOR*)LoadFunction("glClearColor");
    glClearStencil = (GLCLEARSTENCIL*)LoadFunction("glClearStencil");
    glClearDepth = (GLCLEARDEPTH*)LoadFunction("glClearDepth");
    glStencilMask = (GLSTENCILMASK*)LoadFunction("glStencilMask");
    glColorMask = (GLCOLORMASK*)LoadFunction("glColorMask");
    glDepthMask = (GLDEPTHMASK*)LoadFunction("glDepthMask");
    glDisable = (GLDISABLE*)LoadFunction("glDisable");
    glEnable = (GLENABLE*)LoadFunction("glEnable");
    glFinish = (GLFINISH*)LoadFunction("glFinish");
    glFlush = (GLFLUSH*)LoadFunction("glFlush");
    glBlendFunc = (GLBLENDFUNC*)LoadFunction("glBlendFunc");
    glLogicOp = (GLLOGICOP*)LoadFunction("glLogicOp");
    glStencilFunc = (GLSTENCILFUNC*)LoadFunction("glStencilFunc");
    glStencilOp = (GLSTENCILOP*)LoadFunction("glStencilOp");
    glDepthFunc = (GLDEPTHFUNC*)LoadFunction("glDepthFunc");
    glPixelStoref = (GLPIXELSTOREF*)LoadFunction("glPixelStoref");
    glPixelStorei = (GLPIXELSTOREI*)LoadFunction("glPixelStorei");
    glReadBuffer = (GLREADBUFFER*)LoadFunction("glReadBuffer");
    glReadPixels = (GLREADPIXELS*)LoadFunction("glReadPixels");
    glGetBooleanv = (GLGETBOOLEANV*)LoadFunction("glGetBooleanv");
    glGetDoublev = (GLGETDOUBLEV*)LoadFunction("glGetDoublev");
    glGetError = (GLGETERROR*)LoadFunction("glGetError");
    glGetFloatv = (GLGETFLOATV*)LoadFunction("glGetFloatv");
    glGetIntegerv = (GLGETINTEGERV*)LoadFunction("glGetIntegerv");
    glGetString = (GLGETSTRING*)LoadFunction("glGetString");
    glGetTexImage = (GLGETTEXIMAGE*)LoadFunction("glGetTexImage");
    glGetTexParameterfv = (GLGETTEXPARAMETERFV*)LoadFunction("glGetTexParameterfv");
    glGetTexParameteriv = (GLGETTEXPARAMETERIV*)LoadFunction("glGetTexParameteriv");
    glGetTexLevelParameterfv = (GLGETTEXLEVELPARAMETERFV*)LoadFunction("glGetTexLevelParameterfv");
    glGetTexLevelParameteriv = (GLGETTEXLEVELPARAMETERIV*)LoadFunction("glGetTexLevelParameteriv");
    glIsEnabled = (GLISENABLED*)LoadFunction("glIsEnabled");
    glDepthRange = (GLDEPTHRANGE*)LoadFunction("glDepthRange");
    glViewport = (GLVIEWPORT*)LoadFunction("glViewport");
    glDrawArrays = (GLDRAWARRAYS*)LoadFunction("glDrawArrays");
    glDrawElements = (GLDRAWELEMENTS*)LoadFunction("glDrawElements");
    glGetPointerv = (GLGETPOINTERV*)LoadFunction("glGetPointerv");
    glPolygonOffset = (GLPOLYGONOFFSET*)LoadFunction("glPolygonOffset");
    glCopyTexImage1D = (GLCOPYTEXIMAGE1D*)LoadFunction("glCopyTexImage1D");
    glCopyTexImage2D = (GLCOPYTEXIMAGE2D*)LoadFunction("glCopyTexImage2D");
    glCopyTexSubImage1D = (GLCOPYTEXSUBIMAGE1D*)LoadFunction("glCopyTexSubImage1D");
    glCopyTexSubImage2D = (GLCOPYTEXSUBIMAGE2D*)LoadFunction("glCopyTexSubImage2D");
    glTexSubImage1D = (GLTEXSUBIMAGE1D*)LoadFunction("glTexSubImage1D");
    glTexSubImage2D = (GLTEXSUBIMAGE2D*)LoadFunction("glTexSubImage2D");
    glBindTexture = (GLBINDTEXTURE*)LoadFunction("glBindTexture");
    glDeleteTextures = (GLDELETETEXTURES*)LoadFunction("glDeleteTextures");
    glGenTextures = (GLGENTEXTURES*)LoadFunction("glGenTextures");
    glIsTexture = (GLISTEXTURE*)LoadFunction("glIsTexture");
    glDrawRangeElements = (GLDRAWRANGEELEMENTS*)LoadFunction("glDrawRangeElements");
    glTexImage3D = (GLTEXIMAGE3D*)LoadFunction("glTexImage3D");
    glTexSubImage3D = (GLTEXSUBIMAGE3D*)LoadFunction("glTexSubImage3D");
    glCopyTexSubImage3D = (GLCOPYTEXSUBIMAGE3D*)LoadFunction("glCopyTexSubImage3D");
    glActiveTexture = (GLACTIVETEXTURE*)LoadFunction("glActiveTexture");
    glSampleCoverage = (GLSAMPLECOVERAGE*)LoadFunction("glSampleCoverage");
    glCompressedTexImage3D = (GLCOMPRESSEDTEXIMAGE3D*)LoadFunction("glCompressedTexImage3D");
    glCompressedTexImage2D = (GLCOMPRESSEDTEXIMAGE2D*)LoadFunction("glCompressedTexImage2D");
    glCompressedTexImage1D = (GLCOMPRESSEDTEXIMAGE1D*)LoadFunction("glCompressedTexImage1D");
    glCompressedTexSubImage3D = (GLCOMPRESSEDTEXSUBIMAGE3D*)LoadFunction("glCompressedTexSubImage3D");
    glCompressedTexSubImage2D = (GLCOMPRESSEDTEXSUBIMAGE2D*)LoadFunction("glCompressedTexSubImage2D");
    glCompressedTexSubImage1D = (GLCOMPRESSEDTEXSUBIMAGE1D*)LoadFunction("glCompressedTexSubImage1D");
    glGetCompressedTexImage = (GLGETCOMPRESSEDTEXIMAGE*)LoadFunction("glGetCompressedTexImage");
    glBlendFuncSeparate = (GLBLENDFUNCSEPARATE*)LoadFunction("glBlendFuncSeparate");
    glMultiDrawArrays = (GLMULTIDRAWARRAYS*)LoadFunction("glMultiDrawArrays");
    glMultiDrawElements = (GLMULTIDRAWELEMENTS*)LoadFunction("glMultiDrawElements");
    glPointParameterf = (GLPOINTPARAMETERF*)LoadFunction("glPointParameterf");
    glPointParameterfv = (GLPOINTPARAMETERFV*)LoadFunction("glPointParameterfv");
    glPointParameteri = (GLPOINTPARAMETERI*)LoadFunction("glPointParameteri");
    glPointParameteriv = (GLPOINTPARAMETERIV*)LoadFunction("glPointParameteriv");
    glBlendColor = (GLBLENDCOLOR*)LoadFunction("glBlendColor");
    glBlendEquation = (GLBLENDEQUATION*)LoadFunction("glBlendEquation");
    glGenQueries = (GLGENQUERIES*)LoadFunction("glGenQueries");
    glDeleteQueries = (GLDELETEQUERIES*)LoadFunction("glDeleteQueries");
    glIsQuery = (GLISQUERY*)LoadFunction("glIsQuery");
    glBeginQuery = (GLBEGINQUERY*)LoadFunction("glBeginQuery");
    glEndQuery = (GLENDQUERY*)LoadFunction("glEndQuery");
    glGetQueryiv = (GLGETQUERYIV*)LoadFunction("glGetQueryiv");
    glGetQueryObjectiv = (GLGETQUERYOBJECTIV*)LoadFunction("glGetQueryObjectiv");
    glGetQueryObjectuiv = (GLGETQUERYOBJECTUIV*)LoadFunction("glGetQueryObjectuiv");
    glBindBuffer = (GLBINDBUFFER*)LoadFunction("glBindBuffer");
    glDeleteBuffers = (GLDELETEBUFFERS*)LoadFunction("glDeleteBuffers");
    glGenBuffers = (GLGENBUFFERS*)LoadFunction("glGenBuffers");
    glIsBuffer = (GLISBUFFER*)LoadFunction("glIsBuffer");
    glBufferData = (GLBUFFERDATA*)LoadFunction("glBufferData");
    glBufferSubData = (GLBUFFERSUBDATA*)LoadFunction("glBufferSubData");
    glGetBufferSubData = (GLGETBUFFERSUBDATA*)LoadFunction("glGetBufferSubData");
    glMapBuffer = (GLMAPBUFFER*)LoadFunction("glMapBuffer");
    glUnmapBuffer = (GLUNMAPBUFFER*)LoadFunction("glUnmapBuffer");
    glGetBufferParameteriv = (GLGETBUFFERPARAMETERIV*)LoadFunction("glGetBufferParameteriv");
    glGetBufferPointerv = (GLGETBUFFERPOINTERV*)LoadFunction("glGetBufferPointerv");
    glBlendEquationSeparate = (GLBLENDEQUATIONSEPARATE*)LoadFunction("glBlendEquationSeparate");
    glDrawBuffers = (GLDRAWBUFFERS*)LoadFunction("glDrawBuffers");
    glStencilOpSeparate = (GLSTENCILOPSEPARATE*)LoadFunction("glStencilOpSeparate");
    glStencilFuncSeparate = (GLSTENCILFUNCSEPARATE*)LoadFunction("glStencilFuncSeparate");
    glStencilMaskSeparate = (GLSTENCILMASKSEPARATE*)LoadFunction("glStencilMaskSeparate");
    glAttachShader = (GLATTACHSHADER*)LoadFunction("glAttachShader");
    glBindAttribLocation = (GLBINDATTRIBLOCATION*)LoadFunction("glBindAttribLocation");
    glCompileShader = (GLCOMPILESHADER*)LoadFunction("glCompileShader");
    glCreateProgram = (GLCREATEPROGRAM*)LoadFunction("glCreateProgram");
    glCreateShader = (GLCREATESHADER*)LoadFunction("glCreateShader");
    glDeleteProgram = (GLDELETEPROGRAM*)LoadFunction("glDeleteProgram");
    glDeleteShader = (GLDELETESHADER*)LoadFunction("glDeleteShader");
    glDetachShader = (GLDETACHSHADER*)LoadFunction("glDetachShader");
    glDisableVertexAttribArray = (GLDISABLEVERTEXATTRIBARRAY*)LoadFunction("glDisableVertexAttribArray");
    glEnableVertexAttribArray = (GLENABLEVERTEXATTRIBARRAY*)LoadFunction("glEnableVertexAttribArray");
    glGetActiveAttrib = (GLGETACTIVEATTRIB*)LoadFunction("glGetActiveAttrib");
    glGetActiveUniform = (GLGETACTIVEUNIFORM*)LoadFunction("glGetActiveUniform");
    glGetAttachedShaders = (GLGETATTACHEDSHADERS*)LoadFunction("glGetAttachedShaders");
    glGetAttribLocation = (GLGETATTRIBLOCATION*)LoadFunction("glGetAttribLocation");
    glGetProgramiv = (GLGETPROGRAMIV*)LoadFunction("glGetProgramiv");
    glGetProgramInfoLog = (GLGETPROGRAMINFOLOG*)LoadFunction("glGetProgramInfoLog");
    glGetShaderiv = (GLGETSHADERIV*)LoadFunction("glGetShaderiv");
    glGetShaderInfoLog = (GLGETSHADERINFOLOG*)LoadFunction("glGetShaderInfoLog");
    glGetShaderSource = (GLGETSHADERSOURCE*)LoadFunction("glGetShaderSource");
    glGetUniformLocation = (GLGETUNIFORMLOCATION*)LoadFunction("glGetUniformLocation");
    glGetUniformfv = (GLGETUNIFORMFV*)LoadFunction("glGetUniformfv");
    glGetUniformiv = (GLGETUNIFORMIV*)LoadFunction("glGetUniformiv");
    glGetVertexAttribdv = (GLGETVERTEXATTRIBDV*)LoadFunction("glGetVertexAttribdv");
    glGetVertexAttribfv = (GLGETVERTEXATTRIBFV*)LoadFunction("glGetVertexAttribfv");
    glGetVertexAttribiv = (GLGETVERTEXATTRIBIV*)LoadFunction("glGetVertexAttribiv");
    glGetVertexAttribPointerv = (GLGETVERTEXATTRIBPOINTERV*)LoadFunction("glGetVertexAttribPointerv");
    glIsProgram = (GLISPROGRAM*)LoadFunction("glIsProgram");
    glIsShader = (GLISSHADER*)LoadFunction("glIsShader");
    glLinkProgram = (GLLINKPROGRAM*)LoadFunction("glLinkProgram");
    glShaderSource = (GLSHADERSOURCE*)LoadFunction("glShaderSource");
    glUseProgram = (GLUSEPROGRAM*)LoadFunction("glUseProgram");
    glUniform1f = (GLUNIFORM1F*)LoadFunction("glUniform1f");
    glUniform2f = (GLUNIFORM2F*)LoadFunction("glUniform2f");
    glUniform3f = (GLUNIFORM3F*)LoadFunction("glUniform3f");
    glUniform4f = (GLUNIFORM4F*)LoadFunction("glUniform4f");
    glUniform1i = (GLUNIFORM1I*)LoadFunction("glUniform1i");
    glUniform2i = (GLUNIFORM2I*)LoadFunction("glUniform2i");
    glUniform3i = (GLUNIFORM3I*)LoadFunction("glUniform3i");
    glUniform4i = (GLUNIFORM4I*)LoadFunction("glUniform4i");
    glUniform1fv = (GLUNIFORM1FV*)LoadFunction("glUniform1fv");
    glUniform2fv = (GLUNIFORM2FV*)LoadFunction("glUniform2fv");
    glUniform3fv = (GLUNIFORM3FV*)LoadFunction("glUniform3fv");
    glUniform4fv = (GLUNIFORM4FV*)LoadFunction("glUniform4fv");
    glUniform1iv = (GLUNIFORM1IV*)LoadFunction("glUniform1iv");
    glUniform2iv = (GLUNIFORM2IV*)LoadFunction("glUniform2iv");
    glUniform3iv = (GLUNIFORM3IV*)LoadFunction("glUniform3iv");
    glUniform4iv = (GLUNIFORM4IV*)LoadFunction("glUniform4iv");
    glUniformMatrix2fv = (GLUNIFORMMATRIX2FV*)LoadFunction("glUniformMatrix2fv");
    glUniformMatrix3fv = (GLUNIFORMMATRIX3FV*)LoadFunction("glUniformMatrix3fv");
    glUniformMatrix4fv = (GLUNIFORMMATRIX4FV*)LoadFunction("glUniformMatrix4fv");
    glValidateProgram = (GLVALIDATEPROGRAM*)LoadFunction("glValidateProgram");
    glVertexAttrib1d = (GLVERTEXATTRIB1D*)LoadFunction("glVertexAttrib1d");
    glVertexAttrib1dv = (GLVERTEXATTRIB1DV*)LoadFunction("glVertexAttrib1dv");
    glVertexAttrib1f = (GLVERTEXATTRIB1F*)LoadFunction("glVertexAttrib1f");
    glVertexAttrib1fv = (GLVERTEXATTRIB1FV*)LoadFunction("glVertexAttrib1fv");
    glVertexAttrib1s = (GLVERTEXATTRIB1S*)LoadFunction("glVertexAttrib1s");
    glVertexAttrib1sv = (GLVERTEXATTRIB1SV*)LoadFunction("glVertexAttrib1sv");
    glVertexAttrib2d = (GLVERTEXATTRIB2D*)LoadFunction("glVertexAttrib2d");
    glVertexAttrib2dv = (GLVERTEXATTRIB2DV*)LoadFunction("glVertexAttrib2dv");
    glVertexAttrib2f = (GLVERTEXATTRIB2F*)LoadFunction("glVertexAttrib2f");
    glVertexAttrib2fv = (GLVERTEXATTRIB2FV*)LoadFunction("glVertexAttrib2fv");
    glVertexAttrib2s = (GLVERTEXATTRIB2S*)LoadFunction("glVertexAttrib2s");
    glVertexAttrib2sv = (GLVERTEXATTRIB2SV*)LoadFunction("glVertexAttrib2sv");
    glVertexAttrib3d = (GLVERTEXATTRIB3D*)LoadFunction("glVertexAttrib3d");
    glVertexAttrib3dv = (GLVERTEXATTRIB3DV*)LoadFunction("glVertexAttrib3dv");
    glVertexAttrib3f = (GLVERTEXATTRIB3F*)LoadFunction("glVertexAttrib3f");
    glVertexAttrib3fv = (GLVERTEXATTRIB3FV*)LoadFunction("glVertexAttrib3fv");
    glVertexAttrib3s = (GLVERTEXATTRIB3S*)LoadFunction("glVertexAttrib3s");
    glVertexAttrib3sv = (GLVERTEXATTRIB3SV*)LoadFunction("glVertexAttrib3sv");
    glVertexAttrib4Nbv = (GLVERTEXATTRIB4NBV*)LoadFunction("glVertexAttrib4Nbv");
    glVertexAttrib4Niv = (GLVERTEXATTRIB4NIV*)LoadFunction("glVertexAttrib4Niv");
    glVertexAttrib4Nsv = (GLVERTEXATTRIB4NSV*)LoadFunction("glVertexAttrib4Nsv");
    glVertexAttrib4Nub = (GLVERTEXATTRIB4NUB*)LoadFunction("glVertexAttrib4Nub");
    glVertexAttrib4Nubv = (GLVERTEXATTRIB4NUBV*)LoadFunction("glVertexAttrib4Nubv");
    glVertexAttrib4Nuiv = (GLVERTEXATTRIB4NUIV*)LoadFunction("glVertexAttrib4Nuiv");
    glVertexAttrib4Nusv = (GLVERTEXATTRIB4NUSV*)LoadFunction("glVertexAttrib4Nusv");
    glVertexAttrib4bv = (GLVERTEXATTRIB4BV*)LoadFunction("glVertexAttrib4bv");
    glVertexAttrib4d = (GLVERTEXATTRIB4D*)LoadFunction("glVertexAttrib4d");
    glVertexAttrib4dv = (GLVERTEXATTRIB4DV*)LoadFunction("glVertexAttrib4dv");
    glVertexAttrib4f = (GLVERTEXATTRIB4F*)LoadFunction("glVertexAttrib4f");
    glVertexAttrib4fv = (GLVERTEXATTRIB4FV*)LoadFunction("glVertexAttrib4fv");
    glVertexAttrib4iv = (GLVERTEXATTRIB4IV*)LoadFunction("glVertexAttrib4iv");
    glVertexAttrib4s = (GLVERTEXATTRIB4S*)LoadFunction("glVertexAttrib4s");
    glVertexAttrib4sv = (GLVERTEXATTRIB4SV*)LoadFunction("glVertexAttrib4sv");
    glVertexAttrib4ubv = (GLVERTEXATTRIB4UBV*)LoadFunction("glVertexAttrib4ubv");
    glVertexAttrib4uiv = (GLVERTEXATTRIB4UIV*)LoadFunction("glVertexAttrib4uiv");
    glVertexAttrib4usv = (GLVERTEXATTRIB4USV*)LoadFunction("glVertexAttrib4usv");
    glVertexAttribPointer = (GLVERTEXATTRIBPOINTER*)LoadFunction("glVertexAttribPointer");
    glUniformMatrix2x3fv = (GLUNIFORMMATRIX2X3FV*)LoadFunction("glUniformMatrix2x3fv");
    glUniformMatrix3x2fv = (GLUNIFORMMATRIX3X2FV*)LoadFunction("glUniformMatrix3x2fv");
    glUniformMatrix2x4fv = (GLUNIFORMMATRIX2X4FV*)LoadFunction("glUniformMatrix2x4fv");
    glUniformMatrix4x2fv = (GLUNIFORMMATRIX4X2FV*)LoadFunction("glUniformMatrix4x2fv");
    glUniformMatrix3x4fv = (GLUNIFORMMATRIX3X4FV*)LoadFunction("glUniformMatrix3x4fv");
    glUniformMatrix4x3fv = (GLUNIFORMMATRIX4X3FV*)LoadFunction("glUniformMatrix4x3fv");
    glColorMaski = (GLCOLORMASKI*)LoadFunction("glColorMaski");
    glGetBooleani_v = (GLGETBOOLEANI_V*)LoadFunction("glGetBooleani_v");
    glGetIntegeri_v = (GLGETINTEGERI_V*)LoadFunction("glGetIntegeri_v");
    glEnablei = (GLENABLEI*)LoadFunction("glEnablei");
    glDisablei = (GLDISABLEI*)LoadFunction("glDisablei");
    glIsEnabledi = (GLISENABLEDI*)LoadFunction("glIsEnabledi");
    glBeginTransformFeedback = (GLBEGINTRANSFORMFEEDBACK*)LoadFunction("glBeginTransformFeedback");
    glEndTransformFeedback = (GLENDTRANSFORMFEEDBACK*)LoadFunction("glEndTransformFeedback");
    glBindBufferRange = (GLBINDBUFFERRANGE*)LoadFunction("glBindBufferRange");
    glBindBufferBase = (GLBINDBUFFERBASE*)LoadFunction("glBindBufferBase");
    glTransformFeedbackVaryings = (GLTRANSFORMFEEDBACKVARYINGS*)LoadFunction("glTransformFeedbackVaryings");
    glGetTransformFeedbackVarying = (GLGETTRANSFORMFEEDBACKVARYING*)LoadFunction("glGetTransformFeedbackVarying");
    glClampColor = (GLCLAMPCOLOR*)LoadFunction("glClampColor");
    glBeginConditionalRender = (GLBEGINCONDITIONALRENDER*)LoadFunction("glBeginConditionalRender");
    glEndConditionalRender = (GLENDCONDITIONALRENDER*)LoadFunction("glEndConditionalRender");
    glVertexAttribIPointer = (GLVERTEXATTRIBIPOINTER*)LoadFunction("glVertexAttribIPointer");
    glGetVertexAttribIiv = (GLGETVERTEXATTRIBIIV*)LoadFunction("glGetVertexAttribIiv");
    glGetVertexAttribIuiv = (GLGETVERTEXATTRIBIUIV*)LoadFunction("glGetVertexAttribIuiv");
    glVertexAttribI1i = (GLVERTEXATTRIBI1I*)LoadFunction("glVertexAttribI1i");
    glVertexAttribI2i = (GLVERTEXATTRIBI2I*)LoadFunction("glVertexAttribI2i");
    glVertexAttribI3i = (GLVERTEXATTRIBI3I*)LoadFunction("glVertexAttribI3i");
    glVertexAttribI4i = (GLVERTEXATTRIBI4I*)LoadFunction("glVertexAttribI4i");
    glVertexAttribI1ui = (GLVERTEXATTRIBI1UI*)LoadFunction("glVertexAttribI1ui");
    glVertexAttribI2ui = (GLVERTEXATTRIBI2UI*)LoadFunction("glVertexAttribI2ui");
    glVertexAttribI3ui = (GLVERTEXATTRIBI3UI*)LoadFunction("glVertexAttribI3ui");
    glVertexAttribI4ui = (GLVERTEXATTRIBI4UI*)LoadFunction("glVertexAttribI4ui");
    glVertexAttribI1iv = (GLVERTEXATTRIBI1IV*)LoadFunction("glVertexAttribI1iv");
    glVertexAttribI2iv = (GLVERTEXATTRIBI2IV*)LoadFunction("glVertexAttribI2iv");
    glVertexAttribI3iv = (GLVERTEXATTRIBI3IV*)LoadFunction("glVertexAttribI3iv");
    glVertexAttribI4iv = (GLVERTEXATTRIBI4IV*)LoadFunction("glVertexAttribI4iv");
    glVertexAttribI1uiv = (GLVERTEXATTRIBI1UIV*)LoadFunction("glVertexAttribI1uiv");
    glVertexAttribI2uiv = (GLVERTEXATTRIBI2UIV*)LoadFunction("glVertexAttribI2uiv");
    glVertexAttribI3uiv = (GLVERTEXATTRIBI3UIV*)LoadFunction("glVertexAttribI3uiv");
    glVertexAttribI4uiv = (GLVERTEXATTRIBI4UIV*)LoadFunction("glVertexAttribI4uiv");
    glVertexAttribI4bv = (GLVERTEXATTRIBI4BV*)LoadFunction("glVertexAttribI4bv");
    glVertexAttribI4sv = (GLVERTEXATTRIBI4SV*)LoadFunction("glVertexAttribI4sv");
    glVertexAttribI4ubv = (GLVERTEXATTRIBI4UBV*)LoadFunction("glVertexAttribI4ubv");
    glVertexAttribI4usv = (GLVERTEXATTRIBI4USV*)LoadFunction("glVertexAttribI4usv");
    glGetUniformuiv = (GLGETUNIFORMUIV*)LoadFunction("glGetUniformuiv");
    glBindFragDataLocation = (GLBINDFRAGDATALOCATION*)LoadFunction("glBindFragDataLocation");
    glGetFragDataLocation = (GLGETFRAGDATALOCATION*)LoadFunction("glGetFragDataLocation");
    glUniform1ui = (GLUNIFORM1UI*)LoadFunction("glUniform1ui");
    glUniform2ui = (GLUNIFORM2UI*)LoadFunction("glUniform2ui");
    glUniform3ui = (GLUNIFORM3UI*)LoadFunction("glUniform3ui");
    glUniform4ui = (GLUNIFORM4UI*)LoadFunction("glUniform4ui");
    glUniform1uiv = (GLUNIFORM1UIV*)LoadFunction("glUniform1uiv");
    glUniform2uiv = (GLUNIFORM2UIV*)LoadFunction("glUniform2uiv");
    glUniform3uiv = (GLUNIFORM3UIV*)LoadFunction("glUniform3uiv");
    glUniform4uiv = (GLUNIFORM4UIV*)LoadFunction("glUniform4uiv");
    glTexParameterIiv = (GLTEXPARAMETERIIV*)LoadFunction("glTexParameterIiv");
    glTexParameterIuiv = (GLTEXPARAMETERIUIV*)LoadFunction("glTexParameterIuiv");
    glGetTexParameterIiv = (GLGETTEXPARAMETERIIV*)LoadFunction("glGetTexParameterIiv");
    glGetTexParameterIuiv = (GLGETTEXPARAMETERIUIV*)LoadFunction("glGetTexParameterIuiv");
    glClearBufferiv = (GLCLEARBUFFERIV*)LoadFunction("glClearBufferiv");
    glClearBufferuiv = (GLCLEARBUFFERUIV*)LoadFunction("glClearBufferuiv");
    glClearBufferfv = (GLCLEARBUFFERFV*)LoadFunction("glClearBufferfv");
    glClearBufferfi = (GLCLEARBUFFERFI*)LoadFunction("glClearBufferfi");
    glGetStringi = (GLGETSTRINGI*)LoadFunction("glGetStringi");
    glIsRenderbuffer = (GLISRENDERBUFFER*)LoadFunction("glIsRenderbuffer");
    glBindRenderbuffer = (GLBINDRENDERBUFFER*)LoadFunction("glBindRenderbuffer");
    glDeleteRenderbuffers = (GLDELETERENDERBUFFERS*)LoadFunction("glDeleteRenderbuffers");
    glGenRenderbuffers = (GLGENRENDERBUFFERS*)LoadFunction("glGenRenderbuffers");
    glRenderbufferStorage = (GLRENDERBUFFERSTORAGE*)LoadFunction("glRenderbufferStorage");
    glGetRenderbufferParameteriv = (GLGETRENDERBUFFERPARAMETERIV*)LoadFunction("glGetRenderbufferParameteriv");
    glIsFramebuffer = (GLISFRAMEBUFFER*)LoadFunction("glIsFramebuffer");
    glBindFramebuffer = (GLBINDFRAMEBUFFER*)LoadFunction("glBindFramebuffer");
    glDeleteFramebuffers = (GLDELETEFRAMEBUFFERS*)LoadFunction("glDeleteFramebuffers");
    glGenFramebuffers = (GLGENFRAMEBUFFERS*)LoadFunction("glGenFramebuffers");
    glCheckFramebufferStatus = (GLCHECKFRAMEBUFFERSTATUS*)LoadFunction("glCheckFramebufferStatus");
    glFramebufferTexture1D = (GLFRAMEBUFFERTEXTURE1D*)LoadFunction("glFramebufferTexture1D");
    glFramebufferTexture2D = (GLFRAMEBUFFERTEXTURE2D*)LoadFunction("glFramebufferTexture2D");
    glFramebufferTexture3D = (GLFRAMEBUFFERTEXTURE3D*)LoadFunction("glFramebufferTexture3D");
    glFramebufferRenderbuffer = (GLFRAMEBUFFERRENDERBUFFER*)LoadFunction("glFramebufferRenderbuffer");
    glGetFramebufferAttachmentParameteriv = (GLGETFRAMEBUFFERATTACHMENTPARAMETERIV*)LoadFunction("glGetFramebufferAttachmentParameteriv");
    glGenerateMipmap = (GLGENERATEMIPMAP*)LoadFunction("glGenerateMipmap");
    glBlitFramebuffer = (GLBLITFRAMEBUFFER*)LoadFunction("glBlitFramebuffer");
    glRenderbufferStorageMultisample = (GLRENDERBUFFERSTORAGEMULTISAMPLE*)LoadFunction("glRenderbufferStorageMultisample");
    glFramebufferTextureLayer = (GLFRAMEBUFFERTEXTURELAYER*)LoadFunction("glFramebufferTextureLayer");
    glMapBufferRange = (GLMAPBUFFERRANGE*)LoadFunction("glMapBufferRange");
    glFlushMappedBufferRange = (GLFLUSHMAPPEDBUFFERRANGE*)LoadFunction("glFlushMappedBufferRange");
    glBindVertexArray = (GLBINDVERTEXARRAY*)LoadFunction("glBindVertexArray");
    glDeleteVertexArrays = (GLDELETEVERTEXARRAYS*)LoadFunction("glDeleteVertexArrays");
    glGenVertexArrays = (GLGENVERTEXARRAYS*)LoadFunction("glGenVertexArrays");
    glIsVertexArray = (GLISVERTEXARRAY*)LoadFunction("glIsVertexArray");
    glDrawArraysInstanced = (GLDRAWARRAYSINSTANCED*)LoadFunction("glDrawArraysInstanced");
    glDrawElementsInstanced = (GLDRAWELEMENTSINSTANCED*)LoadFunction("glDrawElementsInstanced");
    glTexBuffer = (GLTEXBUFFER*)LoadFunction("glTexBuffer");
    glPrimitiveRestartIndex = (GLPRIMITIVERESTARTINDEX*)LoadFunction("glPrimitiveRestartIndex");
    glCopyBufferSubData = (GLCOPYBUFFERSUBDATA*)LoadFunction("glCopyBufferSubData");
    glGetUniformIndices = (GLGETUNIFORMINDICES*)LoadFunction("glGetUniformIndices");
    glGetActiveUniformsiv = (GLGETACTIVEUNIFORMSIV*)LoadFunction("glGetActiveUniformsiv");
    glGetActiveUniformName = (GLGETACTIVEUNIFORMNAME*)LoadFunction("glGetActiveUniformName");
    glGetUniformBlockIndex = (GLGETUNIFORMBLOCKINDEX*)LoadFunction("glGetUniformBlockIndex");
    glGetActiveUniformBlockiv = (GLGETACTIVEUNIFORMBLOCKIV*)LoadFunction("glGetActiveUniformBlockiv");
    glGetActiveUniformBlockName = (GLGETACTIVEUNIFORMBLOCKNAME*)LoadFunction("glGetActiveUniformBlockName");
    glUniformBlockBinding = (GLUNIFORMBLOCKBINDING*)LoadFunction("glUniformBlockBinding");
    glDrawElementsBaseVertex = (GLDRAWELEMENTSBASEVERTEX*)LoadFunction("glDrawElementsBaseVertex");
    glDrawRangeElementsBaseVertex = (GLDRAWRANGEELEMENTSBASEVERTEX*)LoadFunction("glDrawRangeElementsBaseVertex");
    glDrawElementsInstancedBaseVertex = (GLDRAWELEMENTSINSTANCEDBASEVERTEX*)LoadFunction("glDrawElementsInstancedBaseVertex");
    glMultiDrawElementsBaseVertex = (GLMULTIDRAWELEMENTSBASEVERTEX*)LoadFunction("glMultiDrawElementsBaseVertex");
    glProvokingVertex = (GLPROVOKINGVERTEX*)LoadFunction("glProvokingVertex");
    glFenceSync = (GLFENCESYNC*)LoadFunction("glFenceSync");
    glIsSync = (GLISSYNC*)LoadFunction("glIsSync");
    glDeleteSync = (GLDELETESYNC*)LoadFunction("glDeleteSync");
    glClientWaitSync = (GLCLIENTWAITSYNC*)LoadFunction("glClientWaitSync");
    glWaitSync = (GLWAITSYNC*)LoadFunction("glWaitSync");
    glGetInteger64v = (GLGETINTEGER64V*)LoadFunction("glGetInteger64v");
    glGetSynciv = (GLGETSYNCIV*)LoadFunction("glGetSynciv");
    glGetInteger64i_v = (GLGETINTEGER64I_V*)LoadFunction("glGetInteger64i_v");
    glGetBufferParameteri64v = (GLGETBUFFERPARAMETERI64V*)LoadFunction("glGetBufferParameteri64v");
    glFramebufferTexture = (GLFRAMEBUFFERTEXTURE*)LoadFunction("glFramebufferTexture");
    glTexImage2DMultisample = (GLTEXIMAGE2DMULTISAMPLE*)LoadFunction("glTexImage2DMultisample");
    glTexImage3DMultisample = (GLTEXIMAGE3DMULTISAMPLE*)LoadFunction("glTexImage3DMultisample");
    glGetMultisamplefv = (GLGETMULTISAMPLEFV*)LoadFunction("glGetMultisamplefv");
    glSampleMaski = (GLSAMPLEMASKI*)LoadFunction("glSampleMaski");
    glBindFragDataLocationIndexed = (GLBINDFRAGDATALOCATIONINDEXED*)LoadFunction("glBindFragDataLocationIndexed");
    glGetFragDataIndex = (GLGETFRAGDATAINDEX*)LoadFunction("glGetFragDataIndex");
    glGenSamplers = (GLGENSAMPLERS*)LoadFunction("glGenSamplers");
    glDeleteSamplers = (GLDELETESAMPLERS*)LoadFunction("glDeleteSamplers");
    glIsSampler = (GLISSAMPLER*)LoadFunction("glIsSampler");
    glBindSampler = (GLBINDSAMPLER*)LoadFunction("glBindSampler");
    glSamplerParameteri = (GLSAMPLERPARAMETERI*)LoadFunction("glSamplerParameteri");
    glSamplerParameteriv = (GLSAMPLERPARAMETERIV*)LoadFunction("glSamplerParameteriv");
    glSamplerParameterf = (GLSAMPLERPARAMETERF*)LoadFunction("glSamplerParameterf");
    glSamplerParameterfv = (GLSAMPLERPARAMETERFV*)LoadFunction("glSamplerParameterfv");
    glSamplerParameterIiv = (GLSAMPLERPARAMETERIIV*)LoadFunction("glSamplerParameterIiv");
    glSamplerParameterIuiv = (GLSAMPLERPARAMETERIUIV*)LoadFunction("glSamplerParameterIuiv");
    glGetSamplerParameteriv = (GLGETSAMPLERPARAMETERIV*)LoadFunction("glGetSamplerParameteriv");
    glGetSamplerParameterIiv = (GLGETSAMPLERPARAMETERIIV*)LoadFunction("glGetSamplerParameterIiv");
    glGetSamplerParameterfv = (GLGETSAMPLERPARAMETERFV*)LoadFunction("glGetSamplerParameterfv");
    glGetSamplerParameterIuiv = (GLGETSAMPLERPARAMETERIUIV*)LoadFunction("glGetSamplerParameterIuiv");
    glQueryCounter = (GLQUERYCOUNTER*)LoadFunction("glQueryCounter");
    glGetQueryObjecti64v = (GLGETQUERYOBJECTI64V*)LoadFunction("glGetQueryObjecti64v");
    glGetQueryObjectui64v = (GLGETQUERYOBJECTUI64V*)LoadFunction("glGetQueryObjectui64v");
    glVertexAttribDivisor = (GLVERTEXATTRIBDIVISOR*)LoadFunction("glVertexAttribDivisor");
    glVertexAttribP1ui = (GLVERTEXATTRIBP1UI*)LoadFunction("glVertexAttribP1ui");
    glVertexAttribP1uiv = (GLVERTEXATTRIBP1UIV*)LoadFunction("glVertexAttribP1uiv");
    glVertexAttribP2ui = (GLVERTEXATTRIBP2UI*)LoadFunction("glVertexAttribP2ui");
    glVertexAttribP2uiv = (GLVERTEXATTRIBP2UIV*)LoadFunction("glVertexAttribP2uiv");
    glVertexAttribP3ui = (GLVERTEXATTRIBP3UI*)LoadFunction("glVertexAttribP3ui");
    glVertexAttribP3uiv = (GLVERTEXATTRIBP3UIV*)LoadFunction("glVertexAttribP3uiv");
    glVertexAttribP4ui = (GLVERTEXATTRIBP4UI*)LoadFunction("glVertexAttribP4ui");
    glVertexAttribP4uiv = (GLVERTEXATTRIBP4UIV*)LoadFunction("glVertexAttribP4uiv");
    glMinSampleShading = (GLMINSAMPLESHADING*)LoadFunction("glMinSampleShading");
    glBlendEquationi = (GLBLENDEQUATIONI*)LoadFunction("glBlendEquationi");
    glBlendEquationSeparatei = (GLBLENDEQUATIONSEPARATEI*)LoadFunction("glBlendEquationSeparatei");
    glBlendFunci = (GLBLENDFUNCI*)LoadFunction("glBlendFunci");
    glBlendFuncSeparatei = (GLBLENDFUNCSEPARATEI*)LoadFunction("glBlendFuncSeparatei");
    glDrawArraysIndirect = (GLDRAWARRAYSINDIRECT*)LoadFunction("glDrawArraysIndirect");
    glDrawElementsIndirect = (GLDRAWELEMENTSINDIRECT*)LoadFunction("glDrawElementsIndirect");
    glUniform1d = (GLUNIFORM1D*)LoadFunction("glUniform1d");
    glUniform2d = (GLUNIFORM2D*)LoadFunction("glUniform2d");
    glUniform3d = (GLUNIFORM3D*)LoadFunction("glUniform3d");
    glUniform4d = (GLUNIFORM4D*)LoadFunction("glUniform4d");
    glUniform1dv = (GLUNIFORM1DV*)LoadFunction("glUniform1dv");
    glUniform2dv = (GLUNIFORM2DV*)LoadFunction("glUniform2dv");
    glUniform3dv = (GLUNIFORM3DV*)LoadFunction("glUniform3dv");
    glUniform4dv = (GLUNIFORM4DV*)LoadFunction("glUniform4dv");
    glUniformMatrix2dv = (GLUNIFORMMATRIX2DV*)LoadFunction("glUniformMatrix2dv");
    glUniformMatrix3dv = (GLUNIFORMMATRIX3DV*)LoadFunction("glUniformMatrix3dv");
    glUniformMatrix4dv = (GLUNIFORMMATRIX4DV*)LoadFunction("glUniformMatrix4dv");
    glUniformMatrix2x3dv = (GLUNIFORMMATRIX2X3DV*)LoadFunction("glUniformMatrix2x3dv");
    glUniformMatrix2x4dv = (GLUNIFORMMATRIX2X4DV*)LoadFunction("glUniformMatrix2x4dv");
    glUniformMatrix3x2dv = (GLUNIFORMMATRIX3X2DV*)LoadFunction("glUniformMatrix3x2dv");
    glUniformMatrix3x4dv = (GLUNIFORMMATRIX3X4DV*)LoadFunction("glUniformMatrix3x4dv");
    glUniformMatrix4x2dv = (GLUNIFORMMATRIX4X2DV*)LoadFunction("glUniformMatrix4x2dv");
    glUniformMatrix4x3dv = (GLUNIFORMMATRIX4X3DV*)LoadFunction("glUniformMatrix4x3dv");
    glGetUniformdv = (GLGETUNIFORMDV*)LoadFunction("glGetUniformdv");
    glGetSubroutineUniformLocation = (GLGETSUBROUTINEUNIFORMLOCATION*)LoadFunction("glGetSubroutineUniformLocation");
    glGetSubroutineIndex = (GLGETSUBROUTINEINDEX*)LoadFunction("glGetSubroutineIndex");
    glGetActiveSubroutineUniformiv = (GLGETACTIVESUBROUTINEUNIFORMIV*)LoadFunction("glGetActiveSubroutineUniformiv");
    glGetActiveSubroutineUniformName = (GLGETACTIVESUBROUTINEUNIFORMNAME*)LoadFunction("glGetActiveSubroutineUniformName");
    glGetActiveSubroutineName = (GLGETACTIVESUBROUTINENAME*)LoadFunction("glGetActiveSubroutineName");
    glUniformSubroutinesuiv = (GLUNIFORMSUBROUTINESUIV*)LoadFunction("glUniformSubroutinesuiv");
    glGetUniformSubroutineuiv = (GLGETUNIFORMSUBROUTINEUIV*)LoadFunction("glGetUniformSubroutineuiv");
    glGetProgramStageiv = (GLGETPROGRAMSTAGEIV*)LoadFunction("glGetProgramStageiv");
    glPatchParameteri = (GLPATCHPARAMETERI*)LoadFunction("glPatchParameteri");
    glPatchParameterfv = (GLPATCHPARAMETERFV*)LoadFunction("glPatchParameterfv");
    glBindTransformFeedback = (GLBINDTRANSFORMFEEDBACK*)LoadFunction("glBindTransformFeedback");
    glDeleteTransformFeedbacks = (GLDELETETRANSFORMFEEDBACKS*)LoadFunction("glDeleteTransformFeedbacks");
    glGenTransformFeedbacks = (GLGENTRANSFORMFEEDBACKS*)LoadFunction("glGenTransformFeedbacks");
    glIsTransformFeedback = (GLISTRANSFORMFEEDBACK*)LoadFunction("glIsTransformFeedback");
    glPauseTransformFeedback = (GLPAUSETRANSFORMFEEDBACK*)LoadFunction("glPauseTransformFeedback");
    glResumeTransformFeedback = (GLRESUMETRANSFORMFEEDBACK*)LoadFunction("glResumeTransformFeedback");
    glDrawTransformFeedback = (GLDRAWTRANSFORMFEEDBACK*)LoadFunction("glDrawTransformFeedback");
    glDrawTransformFeedbackStream = (GLDRAWTRANSFORMFEEDBACKSTREAM*)LoadFunction("glDrawTransformFeedbackStream");
    glBeginQueryIndexed = (GLBEGINQUERYINDEXED*)LoadFunction("glBeginQueryIndexed");
    glEndQueryIndexed = (GLENDQUERYINDEXED*)LoadFunction("glEndQueryIndexed");
    glGetQueryIndexediv = (GLGETQUERYINDEXEDIV*)LoadFunction("glGetQueryIndexediv");
    glReleaseShaderCompiler = (GLRELEASESHADERCOMPILER*)LoadFunction("glReleaseShaderCompiler");
    glShaderBinary = (GLSHADERBINARY*)LoadFunction("glShaderBinary");
    glGetShaderPrecisionFormat = (GLGETSHADERPRECISIONFORMAT*)LoadFunction("glGetShaderPrecisionFormat");
    glDepthRangef = (GLDEPTHRANGEF*)LoadFunction("glDepthRangef");
    glClearDepthf = (GLCLEARDEPTHF*)LoadFunction("glClearDepthf");
    glGetProgramBinary = (GLGETPROGRAMBINARY*)LoadFunction("glGetProgramBinary");
    glProgramBinary = (GLPROGRAMBINARY*)LoadFunction("glProgramBinary");
    glProgramParameteri = (GLPROGRAMPARAMETERI*)LoadFunction("glProgramParameteri");
    glUseProgramStages = (GLUSEPROGRAMSTAGES*)LoadFunction("glUseProgramStages");
    glActiveShaderProgram = (GLACTIVESHADERPROGRAM*)LoadFunction("glActiveShaderProgram");
    glCreateShaderProgramv = (GLCREATESHADERPROGRAMV*)LoadFunction("glCreateShaderProgramv");
    glBindProgramPipeline = (GLBINDPROGRAMPIPELINE*)LoadFunction("glBindProgramPipeline");
    glDeleteProgramPipelines = (GLDELETEPROGRAMPIPELINES*)LoadFunction("glDeleteProgramPipelines");
    glGenProgramPipelines = (GLGENPROGRAMPIPELINES*)LoadFunction("glGenProgramPipelines");
    glIsProgramPipeline = (GLISPROGRAMPIPELINE*)LoadFunction("glIsProgramPipeline");
    glGetProgramPipelineiv = (GLGETPROGRAMPIPELINEIV*)LoadFunction("glGetProgramPipelineiv");
    glProgramUniform1i = (GLPROGRAMUNIFORM1I*)LoadFunction("glProgramUniform1i");
    glProgramUniform1iv = (GLPROGRAMUNIFORM1IV*)LoadFunction("glProgramUniform1iv");
    glProgramUniform1f = (GLPROGRAMUNIFORM1F*)LoadFunction("glProgramUniform1f");
    glProgramUniform1fv = (GLPROGRAMUNIFORM1FV*)LoadFunction("glProgramUniform1fv");
    glProgramUniform1d = (GLPROGRAMUNIFORM1D*)LoadFunction("glProgramUniform1d");
    glProgramUniform1dv = (GLPROGRAMUNIFORM1DV*)LoadFunction("glProgramUniform1dv");
    glProgramUniform1ui = (GLPROGRAMUNIFORM1UI*)LoadFunction("glProgramUniform1ui");
    glProgramUniform1uiv = (GLPROGRAMUNIFORM1UIV*)LoadFunction("glProgramUniform1uiv");
    glProgramUniform2i = (GLPROGRAMUNIFORM2I*)LoadFunction("glProgramUniform2i");
    glProgramUniform2iv = (GLPROGRAMUNIFORM2IV*)LoadFunction("glProgramUniform2iv");
    glProgramUniform2f = (GLPROGRAMUNIFORM2F*)LoadFunction("glProgramUniform2f");
    glProgramUniform2fv = (GLPROGRAMUNIFORM2FV*)LoadFunction("glProgramUniform2fv");
    glProgramUniform2d = (GLPROGRAMUNIFORM2D*)LoadFunction("glProgramUniform2d");
    glProgramUniform2dv = (GLPROGRAMUNIFORM2DV*)LoadFunction("glProgramUniform2dv");
    glProgramUniform2ui = (GLPROGRAMUNIFORM2UI*)LoadFunction("glProgramUniform2ui");
    glProgramUniform2uiv = (GLPROGRAMUNIFORM2UIV*)LoadFunction("glProgramUniform2uiv");
    glProgramUniform3i = (GLPROGRAMUNIFORM3I*)LoadFunction("glProgramUniform3i");
    glProgramUniform3iv = (GLPROGRAMUNIFORM3IV*)LoadFunction("glProgramUniform3iv");
    glProgramUniform3f = (GLPROGRAMUNIFORM3F*)LoadFunction("glProgramUniform3f");
    glProgramUniform3fv = (GLPROGRAMUNIFORM3FV*)LoadFunction("glProgramUniform3fv");
    glProgramUniform3d = (GLPROGRAMUNIFORM3D*)LoadFunction("glProgramUniform3d");
    glProgramUniform3dv = (GLPROGRAMUNIFORM3DV*)LoadFunction("glProgramUniform3dv");
    glProgramUniform3ui = (GLPROGRAMUNIFORM3UI*)LoadFunction("glProgramUniform3ui");
    glProgramUniform3uiv = (GLPROGRAMUNIFORM3UIV*)LoadFunction("glProgramUniform3uiv");
    glProgramUniform4i = (GLPROGRAMUNIFORM4I*)LoadFunction("glProgramUniform4i");
    glProgramUniform4iv = (GLPROGRAMUNIFORM4IV*)LoadFunction("glProgramUniform4iv");
    glProgramUniform4f = (GLPROGRAMUNIFORM4F*)LoadFunction("glProgramUniform4f");
    glProgramUniform4fv = (GLPROGRAMUNIFORM4FV*)LoadFunction("glProgramUniform4fv");
    glProgramUniform4d = (GLPROGRAMUNIFORM4D*)LoadFunction("glProgramUniform4d");
    glProgramUniform4dv = (GLPROGRAMUNIFORM4DV*)LoadFunction("glProgramUniform4dv");
    glProgramUniform4ui = (GLPROGRAMUNIFORM4UI*)LoadFunction("glProgramUniform4ui");
    glProgramUniform4uiv = (GLPROGRAMUNIFORM4UIV*)LoadFunction("glProgramUniform4uiv");
    glProgramUniformMatrix2fv = (GLPROGRAMUNIFORMMATRIX2FV*)LoadFunction("glProgramUniformMatrix2fv");
    glProgramUniformMatrix3fv = (GLPROGRAMUNIFORMMATRIX3FV*)LoadFunction("glProgramUniformMatrix3fv");
    glProgramUniformMatrix4fv = (GLPROGRAMUNIFORMMATRIX4FV*)LoadFunction("glProgramUniformMatrix4fv");
    glProgramUniformMatrix2dv = (GLPROGRAMUNIFORMMATRIX2DV*)LoadFunction("glProgramUniformMatrix2dv");
    glProgramUniformMatrix3dv = (GLPROGRAMUNIFORMMATRIX3DV*)LoadFunction("glProgramUniformMatrix3dv");
    glProgramUniformMatrix4dv = (GLPROGRAMUNIFORMMATRIX4DV*)LoadFunction("glProgramUniformMatrix4dv");
    glProgramUniformMatrix2x3fv = (GLPROGRAMUNIFORMMATRIX2X3FV*)LoadFunction("glProgramUniformMatrix2x3fv");
    glProgramUniformMatrix3x2fv = (GLPROGRAMUNIFORMMATRIX3X2FV*)LoadFunction("glProgramUniformMatrix3x2fv");
    glProgramUniformMatrix2x4fv = (GLPROGRAMUNIFORMMATRIX2X4FV*)LoadFunction("glProgramUniformMatrix2x4fv");
    glProgramUniformMatrix4x2fv = (GLPROGRAMUNIFORMMATRIX4X2FV*)LoadFunction("glProgramUniformMatrix4x2fv");
    glProgramUniformMatrix3x4fv = (GLPROGRAMUNIFORMMATRIX3X4FV*)LoadFunction("glProgramUniformMatrix3x4fv");
    glProgramUniformMatrix4x3fv = (GLPROGRAMUNIFORMMATRIX4X3FV*)LoadFunction("glProgramUniformMatrix4x3fv");
    glProgramUniformMatrix2x3dv = (GLPROGRAMUNIFORMMATRIX2X3DV*)LoadFunction("glProgramUniformMatrix2x3dv");
    glProgramUniformMatrix3x2dv = (GLPROGRAMUNIFORMMATRIX3X2DV*)LoadFunction("glProgramUniformMatrix3x2dv");
    glProgramUniformMatrix2x4dv = (GLPROGRAMUNIFORMMATRIX2X4DV*)LoadFunction("glProgramUniformMatrix2x4dv");
    glProgramUniformMatrix4x2dv = (GLPROGRAMUNIFORMMATRIX4X2DV*)LoadFunction("glProgramUniformMatrix4x2dv");
    glProgramUniformMatrix3x4dv = (GLPROGRAMUNIFORMMATRIX3X4DV*)LoadFunction("glProgramUniformMatrix3x4dv");
    glProgramUniformMatrix4x3dv = (GLPROGRAMUNIFORMMATRIX4X3DV*)LoadFunction("glProgramUniformMatrix4x3dv");
    glValidateProgramPipeline = (GLVALIDATEPROGRAMPIPELINE*)LoadFunction("glValidateProgramPipeline");
    glGetProgramPipelineInfoLog = (GLGETPROGRAMPIPELINEINFOLOG*)LoadFunction("glGetProgramPipelineInfoLog");
    glVertexAttribL1d = (GLVERTEXATTRIBL1D*)LoadFunction("glVertexAttribL1d");
    glVertexAttribL2d = (GLVERTEXATTRIBL2D*)LoadFunction("glVertexAttribL2d");
    glVertexAttribL3d = (GLVERTEXATTRIBL3D*)LoadFunction("glVertexAttribL3d");
    glVertexAttribL4d = (GLVERTEXATTRIBL4D*)LoadFunction("glVertexAttribL4d");
    glVertexAttribL1dv = (GLVERTEXATTRIBL1DV*)LoadFunction("glVertexAttribL1dv");
    glVertexAttribL2dv = (GLVERTEXATTRIBL2DV*)LoadFunction("glVertexAttribL2dv");
    glVertexAttribL3dv = (GLVERTEXATTRIBL3DV*)LoadFunction("glVertexAttribL3dv");
    glVertexAttribL4dv = (GLVERTEXATTRIBL4DV*)LoadFunction("glVertexAttribL4dv");
    glVertexAttribLPointer = (GLVERTEXATTRIBLPOINTER*)LoadFunction("glVertexAttribLPointer");
    glGetVertexAttribLdv = (GLGETVERTEXATTRIBLDV*)LoadFunction("glGetVertexAttribLdv");
    glViewportArrayv = (GLVIEWPORTARRAYV*)LoadFunction("glViewportArrayv");
    glViewportIndexedf = (GLVIEWPORTINDEXEDF*)LoadFunction("glViewportIndexedf");
    glViewportIndexedfv = (GLVIEWPORTINDEXEDFV*)LoadFunction("glViewportIndexedfv");
    glScissorArrayv = (GLSCISSORARRAYV*)LoadFunction("glScissorArrayv");
    glScissorIndexed = (GLSCISSORINDEXED*)LoadFunction("glScissorIndexed");
    glScissorIndexedv = (GLSCISSORINDEXEDV*)LoadFunction("glScissorIndexedv");
    glDepthRangeArrayv = (GLDEPTHRANGEARRAYV*)LoadFunction("glDepthRangeArrayv");
    glDepthRangeIndexed = (GLDEPTHRANGEINDEXED*)LoadFunction("glDepthRangeIndexed");
    glGetFloati_v = (GLGETFLOATI_V*)LoadFunction("glGetFloati_v");
    glGetDoublei_v = (GLGETDOUBLEI_V*)LoadFunction("glGetDoublei_v");
    glDrawArraysInstancedBaseInstance = (GLDRAWARRAYSINSTANCEDBASEINSTANCE*)LoadFunction("glDrawArraysInstancedBaseInstance");
    glDrawElementsInstancedBaseInstance = (GLDRAWELEMENTSINSTANCEDBASEINSTANCE*)LoadFunction("glDrawElementsInstancedBaseInstance");
    glDrawElementsInstancedBaseVertexBaseInstance = (GLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCE*)LoadFunction("glDrawElementsInstancedBaseVertexBaseInstance");
    glGetInternalformativ = (GLGETINTERNALFORMATIV*)LoadFunction("glGetInternalformativ");
    glGetActiveAtomicCounterBufferiv = (GLGETACTIVEATOMICCOUNTERBUFFERIV*)LoadFunction("glGetActiveAtomicCounterBufferiv");
    glBindImageTexture = (GLBINDIMAGETEXTURE*)LoadFunction("glBindImageTexture");
    glMemoryBarrier = (GLMEMORYBARRIER*)LoadFunction("glMemoryBarrier");
    glTexStorage1D = (GLTEXSTORAGE1D*)LoadFunction("glTexStorage1D");
    glTexStorage2D = (GLTEXSTORAGE2D*)LoadFunction("glTexStorage2D");
    glTexStorage3D = (GLTEXSTORAGE3D*)LoadFunction("glTexStorage3D");
    glDrawTransformFeedbackInstanced = (GLDRAWTRANSFORMFEEDBACKINSTANCED*)LoadFunction("glDrawTransformFeedbackInstanced");
    glDrawTransformFeedbackStreamInstanced = (GLDRAWTRANSFORMFEEDBACKSTREAMINSTANCED*)LoadFunction("glDrawTransformFeedbackStreamInstanced");
    glClearBufferData = (GLCLEARBUFFERDATA*)LoadFunction("glClearBufferData");
    glClearBufferSubData = (GLCLEARBUFFERSUBDATA*)LoadFunction("glClearBufferSubData");
    glDispatchCompute = (GLDISPATCHCOMPUTE*)LoadFunction("glDispatchCompute");
    glDispatchComputeIndirect = (GLDISPATCHCOMPUTEINDIRECT*)LoadFunction("glDispatchComputeIndirect");
    glCopyImageSubData = (GLCOPYIMAGESUBDATA*)LoadFunction("glCopyImageSubData");
    glFramebufferParameteri = (GLFRAMEBUFFERPARAMETERI*)LoadFunction("glFramebufferParameteri");
    glGetFramebufferParameteriv = (GLGETFRAMEBUFFERPARAMETERIV*)LoadFunction("glGetFramebufferParameteriv");
    glGetInternalformati64v = (GLGETINTERNALFORMATI64V*)LoadFunction("glGetInternalformati64v");
    glInvalidateTexSubImage = (GLINVALIDATETEXSUBIMAGE*)LoadFunction("glInvalidateTexSubImage");
    glInvalidateTexImage = (GLINVALIDATETEXIMAGE*)LoadFunction("glInvalidateTexImage");
    glInvalidateBufferSubData = (GLINVALIDATEBUFFERSUBDATA*)LoadFunction("glInvalidateBufferSubData");
    glInvalidateBufferData = (GLINVALIDATEBUFFERDATA*)LoadFunction("glInvalidateBufferData");
    glInvalidateFramebuffer = (GLINVALIDATEFRAMEBUFFER*)LoadFunction("glInvalidateFramebuffer");
    glInvalidateSubFramebuffer = (GLINVALIDATESUBFRAMEBUFFER*)LoadFunction("glInvalidateSubFramebuffer");
    glMultiDrawArraysIndirect = (GLMULTIDRAWARRAYSINDIRECT*)LoadFunction("glMultiDrawArraysIndirect");
    glMultiDrawElementsIndirect = (GLMULTIDRAWELEMENTSINDIRECT*)LoadFunction("glMultiDrawElementsIndirect");
    glGetProgramInterfaceiv = (GLGETPROGRAMINTERFACEIV*)LoadFunction("glGetProgramInterfaceiv");
    glGetProgramResourceIndex = (GLGETPROGRAMRESOURCEINDEX*)LoadFunction("glGetProgramResourceIndex");
    glGetProgramResourceName = (GLGETPROGRAMRESOURCENAME*)LoadFunction("glGetProgramResourceName");
    glGetProgramResourceiv = (GLGETPROGRAMRESOURCEIV*)LoadFunction("glGetProgramResourceiv");
    glGetProgramResourceLocation = (GLGETPROGRAMRESOURCELOCATION*)LoadFunction("glGetProgramResourceLocation");
    glGetProgramResourceLocationIndex = (GLGETPROGRAMRESOURCELOCATIONINDEX*)LoadFunction("glGetProgramResourceLocationIndex");
    glShaderStorageBlockBinding = (GLSHADERSTORAGEBLOCKBINDING*)LoadFunction("glShaderStorageBlockBinding");
    glTexBufferRange = (GLTEXBUFFERRANGE*)LoadFunction("glTexBufferRange");
    glTexStorage2DMultisample = (GLTEXSTORAGE2DMULTISAMPLE*)LoadFunction("glTexStorage2DMultisample");
    glTexStorage3DMultisample = (GLTEXSTORAGE3DMULTISAMPLE*)LoadFunction("glTexStorage3DMultisample");
    glTextureView = (GLTEXTUREVIEW*)LoadFunction("glTextureView");
    glBindVertexBuffer = (GLBINDVERTEXBUFFER*)LoadFunction("glBindVertexBuffer");
    glVertexAttribFormat = (GLVERTEXATTRIBFORMAT*)LoadFunction("glVertexAttribFormat");
    glVertexAttribIFormat = (GLVERTEXATTRIBIFORMAT*)LoadFunction("glVertexAttribIFormat");
    glVertexAttribLFormat = (GLVERTEXATTRIBLFORMAT*)LoadFunction("glVertexAttribLFormat");
    glVertexAttribBinding = (GLVERTEXATTRIBBINDING*)LoadFunction("glVertexAttribBinding");
    glVertexBindingDivisor = (GLVERTEXBINDINGDIVISOR*)LoadFunction("glVertexBindingDivisor");
    glDebugMessageControl = (GLDEBUGMESSAGECONTROL*)LoadFunction("glDebugMessageControl");
    glDebugMessageInsert = (GLDEBUGMESSAGEINSERT*)LoadFunction("glDebugMessageInsert");
    glDebugMessageCallback = (GLDEBUGMESSAGECALLBACK*)LoadFunction("glDebugMessageCallback");
    glGetDebugMessageLog = (GLGETDEBUGMESSAGELOG*)LoadFunction("glGetDebugMessageLog");
    glPushDebugGroup = (GLPUSHDEBUGGROUP*)LoadFunction("glPushDebugGroup");
    glPopDebugGroup = (GLPOPDEBUGGROUP*)LoadFunction("glPopDebugGroup");
    glObjectLabel = (GLOBJECTLABEL*)LoadFunction("glObjectLabel");
    glGetObjectLabel = (GLGETOBJECTLABEL*)LoadFunction("glGetObjectLabel");
    glObjectPtrLabel = (GLOBJECTPTRLABEL*)LoadFunction("glObjectPtrLabel");
    glGetObjectPtrLabel = (GLGETOBJECTPTRLABEL*)LoadFunction("glGetObjectPtrLabel");
    glBufferStorage = (GLBUFFERSTORAGE*)LoadFunction("glBufferStorage");
    glClearTexImage = (GLCLEARTEXIMAGE*)LoadFunction("glClearTexImage");
    glClearTexSubImage = (GLCLEARTEXSUBIMAGE*)LoadFunction("glClearTexSubImage");
    glBindBuffersBase = (GLBINDBUFFERSBASE*)LoadFunction("glBindBuffersBase");
    glBindBuffersRange = (GLBINDBUFFERSRANGE*)LoadFunction("glBindBuffersRange");
    glBindTextures = (GLBINDTEXTURES*)LoadFunction("glBindTextures");
    glBindSamplers = (GLBINDSAMPLERS*)LoadFunction("glBindSamplers");
    glBindImageTextures = (GLBINDIMAGETEXTURES*)LoadFunction("glBindImageTextures");
    glBindVertexBuffers = (GLBINDVERTEXBUFFERS*)LoadFunction("glBindVertexBuffers");
    glClipControl = (GLCLIPCONTROL*)LoadFunction("glClipControl");
    glCreateTransformFeedbacks = (GLCREATETRANSFORMFEEDBACKS*)LoadFunction("glCreateTransformFeedbacks");
    glTransformFeedbackBufferBase = (GLTRANSFORMFEEDBACKBUFFERBASE*)LoadFunction("glTransformFeedbackBufferBase");
    glTransformFeedbackBufferRange = (GLTRANSFORMFEEDBACKBUFFERRANGE*)LoadFunction("glTransformFeedbackBufferRange");
    glGetTransformFeedbackiv = (GLGETTRANSFORMFEEDBACKIV*)LoadFunction("glGetTransformFeedbackiv");
    glGetTransformFeedbacki_v = (GLGETTRANSFORMFEEDBACKI_V*)LoadFunction("glGetTransformFeedbacki_v");
    glGetTransformFeedbacki64_v = (GLGETTRANSFORMFEEDBACKI64_V*)LoadFunction("glGetTransformFeedbacki64_v");
    glCreateBuffers = (GLCREATEBUFFERS*)LoadFunction("glCreateBuffers");
    glNamedBufferStorage = (GLNAMEDBUFFERSTORAGE*)LoadFunction("glNamedBufferStorage");
    glNamedBufferData = (GLNAMEDBUFFERDATA*)LoadFunction("glNamedBufferData");
    glNamedBufferSubData = (GLNAMEDBUFFERSUBDATA*)LoadFunction("glNamedBufferSubData");
    glCopyNamedBufferSubData = (GLCOPYNAMEDBUFFERSUBDATA*)LoadFunction("glCopyNamedBufferSubData");
    glClearNamedBufferData = (GLCLEARNAMEDBUFFERDATA*)LoadFunction("glClearNamedBufferData");
    glClearNamedBufferSubData = (GLCLEARNAMEDBUFFERSUBDATA*)LoadFunction("glClearNamedBufferSubData");
    glMapNamedBuffer = (GLMAPNAMEDBUFFER*)LoadFunction("glMapNamedBuffer");
    glMapNamedBufferRange = (GLMAPNAMEDBUFFERRANGE*)LoadFunction("glMapNamedBufferRange");
    glUnmapNamedBuffer = (GLUNMAPNAMEDBUFFER*)LoadFunction("glUnmapNamedBuffer");
    glFlushMappedNamedBufferRange = (GLFLUSHMAPPEDNAMEDBUFFERRANGE*)LoadFunction("glFlushMappedNamedBufferRange");
    glGetNamedBufferParameteriv = (GLGETNAMEDBUFFERPARAMETERIV*)LoadFunction("glGetNamedBufferParameteriv");
    glGetNamedBufferParameteri64v = (GLGETNAMEDBUFFERPARAMETERI64V*)LoadFunction("glGetNamedBufferParameteri64v");
    glGetNamedBufferPointerv = (GLGETNAMEDBUFFERPOINTERV*)LoadFunction("glGetNamedBufferPointerv");
    glGetNamedBufferSubData = (GLGETNAMEDBUFFERSUBDATA*)LoadFunction("glGetNamedBufferSubData");
    glCreateFramebuffers = (GLCREATEFRAMEBUFFERS*)LoadFunction("glCreateFramebuffers");
    glNamedFramebufferRenderbuffer = (GLNAMEDFRAMEBUFFERRENDERBUFFER*)LoadFunction("glNamedFramebufferRenderbuffer");
    glNamedFramebufferParameteri = (GLNAMEDFRAMEBUFFERPARAMETERI*)LoadFunction("glNamedFramebufferParameteri");
    glNamedFramebufferTexture = (GLNAMEDFRAMEBUFFERTEXTURE*)LoadFunction("glNamedFramebufferTexture");
    glNamedFramebufferTextureLayer = (GLNAMEDFRAMEBUFFERTEXTURELAYER*)LoadFunction("glNamedFramebufferTextureLayer");
    glNamedFramebufferDrawBuffer = (GLNAMEDFRAMEBUFFERDRAWBUFFER*)LoadFunction("glNamedFramebufferDrawBuffer");
    glNamedFramebufferDrawBuffers = (GLNAMEDFRAMEBUFFERDRAWBUFFERS*)LoadFunction("glNamedFramebufferDrawBuffers");
    glNamedFramebufferReadBuffer = (GLNAMEDFRAMEBUFFERREADBUFFER*)LoadFunction("glNamedFramebufferReadBuffer");
    glInvalidateNamedFramebufferData = (GLINVALIDATENAMEDFRAMEBUFFERDATA*)LoadFunction("glInvalidateNamedFramebufferData");
    glInvalidateNamedFramebufferSubData = (GLINVALIDATENAMEDFRAMEBUFFERSUBDATA*)LoadFunction("glInvalidateNamedFramebufferSubData");
    glClearNamedFramebufferiv = (GLCLEARNAMEDFRAMEBUFFERIV*)LoadFunction("glClearNamedFramebufferiv");
    glClearNamedFramebufferuiv = (GLCLEARNAMEDFRAMEBUFFERUIV*)LoadFunction("glClearNamedFramebufferuiv");
    glClearNamedFramebufferfv = (GLCLEARNAMEDFRAMEBUFFERFV*)LoadFunction("glClearNamedFramebufferfv");
    glClearNamedFramebufferfi = (GLCLEARNAMEDFRAMEBUFFERFI*)LoadFunction("glClearNamedFramebufferfi");
    glBlitNamedFramebuffer = (GLBLITNAMEDFRAMEBUFFER*)LoadFunction("glBlitNamedFramebuffer");
    glCheckNamedFramebufferStatus = (GLCHECKNAMEDFRAMEBUFFERSTATUS*)LoadFunction("glCheckNamedFramebufferStatus");
    glGetNamedFramebufferParameteriv = (GLGETNAMEDFRAMEBUFFERPARAMETERIV*)LoadFunction("glGetNamedFramebufferParameteriv");
    glGetNamedFramebufferAttachmentParameteriv = (GLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIV*)LoadFunction("glGetNamedFramebufferAttachmentParameteriv");
    glCreateRenderbuffers = (GLCREATERENDERBUFFERS*)LoadFunction("glCreateRenderbuffers");
    glNamedRenderbufferStorage = (GLNAMEDRENDERBUFFERSTORAGE*)LoadFunction("glNamedRenderbufferStorage");
    glNamedRenderbufferStorageMultisample = (GLNAMEDRENDERBUFFERSTORAGEMULTISAMPLE*)LoadFunction("glNamedRenderbufferStorageMultisample");
    glGetNamedRenderbufferParameteriv = (GLGETNAMEDRENDERBUFFERPARAMETERIV*)LoadFunction("glGetNamedRenderbufferParameteriv");
    glCreateTextures = (GLCREATETEXTURES*)LoadFunction("glCreateTextures");
    glTextureBuffer = (GLTEXTUREBUFFER*)LoadFunction("glTextureBuffer");
    glTextureBufferRange = (GLTEXTUREBUFFERRANGE*)LoadFunction("glTextureBufferRange");
    glTextureStorage1D = (GLTEXTURESTORAGE1D*)LoadFunction("glTextureStorage1D");
    glTextureStorage2D = (GLTEXTURESTORAGE2D*)LoadFunction("glTextureStorage2D");
    glTextureStorage3D = (GLTEXTURESTORAGE3D*)LoadFunction("glTextureStorage3D");
    glTextureStorage2DMultisample = (GLTEXTURESTORAGE2DMULTISAMPLE*)LoadFunction("glTextureStorage2DMultisample");
    glTextureStorage3DMultisample = (GLTEXTURESTORAGE3DMULTISAMPLE*)LoadFunction("glTextureStorage3DMultisample");
    glTextureSubImage1D = (GLTEXTURESUBIMAGE1D*)LoadFunction("glTextureSubImage1D");
    glTextureSubImage2D = (GLTEXTURESUBIMAGE2D*)LoadFunction("glTextureSubImage2D");
    glTextureSubImage3D = (GLTEXTURESUBIMAGE3D*)LoadFunction("glTextureSubImage3D");
    glCompressedTextureSubImage1D = (GLCOMPRESSEDTEXTURESUBIMAGE1D*)LoadFunction("glCompressedTextureSubImage1D");
    glCompressedTextureSubImage2D = (GLCOMPRESSEDTEXTURESUBIMAGE2D*)LoadFunction("glCompressedTextureSubImage2D");
    glCompressedTextureSubImage3D = (GLCOMPRESSEDTEXTURESUBIMAGE3D*)LoadFunction("glCompressedTextureSubImage3D");
    glCopyTextureSubImage1D = (GLCOPYTEXTURESUBIMAGE1D*)LoadFunction("glCopyTextureSubImage1D");
    glCopyTextureSubImage2D = (GLCOPYTEXTURESUBIMAGE2D*)LoadFunction("glCopyTextureSubImage2D");
    glCopyTextureSubImage3D = (GLCOPYTEXTURESUBIMAGE3D*)LoadFunction("glCopyTextureSubImage3D");
    glTextureParameterf = (GLTEXTUREPARAMETERF*)LoadFunction("glTextureParameterf");
    glTextureParameterfv = (GLTEXTUREPARAMETERFV*)LoadFunction("glTextureParameterfv");
    glTextureParameteri = (GLTEXTUREPARAMETERI*)LoadFunction("glTextureParameteri");
    glTextureParameterIiv = (GLTEXTUREPARAMETERIIV*)LoadFunction("glTextureParameterIiv");
    glTextureParameterIuiv = (GLTEXTUREPARAMETERIUIV*)LoadFunction("glTextureParameterIuiv");
    glTextureParameteriv = (GLTEXTUREPARAMETERIV*)LoadFunction("glTextureParameteriv");
    glGenerateTextureMipmap = (GLGENERATETEXTUREMIPMAP*)LoadFunction("glGenerateTextureMipmap");
    glBindTextureUnit = (GLBINDTEXTUREUNIT*)LoadFunction("glBindTextureUnit");
    glGetTextureImage = (GLGETTEXTUREIMAGE*)LoadFunction("glGetTextureImage");
    glGetCompressedTextureImage = (GLGETCOMPRESSEDTEXTUREIMAGE*)LoadFunction("glGetCompressedTextureImage");
    glGetTextureLevelParameterfv = (GLGETTEXTURELEVELPARAMETERFV*)LoadFunction("glGetTextureLevelParameterfv");
    glGetTextureLevelParameteriv = (GLGETTEXTURELEVELPARAMETERIV*)LoadFunction("glGetTextureLevelParameteriv");
    glGetTextureParameterfv = (GLGETTEXTUREPARAMETERFV*)LoadFunction("glGetTextureParameterfv");
    glGetTextureParameterIiv = (GLGETTEXTUREPARAMETERIIV*)LoadFunction("glGetTextureParameterIiv");
    glGetTextureParameterIuiv = (GLGETTEXTUREPARAMETERIUIV*)LoadFunction("glGetTextureParameterIuiv");
    glGetTextureParameteriv = (GLGETTEXTUREPARAMETERIV*)LoadFunction("glGetTextureParameteriv");
    glCreateVertexArrays = (GLCREATEVERTEXARRAYS*)LoadFunction("glCreateVertexArrays");
    glDisableVertexArrayAttrib = (GLDISABLEVERTEXARRAYATTRIB*)LoadFunction("glDisableVertexArrayAttrib");
    glEnableVertexArrayAttrib = (GLENABLEVERTEXARRAYATTRIB*)LoadFunction("glEnableVertexArrayAttrib");
    glVertexArrayElementBuffer = (GLVERTEXARRAYELEMENTBUFFER*)LoadFunction("glVertexArrayElementBuffer");
    glVertexArrayVertexBuffer = (GLVERTEXARRAYVERTEXBUFFER*)LoadFunction("glVertexArrayVertexBuffer");
    glVertexArrayVertexBuffers = (GLVERTEXARRAYVERTEXBUFFERS*)LoadFunction("glVertexArrayVertexBuffers");
    glVertexArrayAttribBinding = (GLVERTEXARRAYATTRIBBINDING*)LoadFunction("glVertexArrayAttribBinding");
    glVertexArrayAttribFormat = (GLVERTEXARRAYATTRIBFORMAT*)LoadFunction("glVertexArrayAttribFormat");
    glVertexArrayAttribIFormat = (GLVERTEXARRAYATTRIBIFORMAT*)LoadFunction("glVertexArrayAttribIFormat");
    glVertexArrayAttribLFormat = (GLVERTEXARRAYATTRIBLFORMAT*)LoadFunction("glVertexArrayAttribLFormat");
    glVertexArrayBindingDivisor = (GLVERTEXARRAYBINDINGDIVISOR*)LoadFunction("glVertexArrayBindingDivisor");
    glGetVertexArrayiv = (GLGETVERTEXARRAYIV*)LoadFunction("glGetVertexArrayiv");
    glGetVertexArrayIndexediv = (GLGETVERTEXARRAYINDEXEDIV*)LoadFunction("glGetVertexArrayIndexediv");
    glGetVertexArrayIndexed64iv = (GLGETVERTEXARRAYINDEXED64IV*)LoadFunction("glGetVertexArrayIndexed64iv");
    glCreateSamplers = (GLCREATESAMPLERS*)LoadFunction("glCreateSamplers");
    glCreateProgramPipelines = (GLCREATEPROGRAMPIPELINES*)LoadFunction("glCreateProgramPipelines");
    glCreateQueries = (GLCREATEQUERIES*)LoadFunction("glCreateQueries");
    glGetQueryBufferObjecti64v = (GLGETQUERYBUFFEROBJECTI64V*)LoadFunction("glGetQueryBufferObjecti64v");
    glGetQueryBufferObjectiv = (GLGETQUERYBUFFEROBJECTIV*)LoadFunction("glGetQueryBufferObjectiv");
    glGetQueryBufferObjectui64v = (GLGETQUERYBUFFEROBJECTUI64V*)LoadFunction("glGetQueryBufferObjectui64v");
    glGetQueryBufferObjectuiv = (GLGETQUERYBUFFEROBJECTUIV*)LoadFunction("glGetQueryBufferObjectuiv");
    glMemoryBarrierByRegion = (GLMEMORYBARRIERBYREGION*)LoadFunction("glMemoryBarrierByRegion");
    glGetTextureSubImage = (GLGETTEXTURESUBIMAGE*)LoadFunction("glGetTextureSubImage");
    glGetCompressedTextureSubImage = (GLGETCOMPRESSEDTEXTURESUBIMAGE*)LoadFunction("glGetCompressedTextureSubImage");
    glGetGraphicsResetStatus = (GLGETGRAPHICSRESETSTATUS*)LoadFunction("glGetGraphicsResetStatus");
    glGetnCompressedTexImage = (GLGETNCOMPRESSEDTEXIMAGE*)LoadFunction("glGetnCompressedTexImage");
    glGetnTexImage = (GLGETNTEXIMAGE*)LoadFunction("glGetnTexImage");
    glGetnUniformdv = (GLGETNUNIFORMDV*)LoadFunction("glGetnUniformdv");
    glGetnUniformfv = (GLGETNUNIFORMFV*)LoadFunction("glGetnUniformfv");
    glGetnUniformiv = (GLGETNUNIFORMIV*)LoadFunction("glGetnUniformiv");
    glGetnUniformuiv = (GLGETNUNIFORMUIV*)LoadFunction("glGetnUniformuiv");
    glReadnPixels = (GLREADNPIXELS*)LoadFunction("glReadnPixels");
    glTextureBarrier = (GLTEXTUREBARRIER*)LoadFunction("glTextureBarrier");
    glGetTextureHandleARB = (GLGETTEXTUREHANDLEARB*)LoadFunction("glGetTextureHandleARB");
    glGetTextureSamplerHandleARB = (GLGETTEXTURESAMPLERHANDLEARB*)LoadFunction("glGetTextureSamplerHandleARB");
    glMakeTextureHandleResidentARB = (GLMAKETEXTUREHANDLERESIDENTARB*)LoadFunction("glMakeTextureHandleResidentARB");
    glMakeTextureHandleNonResidentARB = (GLMAKETEXTUREHANDLENONRESIDENTARB*)LoadFunction("glMakeTextureHandleNonResidentARB");
    glGetImageHandleARB = (GLGETIMAGEHANDLEARB*)LoadFunction("glGetImageHandleARB");
    glMakeImageHandleResidentARB = (GLMAKEIMAGEHANDLERESIDENTARB*)LoadFunction("glMakeImageHandleResidentARB");
    glMakeImageHandleNonResidentARB = (GLMAKEIMAGEHANDLENONRESIDENTARB*)LoadFunction("glMakeImageHandleNonResidentARB");
    glUniformHandleui64ARB = (GLUNIFORMHANDLEUI64ARB*)LoadFunction("glUniformHandleui64ARB");
    glUniformHandleui64vARB = (GLUNIFORMHANDLEUI64VARB*)LoadFunction("glUniformHandleui64vARB");
    glProgramUniformHandleui64ARB = (GLPROGRAMUNIFORMHANDLEUI64ARB*)LoadFunction("glProgramUniformHandleui64ARB");
    glProgramUniformHandleui64vARB = (GLPROGRAMUNIFORMHANDLEUI64VARB*)LoadFunction("glProgramUniformHandleui64vARB");
    glIsTextureHandleResidentARB = (GLISTEXTUREHANDLERESIDENTARB*)LoadFunction("glIsTextureHandleResidentARB");
    glIsImageHandleResidentARB = (GLISIMAGEHANDLERESIDENTARB*)LoadFunction("glIsImageHandleResidentARB");
    glVertexAttribL1ui64ARB = (GLVERTEXATTRIBL1UI64ARB*)LoadFunction("glVertexAttribL1ui64ARB");
    glVertexAttribL1ui64vARB = (GLVERTEXATTRIBL1UI64VARB*)LoadFunction("glVertexAttribL1ui64vARB");
    glGetVertexAttribLui64vARB = (GLGETVERTEXATTRIBLUI64VARB*)LoadFunction("glGetVertexAttribLui64vARB");
    glCreateSyncFromCLeventARB = (GLCREATESYNCFROMCLEVENTARB*)LoadFunction("glCreateSyncFromCLeventARB");
    glDispatchComputeGroupSizeARB = (GLDISPATCHCOMPUTEGROUPSIZEARB*)LoadFunction("glDispatchComputeGroupSizeARB");
    glDebugMessageControlARB = (GLDEBUGMESSAGECONTROLARB*)LoadFunction("glDebugMessageControlARB");
    glDebugMessageInsertARB = (GLDEBUGMESSAGEINSERTARB*)LoadFunction("glDebugMessageInsertARB");
    glDebugMessageCallbackARB = (GLDEBUGMESSAGECALLBACKARB*)LoadFunction("glDebugMessageCallbackARB");
    glGetDebugMessageLogARB = (GLGETDEBUGMESSAGELOGARB*)LoadFunction("glGetDebugMessageLogARB");
    glBlendEquationiARB = (GLBLENDEQUATIONIARB*)LoadFunction("glBlendEquationiARB");
    glBlendEquationSeparateiARB = (GLBLENDEQUATIONSEPARATEIARB*)LoadFunction("glBlendEquationSeparateiARB");
    glBlendFunciARB = (GLBLENDFUNCIARB*)LoadFunction("glBlendFunciARB");
    glBlendFuncSeparateiARB = (GLBLENDFUNCSEPARATEIARB*)LoadFunction("glBlendFuncSeparateiARB");
    glMultiDrawArraysIndirectCountARB = (GLMULTIDRAWARRAYSINDIRECTCOUNTARB*)LoadFunction("glMultiDrawArraysIndirectCountARB");
    glMultiDrawElementsIndirectCountARB = (GLMULTIDRAWELEMENTSINDIRECTCOUNTARB*)LoadFunction("glMultiDrawElementsIndirectCountARB");
    glGetGraphicsResetStatusARB = (GLGETGRAPHICSRESETSTATUSARB*)LoadFunction("glGetGraphicsResetStatusARB");
    glGetnTexImageARB = (GLGETNTEXIMAGEARB*)LoadFunction("glGetnTexImageARB");
    glReadnPixelsARB = (GLREADNPIXELSARB*)LoadFunction("glReadnPixelsARB");
    glGetnCompressedTexImageARB = (GLGETNCOMPRESSEDTEXIMAGEARB*)LoadFunction("glGetnCompressedTexImageARB");
    glGetnUniformfvARB = (GLGETNUNIFORMFVARB*)LoadFunction("glGetnUniformfvARB");
    glGetnUniformivARB = (GLGETNUNIFORMIVARB*)LoadFunction("glGetnUniformivARB");
    glGetnUniformuivARB = (GLGETNUNIFORMUIVARB*)LoadFunction("glGetnUniformuivARB");
    glGetnUniformdvARB = (GLGETNUNIFORMDVARB*)LoadFunction("glGetnUniformdvARB");
    glMinSampleShadingARB = (GLMINSAMPLESHADINGARB*)LoadFunction("glMinSampleShadingARB");
    glNamedStringARB = (GLNAMEDSTRINGARB*)LoadFunction("glNamedStringARB");
    glDeleteNamedStringARB = (GLDELETENAMEDSTRINGARB*)LoadFunction("glDeleteNamedStringARB");
    glCompileShaderIncludeARB = (GLCOMPILESHADERINCLUDEARB*)LoadFunction("glCompileShaderIncludeARB");
    glIsNamedStringARB = (GLISNAMEDSTRINGARB*)LoadFunction("glIsNamedStringARB");
    glGetNamedStringARB = (GLGETNAMEDSTRINGARB*)LoadFunction("glGetNamedStringARB");
    glGetNamedStringivARB = (GLGETNAMEDSTRINGIVARB*)LoadFunction("glGetNamedStringivARB");
    glBufferPageCommitmentARB = (GLBUFFERPAGECOMMITMENTARB*)LoadFunction("glBufferPageCommitmentARB");
    glNamedBufferPageCommitmentEXT = (GLNAMEDBUFFERPAGECOMMITMENTEXT*)LoadFunction("glNamedBufferPageCommitmentEXT");
    glNamedBufferPageCommitmentARB = (GLNAMEDBUFFERPAGECOMMITMENTARB*)LoadFunction("glNamedBufferPageCommitmentARB");
    glTexPageCommitmentARB = (GLTEXPAGECOMMITMENTARB*)LoadFunction("glTexPageCommitmentARB");
    glBlendBarrierKHR = (GLBLENDBARRIERKHR*)LoadFunction("glBlendBarrierKHR");
    glGetPerfMonitorGroupsAMD = (GLGETPERFMONITORGROUPSAMD*)LoadFunction("glGetPerfMonitorGroupsAMD");
    glGetPerfMonitorCountersAMD = (GLGETPERFMONITORCOUNTERSAMD*)LoadFunction("glGetPerfMonitorCountersAMD");
    glGetPerfMonitorGroupStringAMD = (GLGETPERFMONITORGROUPSTRINGAMD*)LoadFunction("glGetPerfMonitorGroupStringAMD");
    glGetPerfMonitorCounterStringAMD = (GLGETPERFMONITORCOUNTERSTRINGAMD*)LoadFunction("glGetPerfMonitorCounterStringAMD");
    glGetPerfMonitorCounterInfoAMD = (GLGETPERFMONITORCOUNTERINFOAMD*)LoadFunction("glGetPerfMonitorCounterInfoAMD");
    glGenPerfMonitorsAMD = (GLGENPERFMONITORSAMD*)LoadFunction("glGenPerfMonitorsAMD");
    glDeletePerfMonitorsAMD = (GLDELETEPERFMONITORSAMD*)LoadFunction("glDeletePerfMonitorsAMD");
    glSelectPerfMonitorCountersAMD = (GLSELECTPERFMONITORCOUNTERSAMD*)LoadFunction("glSelectPerfMonitorCountersAMD");
    glBeginPerfMonitorAMD = (GLBEGINPERFMONITORAMD*)LoadFunction("glBeginPerfMonitorAMD");
    glEndPerfMonitorAMD = (GLENDPERFMONITORAMD*)LoadFunction("glEndPerfMonitorAMD");
    glGetPerfMonitorCounterDataAMD = (GLGETPERFMONITORCOUNTERDATAAMD*)LoadFunction("glGetPerfMonitorCounterDataAMD");
    glLabelObjectEXT = (GLLABELOBJECTEXT*)LoadFunction("glLabelObjectEXT");
    glGetObjectLabelEXT = (GLGETOBJECTLABELEXT*)LoadFunction("glGetObjectLabelEXT");
    glInsertEventMarkerEXT = (GLINSERTEVENTMARKEREXT*)LoadFunction("glInsertEventMarkerEXT");
    glPushGroupMarkerEXT = (GLPUSHGROUPMARKEREXT*)LoadFunction("glPushGroupMarkerEXT");
    glPopGroupMarkerEXT = (GLPOPGROUPMARKEREXT*)LoadFunction("glPopGroupMarkerEXT");
    glMatrixLoadfEXT = (GLMATRIXLOADFEXT*)LoadFunction("glMatrixLoadfEXT");
    glMatrixLoaddEXT = (GLMATRIXLOADDEXT*)LoadFunction("glMatrixLoaddEXT");
    glMatrixMultfEXT = (GLMATRIXMULTFEXT*)LoadFunction("glMatrixMultfEXT");
    glMatrixMultdEXT = (GLMATRIXMULTDEXT*)LoadFunction("glMatrixMultdEXT");
    glMatrixLoadIdentityEXT = (GLMATRIXLOADIDENTITYEXT*)LoadFunction("glMatrixLoadIdentityEXT");
    glMatrixRotatefEXT = (GLMATRIXROTATEFEXT*)LoadFunction("glMatrixRotatefEXT");
    glMatrixRotatedEXT = (GLMATRIXROTATEDEXT*)LoadFunction("glMatrixRotatedEXT");
    glMatrixScalefEXT = (GLMATRIXSCALEFEXT*)LoadFunction("glMatrixScalefEXT");
    glMatrixScaledEXT = (GLMATRIXSCALEDEXT*)LoadFunction("glMatrixScaledEXT");
    glMatrixTranslatefEXT = (GLMATRIXTRANSLATEFEXT*)LoadFunction("glMatrixTranslatefEXT");
    glMatrixTranslatedEXT = (GLMATRIXTRANSLATEDEXT*)LoadFunction("glMatrixTranslatedEXT");
    glMatrixFrustumEXT = (GLMATRIXFRUSTUMEXT*)LoadFunction("glMatrixFrustumEXT");
    glMatrixOrthoEXT = (GLMATRIXORTHOEXT*)LoadFunction("glMatrixOrthoEXT");
    glMatrixPopEXT = (GLMATRIXPOPEXT*)LoadFunction("glMatrixPopEXT");
    glMatrixPushEXT = (GLMATRIXPUSHEXT*)LoadFunction("glMatrixPushEXT");
    glClientAttribDefaultEXT = (GLCLIENTATTRIBDEFAULTEXT*)LoadFunction("glClientAttribDefaultEXT");
    glPushClientAttribDefaultEXT = (GLPUSHCLIENTATTRIBDEFAULTEXT*)LoadFunction("glPushClientAttribDefaultEXT");
    glTextureParameterfEXT = (GLTEXTUREPARAMETERFEXT*)LoadFunction("glTextureParameterfEXT");
    glTextureParameterfvEXT = (GLTEXTUREPARAMETERFVEXT*)LoadFunction("glTextureParameterfvEXT");
    glTextureParameteriEXT = (GLTEXTUREPARAMETERIEXT*)LoadFunction("glTextureParameteriEXT");
    glTextureParameterivEXT = (GLTEXTUREPARAMETERIVEXT*)LoadFunction("glTextureParameterivEXT");
    glTextureImage1DEXT = (GLTEXTUREIMAGE1DEXT*)LoadFunction("glTextureImage1DEXT");
    glTextureImage2DEXT = (GLTEXTUREIMAGE2DEXT*)LoadFunction("glTextureImage2DEXT");
    glTextureSubImage1DEXT = (GLTEXTURESUBIMAGE1DEXT*)LoadFunction("glTextureSubImage1DEXT");
    glTextureSubImage2DEXT = (GLTEXTURESUBIMAGE2DEXT*)LoadFunction("glTextureSubImage2DEXT");
    glCopyTextureImage1DEXT = (GLCOPYTEXTUREIMAGE1DEXT*)LoadFunction("glCopyTextureImage1DEXT");
    glCopyTextureImage2DEXT = (GLCOPYTEXTUREIMAGE2DEXT*)LoadFunction("glCopyTextureImage2DEXT");
    glCopyTextureSubImage1DEXT = (GLCOPYTEXTURESUBIMAGE1DEXT*)LoadFunction("glCopyTextureSubImage1DEXT");
    glCopyTextureSubImage2DEXT = (GLCOPYTEXTURESUBIMAGE2DEXT*)LoadFunction("glCopyTextureSubImage2DEXT");
    glGetTextureImageEXT = (GLGETTEXTUREIMAGEEXT*)LoadFunction("glGetTextureImageEXT");
    glGetTextureParameterfvEXT = (GLGETTEXTUREPARAMETERFVEXT*)LoadFunction("glGetTextureParameterfvEXT");
    glGetTextureParameterivEXT = (GLGETTEXTUREPARAMETERIVEXT*)LoadFunction("glGetTextureParameterivEXT");
    glGetTextureLevelParameterfvEXT = (GLGETTEXTURELEVELPARAMETERFVEXT*)LoadFunction("glGetTextureLevelParameterfvEXT");
    glGetTextureLevelParameterivEXT = (GLGETTEXTURELEVELPARAMETERIVEXT*)LoadFunction("glGetTextureLevelParameterivEXT");
    glTextureImage3DEXT = (GLTEXTUREIMAGE3DEXT*)LoadFunction("glTextureImage3DEXT");
    glTextureSubImage3DEXT = (GLTEXTURESUBIMAGE3DEXT*)LoadFunction("glTextureSubImage3DEXT");
    glCopyTextureSubImage3DEXT = (GLCOPYTEXTURESUBIMAGE3DEXT*)LoadFunction("glCopyTextureSubImage3DEXT");
    glBindMultiTextureEXT = (GLBINDMULTITEXTUREEXT*)LoadFunction("glBindMultiTextureEXT");
    glMultiTexCoordPointerEXT = (GLMULTITEXCOORDPOINTEREXT*)LoadFunction("glMultiTexCoordPointerEXT");
    glMultiTexEnvfEXT = (GLMULTITEXENVFEXT*)LoadFunction("glMultiTexEnvfEXT");
    glMultiTexEnvfvEXT = (GLMULTITEXENVFVEXT*)LoadFunction("glMultiTexEnvfvEXT");
    glMultiTexEnviEXT = (GLMULTITEXENVIEXT*)LoadFunction("glMultiTexEnviEXT");
    glMultiTexEnvivEXT = (GLMULTITEXENVIVEXT*)LoadFunction("glMultiTexEnvivEXT");
    glMultiTexGendEXT = (GLMULTITEXGENDEXT*)LoadFunction("glMultiTexGendEXT");
    glMultiTexGendvEXT = (GLMULTITEXGENDVEXT*)LoadFunction("glMultiTexGendvEXT");
    glMultiTexGenfEXT = (GLMULTITEXGENFEXT*)LoadFunction("glMultiTexGenfEXT");
    glMultiTexGenfvEXT = (GLMULTITEXGENFVEXT*)LoadFunction("glMultiTexGenfvEXT");
    glMultiTexGeniEXT = (GLMULTITEXGENIEXT*)LoadFunction("glMultiTexGeniEXT");
    glMultiTexGenivEXT = (GLMULTITEXGENIVEXT*)LoadFunction("glMultiTexGenivEXT");
    glGetMultiTexEnvfvEXT = (GLGETMULTITEXENVFVEXT*)LoadFunction("glGetMultiTexEnvfvEXT");
    glGetMultiTexEnvivEXT = (GLGETMULTITEXENVIVEXT*)LoadFunction("glGetMultiTexEnvivEXT");
    glGetMultiTexGendvEXT = (GLGETMULTITEXGENDVEXT*)LoadFunction("glGetMultiTexGendvEXT");
    glGetMultiTexGenfvEXT = (GLGETMULTITEXGENFVEXT*)LoadFunction("glGetMultiTexGenfvEXT");
    glGetMultiTexGenivEXT = (GLGETMULTITEXGENIVEXT*)LoadFunction("glGetMultiTexGenivEXT");
    glMultiTexParameteriEXT = (GLMULTITEXPARAMETERIEXT*)LoadFunction("glMultiTexParameteriEXT");
    glMultiTexParameterivEXT = (GLMULTITEXPARAMETERIVEXT*)LoadFunction("glMultiTexParameterivEXT");
    glMultiTexParameterfEXT = (GLMULTITEXPARAMETERFEXT*)LoadFunction("glMultiTexParameterfEXT");
    glMultiTexParameterfvEXT = (GLMULTITEXPARAMETERFVEXT*)LoadFunction("glMultiTexParameterfvEXT");
    glMultiTexImage1DEXT = (GLMULTITEXIMAGE1DEXT*)LoadFunction("glMultiTexImage1DEXT");
    glMultiTexImage2DEXT = (GLMULTITEXIMAGE2DEXT*)LoadFunction("glMultiTexImage2DEXT");
    glMultiTexSubImage1DEXT = (GLMULTITEXSUBIMAGE1DEXT*)LoadFunction("glMultiTexSubImage1DEXT");
    glMultiTexSubImage2DEXT = (GLMULTITEXSUBIMAGE2DEXT*)LoadFunction("glMultiTexSubImage2DEXT");
    glCopyMultiTexImage1DEXT = (GLCOPYMULTITEXIMAGE1DEXT*)LoadFunction("glCopyMultiTexImage1DEXT");
    glCopyMultiTexImage2DEXT = (GLCOPYMULTITEXIMAGE2DEXT*)LoadFunction("glCopyMultiTexImage2DEXT");
    glCopyMultiTexSubImage1DEXT = (GLCOPYMULTITEXSUBIMAGE1DEXT*)LoadFunction("glCopyMultiTexSubImage1DEXT");
    glCopyMultiTexSubImage2DEXT = (GLCOPYMULTITEXSUBIMAGE2DEXT*)LoadFunction("glCopyMultiTexSubImage2DEXT");
    glGetMultiTexImageEXT = (GLGETMULTITEXIMAGEEXT*)LoadFunction("glGetMultiTexImageEXT");
    glGetMultiTexParameterfvEXT = (GLGETMULTITEXPARAMETERFVEXT*)LoadFunction("glGetMultiTexParameterfvEXT");
    glGetMultiTexParameterivEXT = (GLGETMULTITEXPARAMETERIVEXT*)LoadFunction("glGetMultiTexParameterivEXT");
    glGetMultiTexLevelParameterfvEXT = (GLGETMULTITEXLEVELPARAMETERFVEXT*)LoadFunction("glGetMultiTexLevelParameterfvEXT");
    glGetMultiTexLevelParameterivEXT = (GLGETMULTITEXLEVELPARAMETERIVEXT*)LoadFunction("glGetMultiTexLevelParameterivEXT");
    glMultiTexImage3DEXT = (GLMULTITEXIMAGE3DEXT*)LoadFunction("glMultiTexImage3DEXT");
    glMultiTexSubImage3DEXT = (GLMULTITEXSUBIMAGE3DEXT*)LoadFunction("glMultiTexSubImage3DEXT");
    glCopyMultiTexSubImage3DEXT = (GLCOPYMULTITEXSUBIMAGE3DEXT*)LoadFunction("glCopyMultiTexSubImage3DEXT");
    glEnableClientStateIndexedEXT = (GLENABLECLIENTSTATEINDEXEDEXT*)LoadFunction("glEnableClientStateIndexedEXT");
    glDisableClientStateIndexedEXT = (GLDISABLECLIENTSTATEINDEXEDEXT*)LoadFunction("glDisableClientStateIndexedEXT");
    glGetFloatIndexedvEXT = (GLGETFLOATINDEXEDVEXT*)LoadFunction("glGetFloatIndexedvEXT");
    glGetDoubleIndexedvEXT = (GLGETDOUBLEINDEXEDVEXT*)LoadFunction("glGetDoubleIndexedvEXT");
    glGetPointerIndexedvEXT = (GLGETPOINTERINDEXEDVEXT*)LoadFunction("glGetPointerIndexedvEXT");
    glEnableIndexedEXT = (GLENABLEINDEXEDEXT*)LoadFunction("glEnableIndexedEXT");
    glDisableIndexedEXT = (GLDISABLEINDEXEDEXT*)LoadFunction("glDisableIndexedEXT");
    glIsEnabledIndexedEXT = (GLISENABLEDINDEXEDEXT*)LoadFunction("glIsEnabledIndexedEXT");
    glGetIntegerIndexedvEXT = (GLGETINTEGERINDEXEDVEXT*)LoadFunction("glGetIntegerIndexedvEXT");
    glGetBooleanIndexedvEXT = (GLGETBOOLEANINDEXEDVEXT*)LoadFunction("glGetBooleanIndexedvEXT");
    glCompressedTextureImage3DEXT = (GLCOMPRESSEDTEXTUREIMAGE3DEXT*)LoadFunction("glCompressedTextureImage3DEXT");
    glCompressedTextureImage2DEXT = (GLCOMPRESSEDTEXTUREIMAGE2DEXT*)LoadFunction("glCompressedTextureImage2DEXT");
    glCompressedTextureImage1DEXT = (GLCOMPRESSEDTEXTUREIMAGE1DEXT*)LoadFunction("glCompressedTextureImage1DEXT");
    glCompressedTextureSubImage3DEXT = (GLCOMPRESSEDTEXTURESUBIMAGE3DEXT*)LoadFunction("glCompressedTextureSubImage3DEXT");
    glCompressedTextureSubImage2DEXT = (GLCOMPRESSEDTEXTURESUBIMAGE2DEXT*)LoadFunction("glCompressedTextureSubImage2DEXT");
    glCompressedTextureSubImage1DEXT = (GLCOMPRESSEDTEXTURESUBIMAGE1DEXT*)LoadFunction("glCompressedTextureSubImage1DEXT");
    glGetCompressedTextureImageEXT = (GLGETCOMPRESSEDTEXTUREIMAGEEXT*)LoadFunction("glGetCompressedTextureImageEXT");
    glCompressedMultiTexImage3DEXT = (GLCOMPRESSEDMULTITEXIMAGE3DEXT*)LoadFunction("glCompressedMultiTexImage3DEXT");
    glCompressedMultiTexImage2DEXT = (GLCOMPRESSEDMULTITEXIMAGE2DEXT*)LoadFunction("glCompressedMultiTexImage2DEXT");
    glCompressedMultiTexImage1DEXT = (GLCOMPRESSEDMULTITEXIMAGE1DEXT*)LoadFunction("glCompressedMultiTexImage1DEXT");
    glCompressedMultiTexSubImage3DEXT = (GLCOMPRESSEDMULTITEXSUBIMAGE3DEXT*)LoadFunction("glCompressedMultiTexSubImage3DEXT");
    glCompressedMultiTexSubImage2DEXT = (GLCOMPRESSEDMULTITEXSUBIMAGE2DEXT*)LoadFunction("glCompressedMultiTexSubImage2DEXT");
    glCompressedMultiTexSubImage1DEXT = (GLCOMPRESSEDMULTITEXSUBIMAGE1DEXT*)LoadFunction("glCompressedMultiTexSubImage1DEXT");
    glGetCompressedMultiTexImageEXT = (GLGETCOMPRESSEDMULTITEXIMAGEEXT*)LoadFunction("glGetCompressedMultiTexImageEXT");
    glMatrixLoadTransposefEXT = (GLMATRIXLOADTRANSPOSEFEXT*)LoadFunction("glMatrixLoadTransposefEXT");
    glMatrixLoadTransposedEXT = (GLMATRIXLOADTRANSPOSEDEXT*)LoadFunction("glMatrixLoadTransposedEXT");
    glMatrixMultTransposefEXT = (GLMATRIXMULTTRANSPOSEFEXT*)LoadFunction("glMatrixMultTransposefEXT");
    glMatrixMultTransposedEXT = (GLMATRIXMULTTRANSPOSEDEXT*)LoadFunction("glMatrixMultTransposedEXT");
    glNamedBufferDataEXT = (GLNAMEDBUFFERDATAEXT*)LoadFunction("glNamedBufferDataEXT");
    glNamedBufferSubDataEXT = (GLNAMEDBUFFERSUBDATAEXT*)LoadFunction("glNamedBufferSubDataEXT");
    glMapNamedBufferEXT = (GLMAPNAMEDBUFFEREXT*)LoadFunction("glMapNamedBufferEXT");
    glUnmapNamedBufferEXT = (GLUNMAPNAMEDBUFFEREXT*)LoadFunction("glUnmapNamedBufferEXT");
    glGetNamedBufferParameterivEXT = (GLGETNAMEDBUFFERPARAMETERIVEXT*)LoadFunction("glGetNamedBufferParameterivEXT");
    glGetNamedBufferPointervEXT = (GLGETNAMEDBUFFERPOINTERVEXT*)LoadFunction("glGetNamedBufferPointervEXT");
    glGetNamedBufferSubDataEXT = (GLGETNAMEDBUFFERSUBDATAEXT*)LoadFunction("glGetNamedBufferSubDataEXT");
    glProgramUniform1fEXT = (GLPROGRAMUNIFORM1FEXT*)LoadFunction("glProgramUniform1fEXT");
    glProgramUniform2fEXT = (GLPROGRAMUNIFORM2FEXT*)LoadFunction("glProgramUniform2fEXT");
    glProgramUniform3fEXT = (GLPROGRAMUNIFORM3FEXT*)LoadFunction("glProgramUniform3fEXT");
    glProgramUniform4fEXT = (GLPROGRAMUNIFORM4FEXT*)LoadFunction("glProgramUniform4fEXT");
    glProgramUniform1iEXT = (GLPROGRAMUNIFORM1IEXT*)LoadFunction("glProgramUniform1iEXT");
    glProgramUniform2iEXT = (GLPROGRAMUNIFORM2IEXT*)LoadFunction("glProgramUniform2iEXT");
    glProgramUniform3iEXT = (GLPROGRAMUNIFORM3IEXT*)LoadFunction("glProgramUniform3iEXT");
    glProgramUniform4iEXT = (GLPROGRAMUNIFORM4IEXT*)LoadFunction("glProgramUniform4iEXT");
    glProgramUniform1fvEXT = (GLPROGRAMUNIFORM1FVEXT*)LoadFunction("glProgramUniform1fvEXT");
    glProgramUniform2fvEXT = (GLPROGRAMUNIFORM2FVEXT*)LoadFunction("glProgramUniform2fvEXT");
    glProgramUniform3fvEXT = (GLPROGRAMUNIFORM3FVEXT*)LoadFunction("glProgramUniform3fvEXT");
    glProgramUniform4fvEXT = (GLPROGRAMUNIFORM4FVEXT*)LoadFunction("glProgramUniform4fvEXT");
    glProgramUniform1ivEXT = (GLPROGRAMUNIFORM1IVEXT*)LoadFunction("glProgramUniform1ivEXT");
    glProgramUniform2ivEXT = (GLPROGRAMUNIFORM2IVEXT*)LoadFunction("glProgramUniform2ivEXT");
    glProgramUniform3ivEXT = (GLPROGRAMUNIFORM3IVEXT*)LoadFunction("glProgramUniform3ivEXT");
    glProgramUniform4ivEXT = (GLPROGRAMUNIFORM4IVEXT*)LoadFunction("glProgramUniform4ivEXT");
    glProgramUniformMatrix2fvEXT = (GLPROGRAMUNIFORMMATRIX2FVEXT*)LoadFunction("glProgramUniformMatrix2fvEXT");
    glProgramUniformMatrix3fvEXT = (GLPROGRAMUNIFORMMATRIX3FVEXT*)LoadFunction("glProgramUniformMatrix3fvEXT");
    glProgramUniformMatrix4fvEXT = (GLPROGRAMUNIFORMMATRIX4FVEXT*)LoadFunction("glProgramUniformMatrix4fvEXT");
    glProgramUniformMatrix2x3fvEXT = (GLPROGRAMUNIFORMMATRIX2X3FVEXT*)LoadFunction("glProgramUniformMatrix2x3fvEXT");
    glProgramUniformMatrix3x2fvEXT = (GLPROGRAMUNIFORMMATRIX3X2FVEXT*)LoadFunction("glProgramUniformMatrix3x2fvEXT");
    glProgramUniformMatrix2x4fvEXT = (GLPROGRAMUNIFORMMATRIX2X4FVEXT*)LoadFunction("glProgramUniformMatrix2x4fvEXT");
    glProgramUniformMatrix4x2fvEXT = (GLPROGRAMUNIFORMMATRIX4X2FVEXT*)LoadFunction("glProgramUniformMatrix4x2fvEXT");
    glProgramUniformMatrix3x4fvEXT = (GLPROGRAMUNIFORMMATRIX3X4FVEXT*)LoadFunction("glProgramUniformMatrix3x4fvEXT");
    glProgramUniformMatrix4x3fvEXT = (GLPROGRAMUNIFORMMATRIX4X3FVEXT*)LoadFunction("glProgramUniformMatrix4x3fvEXT");
    glTextureBufferEXT = (GLTEXTUREBUFFEREXT*)LoadFunction("glTextureBufferEXT");
    glMultiTexBufferEXT = (GLMULTITEXBUFFEREXT*)LoadFunction("glMultiTexBufferEXT");
    glTextureParameterIivEXT = (GLTEXTUREPARAMETERIIVEXT*)LoadFunction("glTextureParameterIivEXT");
    glTextureParameterIuivEXT = (GLTEXTUREPARAMETERIUIVEXT*)LoadFunction("glTextureParameterIuivEXT");
    glGetTextureParameterIivEXT = (GLGETTEXTUREPARAMETERIIVEXT*)LoadFunction("glGetTextureParameterIivEXT");
    glGetTextureParameterIuivEXT = (GLGETTEXTUREPARAMETERIUIVEXT*)LoadFunction("glGetTextureParameterIuivEXT");
    glMultiTexParameterIivEXT = (GLMULTITEXPARAMETERIIVEXT*)LoadFunction("glMultiTexParameterIivEXT");
    glMultiTexParameterIuivEXT = (GLMULTITEXPARAMETERIUIVEXT*)LoadFunction("glMultiTexParameterIuivEXT");
    glGetMultiTexParameterIivEXT = (GLGETMULTITEXPARAMETERIIVEXT*)LoadFunction("glGetMultiTexParameterIivEXT");
    glGetMultiTexParameterIuivEXT = (GLGETMULTITEXPARAMETERIUIVEXT*)LoadFunction("glGetMultiTexParameterIuivEXT");
    glProgramUniform1uiEXT = (GLPROGRAMUNIFORM1UIEXT*)LoadFunction("glProgramUniform1uiEXT");
    glProgramUniform2uiEXT = (GLPROGRAMUNIFORM2UIEXT*)LoadFunction("glProgramUniform2uiEXT");
    glProgramUniform3uiEXT = (GLPROGRAMUNIFORM3UIEXT*)LoadFunction("glProgramUniform3uiEXT");
    glProgramUniform4uiEXT = (GLPROGRAMUNIFORM4UIEXT*)LoadFunction("glProgramUniform4uiEXT");
    glProgramUniform1uivEXT = (GLPROGRAMUNIFORM1UIVEXT*)LoadFunction("glProgramUniform1uivEXT");
    glProgramUniform2uivEXT = (GLPROGRAMUNIFORM2UIVEXT*)LoadFunction("glProgramUniform2uivEXT");
    glProgramUniform3uivEXT = (GLPROGRAMUNIFORM3UIVEXT*)LoadFunction("glProgramUniform3uivEXT");
    glProgramUniform4uivEXT = (GLPROGRAMUNIFORM4UIVEXT*)LoadFunction("glProgramUniform4uivEXT");
    glNamedProgramLocalParameters4fvEXT = (GLNAMEDPROGRAMLOCALPARAMETERS4FVEXT*)LoadFunction("glNamedProgramLocalParameters4fvEXT");
    glNamedProgramLocalParameterI4iEXT = (GLNAMEDPROGRAMLOCALPARAMETERI4IEXT*)LoadFunction("glNamedProgramLocalParameterI4iEXT");
    glNamedProgramLocalParameterI4ivEXT = (GLNAMEDPROGRAMLOCALPARAMETERI4IVEXT*)LoadFunction("glNamedProgramLocalParameterI4ivEXT");
    glNamedProgramLocalParametersI4ivEXT = (GLNAMEDPROGRAMLOCALPARAMETERSI4IVEXT*)LoadFunction("glNamedProgramLocalParametersI4ivEXT");
    glNamedProgramLocalParameterI4uiEXT = (GLNAMEDPROGRAMLOCALPARAMETERI4UIEXT*)LoadFunction("glNamedProgramLocalParameterI4uiEXT");
    glNamedProgramLocalParameterI4uivEXT = (GLNAMEDPROGRAMLOCALPARAMETERI4UIVEXT*)LoadFunction("glNamedProgramLocalParameterI4uivEXT");
    glNamedProgramLocalParametersI4uivEXT = (GLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXT*)LoadFunction("glNamedProgramLocalParametersI4uivEXT");
    glGetNamedProgramLocalParameterIivEXT = (GLGETNAMEDPROGRAMLOCALPARAMETERIIVEXT*)LoadFunction("glGetNamedProgramLocalParameterIivEXT");
    glGetNamedProgramLocalParameterIuivEXT = (GLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXT*)LoadFunction("glGetNamedProgramLocalParameterIuivEXT");
    glEnableClientStateiEXT = (GLENABLECLIENTSTATEIEXT*)LoadFunction("glEnableClientStateiEXT");
    glDisableClientStateiEXT = (GLDISABLECLIENTSTATEIEXT*)LoadFunction("glDisableClientStateiEXT");
    glGetFloati_vEXT = (GLGETFLOATI_VEXT*)LoadFunction("glGetFloati_vEXT");
    glGetDoublei_vEXT = (GLGETDOUBLEI_VEXT*)LoadFunction("glGetDoublei_vEXT");
    glGetPointeri_vEXT = (GLGETPOINTERI_VEXT*)LoadFunction("glGetPointeri_vEXT");
    glNamedProgramStringEXT = (GLNAMEDPROGRAMSTRINGEXT*)LoadFunction("glNamedProgramStringEXT");
    glNamedProgramLocalParameter4dEXT = (GLNAMEDPROGRAMLOCALPARAMETER4DEXT*)LoadFunction("glNamedProgramLocalParameter4dEXT");
    glNamedProgramLocalParameter4dvEXT = (GLNAMEDPROGRAMLOCALPARAMETER4DVEXT*)LoadFunction("glNamedProgramLocalParameter4dvEXT");
    glNamedProgramLocalParameter4fEXT = (GLNAMEDPROGRAMLOCALPARAMETER4FEXT*)LoadFunction("glNamedProgramLocalParameter4fEXT");
    glNamedProgramLocalParameter4fvEXT = (GLNAMEDPROGRAMLOCALPARAMETER4FVEXT*)LoadFunction("glNamedProgramLocalParameter4fvEXT");
    glGetNamedProgramLocalParameterdvEXT = (GLGETNAMEDPROGRAMLOCALPARAMETERDVEXT*)LoadFunction("glGetNamedProgramLocalParameterdvEXT");
    glGetNamedProgramLocalParameterfvEXT = (GLGETNAMEDPROGRAMLOCALPARAMETERFVEXT*)LoadFunction("glGetNamedProgramLocalParameterfvEXT");
    glGetNamedProgramivEXT = (GLGETNAMEDPROGRAMIVEXT*)LoadFunction("glGetNamedProgramivEXT");
    glGetNamedProgramStringEXT = (GLGETNAMEDPROGRAMSTRINGEXT*)LoadFunction("glGetNamedProgramStringEXT");
    glNamedRenderbufferStorageEXT = (GLNAMEDRENDERBUFFERSTORAGEEXT*)LoadFunction("glNamedRenderbufferStorageEXT");
    glGetNamedRenderbufferParameterivEXT = (GLGETNAMEDRENDERBUFFERPARAMETERIVEXT*)LoadFunction("glGetNamedRenderbufferParameterivEXT");
    glNamedRenderbufferStorageMultisampleEXT = (GLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXT*)LoadFunction("glNamedRenderbufferStorageMultisampleEXT");
    glNamedRenderbufferStorageMultisampleCoverageEXT = (GLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXT*)LoadFunction("glNamedRenderbufferStorageMultisampleCoverageEXT");
    glCheckNamedFramebufferStatusEXT = (GLCHECKNAMEDFRAMEBUFFERSTATUSEXT*)LoadFunction("glCheckNamedFramebufferStatusEXT");
    glNamedFramebufferTexture1DEXT = (GLNAMEDFRAMEBUFFERTEXTURE1DEXT*)LoadFunction("glNamedFramebufferTexture1DEXT");
    glNamedFramebufferTexture2DEXT = (GLNAMEDFRAMEBUFFERTEXTURE2DEXT*)LoadFunction("glNamedFramebufferTexture2DEXT");
    glNamedFramebufferTexture3DEXT = (GLNAMEDFRAMEBUFFERTEXTURE3DEXT*)LoadFunction("glNamedFramebufferTexture3DEXT");
    glNamedFramebufferRenderbufferEXT = (GLNAMEDFRAMEBUFFERRENDERBUFFEREXT*)LoadFunction("glNamedFramebufferRenderbufferEXT");
    glGetNamedFramebufferAttachmentParameterivEXT = (GLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXT*)LoadFunction("glGetNamedFramebufferAttachmentParameterivEXT");
    glGenerateTextureMipmapEXT = (GLGENERATETEXTUREMIPMAPEXT*)LoadFunction("glGenerateTextureMipmapEXT");
    glGenerateMultiTexMipmapEXT = (GLGENERATEMULTITEXMIPMAPEXT*)LoadFunction("glGenerateMultiTexMipmapEXT");
    glFramebufferDrawBufferEXT = (GLFRAMEBUFFERDRAWBUFFEREXT*)LoadFunction("glFramebufferDrawBufferEXT");
    glFramebufferDrawBuffersEXT = (GLFRAMEBUFFERDRAWBUFFERSEXT*)LoadFunction("glFramebufferDrawBuffersEXT");
    glFramebufferReadBufferEXT = (GLFRAMEBUFFERREADBUFFEREXT*)LoadFunction("glFramebufferReadBufferEXT");
    glGetFramebufferParameterivEXT = (GLGETFRAMEBUFFERPARAMETERIVEXT*)LoadFunction("glGetFramebufferParameterivEXT");
    glNamedCopyBufferSubDataEXT = (GLNAMEDCOPYBUFFERSUBDATAEXT*)LoadFunction("glNamedCopyBufferSubDataEXT");
    glNamedFramebufferTextureEXT = (GLNAMEDFRAMEBUFFERTEXTUREEXT*)LoadFunction("glNamedFramebufferTextureEXT");
    glNamedFramebufferTextureLayerEXT = (GLNAMEDFRAMEBUFFERTEXTURELAYEREXT*)LoadFunction("glNamedFramebufferTextureLayerEXT");
    glNamedFramebufferTextureFaceEXT = (GLNAMEDFRAMEBUFFERTEXTUREFACEEXT*)LoadFunction("glNamedFramebufferTextureFaceEXT");
    glTextureRenderbufferEXT = (GLTEXTURERENDERBUFFEREXT*)LoadFunction("glTextureRenderbufferEXT");
    glMultiTexRenderbufferEXT = (GLMULTITEXRENDERBUFFEREXT*)LoadFunction("glMultiTexRenderbufferEXT");
    glVertexArrayVertexOffsetEXT = (GLVERTEXARRAYVERTEXOFFSETEXT*)LoadFunction("glVertexArrayVertexOffsetEXT");
    glVertexArrayColorOffsetEXT = (GLVERTEXARRAYCOLOROFFSETEXT*)LoadFunction("glVertexArrayColorOffsetEXT");
    glVertexArrayEdgeFlagOffsetEXT = (GLVERTEXARRAYEDGEFLAGOFFSETEXT*)LoadFunction("glVertexArrayEdgeFlagOffsetEXT");
    glVertexArrayIndexOffsetEXT = (GLVERTEXARRAYINDEXOFFSETEXT*)LoadFunction("glVertexArrayIndexOffsetEXT");
    glVertexArrayNormalOffsetEXT = (GLVERTEXARRAYNORMALOFFSETEXT*)LoadFunction("glVertexArrayNormalOffsetEXT");
    glVertexArrayTexCoordOffsetEXT = (GLVERTEXARRAYTEXCOORDOFFSETEXT*)LoadFunction("glVertexArrayTexCoordOffsetEXT");
    glVertexArrayMultiTexCoordOffsetEXT = (GLVERTEXARRAYMULTITEXCOORDOFFSETEXT*)LoadFunction("glVertexArrayMultiTexCoordOffsetEXT");
    glVertexArrayFogCoordOffsetEXT = (GLVERTEXARRAYFOGCOORDOFFSETEXT*)LoadFunction("glVertexArrayFogCoordOffsetEXT");
    glVertexArraySecondaryColorOffsetEXT = (GLVERTEXARRAYSECONDARYCOLOROFFSETEXT*)LoadFunction("glVertexArraySecondaryColorOffsetEXT");
    glVertexArrayVertexAttribOffsetEXT = (GLVERTEXARRAYVERTEXATTRIBOFFSETEXT*)LoadFunction("glVertexArrayVertexAttribOffsetEXT");
    glVertexArrayVertexAttribIOffsetEXT = (GLVERTEXARRAYVERTEXATTRIBIOFFSETEXT*)LoadFunction("glVertexArrayVertexAttribIOffsetEXT");
    glEnableVertexArrayEXT = (GLENABLEVERTEXARRAYEXT*)LoadFunction("glEnableVertexArrayEXT");
    glDisableVertexArrayEXT = (GLDISABLEVERTEXARRAYEXT*)LoadFunction("glDisableVertexArrayEXT");
    glEnableVertexArrayAttribEXT = (GLENABLEVERTEXARRAYATTRIBEXT*)LoadFunction("glEnableVertexArrayAttribEXT");
    glDisableVertexArrayAttribEXT = (GLDISABLEVERTEXARRAYATTRIBEXT*)LoadFunction("glDisableVertexArrayAttribEXT");
    glGetVertexArrayIntegervEXT = (GLGETVERTEXARRAYINTEGERVEXT*)LoadFunction("glGetVertexArrayIntegervEXT");
    glGetVertexArrayPointervEXT = (GLGETVERTEXARRAYPOINTERVEXT*)LoadFunction("glGetVertexArrayPointervEXT");
    glGetVertexArrayIntegeri_vEXT = (GLGETVERTEXARRAYINTEGERI_VEXT*)LoadFunction("glGetVertexArrayIntegeri_vEXT");
    glGetVertexArrayPointeri_vEXT = (GLGETVERTEXARRAYPOINTERI_VEXT*)LoadFunction("glGetVertexArrayPointeri_vEXT");
    glMapNamedBufferRangeEXT = (GLMAPNAMEDBUFFERRANGEEXT*)LoadFunction("glMapNamedBufferRangeEXT");
    glFlushMappedNamedBufferRangeEXT = (GLFLUSHMAPPEDNAMEDBUFFERRANGEEXT*)LoadFunction("glFlushMappedNamedBufferRangeEXT");
    glNamedBufferStorageEXT = (GLNAMEDBUFFERSTORAGEEXT*)LoadFunction("glNamedBufferStorageEXT");
    glClearNamedBufferDataEXT = (GLCLEARNAMEDBUFFERDATAEXT*)LoadFunction("glClearNamedBufferDataEXT");
    glClearNamedBufferSubDataEXT = (GLCLEARNAMEDBUFFERSUBDATAEXT*)LoadFunction("glClearNamedBufferSubDataEXT");
    glNamedFramebufferParameteriEXT = (GLNAMEDFRAMEBUFFERPARAMETERIEXT*)LoadFunction("glNamedFramebufferParameteriEXT");
    glGetNamedFramebufferParameterivEXT = (GLGETNAMEDFRAMEBUFFERPARAMETERIVEXT*)LoadFunction("glGetNamedFramebufferParameterivEXT");
    glProgramUniform1dEXT = (GLPROGRAMUNIFORM1DEXT*)LoadFunction("glProgramUniform1dEXT");
    glProgramUniform2dEXT = (GLPROGRAMUNIFORM2DEXT*)LoadFunction("glProgramUniform2dEXT");
    glProgramUniform3dEXT = (GLPROGRAMUNIFORM3DEXT*)LoadFunction("glProgramUniform3dEXT");
    glProgramUniform4dEXT = (GLPROGRAMUNIFORM4DEXT*)LoadFunction("glProgramUniform4dEXT");
    glProgramUniform1dvEXT = (GLPROGRAMUNIFORM1DVEXT*)LoadFunction("glProgramUniform1dvEXT");
    glProgramUniform2dvEXT = (GLPROGRAMUNIFORM2DVEXT*)LoadFunction("glProgramUniform2dvEXT");
    glProgramUniform3dvEXT = (GLPROGRAMUNIFORM3DVEXT*)LoadFunction("glProgramUniform3dvEXT");
    glProgramUniform4dvEXT = (GLPROGRAMUNIFORM4DVEXT*)LoadFunction("glProgramUniform4dvEXT");
    glProgramUniformMatrix2dvEXT = (GLPROGRAMUNIFORMMATRIX2DVEXT*)LoadFunction("glProgramUniformMatrix2dvEXT");
    glProgramUniformMatrix3dvEXT = (GLPROGRAMUNIFORMMATRIX3DVEXT*)LoadFunction("glProgramUniformMatrix3dvEXT");
    glProgramUniformMatrix4dvEXT = (GLPROGRAMUNIFORMMATRIX4DVEXT*)LoadFunction("glProgramUniformMatrix4dvEXT");
    glProgramUniformMatrix2x3dvEXT = (GLPROGRAMUNIFORMMATRIX2X3DVEXT*)LoadFunction("glProgramUniformMatrix2x3dvEXT");
    glProgramUniformMatrix2x4dvEXT = (GLPROGRAMUNIFORMMATRIX2X4DVEXT*)LoadFunction("glProgramUniformMatrix2x4dvEXT");
    glProgramUniformMatrix3x2dvEXT = (GLPROGRAMUNIFORMMATRIX3X2DVEXT*)LoadFunction("glProgramUniformMatrix3x2dvEXT");
    glProgramUniformMatrix3x4dvEXT = (GLPROGRAMUNIFORMMATRIX3X4DVEXT*)LoadFunction("glProgramUniformMatrix3x4dvEXT");
    glProgramUniformMatrix4x2dvEXT = (GLPROGRAMUNIFORMMATRIX4X2DVEXT*)LoadFunction("glProgramUniformMatrix4x2dvEXT");
    glProgramUniformMatrix4x3dvEXT = (GLPROGRAMUNIFORMMATRIX4X3DVEXT*)LoadFunction("glProgramUniformMatrix4x3dvEXT");
    glTextureBufferRangeEXT = (GLTEXTUREBUFFERRANGEEXT*)LoadFunction("glTextureBufferRangeEXT");
    glTextureStorage1DEXT = (GLTEXTURESTORAGE1DEXT*)LoadFunction("glTextureStorage1DEXT");
    glTextureStorage2DEXT = (GLTEXTURESTORAGE2DEXT*)LoadFunction("glTextureStorage2DEXT");
    glTextureStorage3DEXT = (GLTEXTURESTORAGE3DEXT*)LoadFunction("glTextureStorage3DEXT");
    glTextureStorage2DMultisampleEXT = (GLTEXTURESTORAGE2DMULTISAMPLEEXT*)LoadFunction("glTextureStorage2DMultisampleEXT");
    glTextureStorage3DMultisampleEXT = (GLTEXTURESTORAGE3DMULTISAMPLEEXT*)LoadFunction("glTextureStorage3DMultisampleEXT");
    glVertexArrayBindVertexBufferEXT = (GLVERTEXARRAYBINDVERTEXBUFFEREXT*)LoadFunction("glVertexArrayBindVertexBufferEXT");
    glVertexArrayVertexAttribFormatEXT = (GLVERTEXARRAYVERTEXATTRIBFORMATEXT*)LoadFunction("glVertexArrayVertexAttribFormatEXT");
    glVertexArrayVertexAttribIFormatEXT = (GLVERTEXARRAYVERTEXATTRIBIFORMATEXT*)LoadFunction("glVertexArrayVertexAttribIFormatEXT");
    glVertexArrayVertexAttribLFormatEXT = (GLVERTEXARRAYVERTEXATTRIBLFORMATEXT*)LoadFunction("glVertexArrayVertexAttribLFormatEXT");
    glVertexArrayVertexAttribBindingEXT = (GLVERTEXARRAYVERTEXATTRIBBINDINGEXT*)LoadFunction("glVertexArrayVertexAttribBindingEXT");
    glVertexArrayVertexBindingDivisorEXT = (GLVERTEXARRAYVERTEXBINDINGDIVISOREXT*)LoadFunction("glVertexArrayVertexBindingDivisorEXT");
    glVertexArrayVertexAttribLOffsetEXT = (GLVERTEXARRAYVERTEXATTRIBLOFFSETEXT*)LoadFunction("glVertexArrayVertexAttribLOffsetEXT");
    glTexturePageCommitmentEXT = (GLTEXTUREPAGECOMMITMENTEXT*)LoadFunction("glTexturePageCommitmentEXT");
    glVertexArrayVertexAttribDivisorEXT = (GLVERTEXARRAYVERTEXATTRIBDIVISOREXT*)LoadFunction("glVertexArrayVertexAttribDivisorEXT");
    glDrawArraysInstancedEXT = (GLDRAWARRAYSINSTANCEDEXT*)LoadFunction("glDrawArraysInstancedEXT");
    glDrawElementsInstancedEXT = (GLDRAWELEMENTSINSTANCEDEXT*)LoadFunction("glDrawElementsInstancedEXT");
    glPolygonOffsetClampEXT = (GLPOLYGONOFFSETCLAMPEXT*)LoadFunction("glPolygonOffsetClampEXT");
    glRasterSamplesEXT = (GLRASTERSAMPLESEXT*)LoadFunction("glRasterSamplesEXT");
    glUseShaderProgramEXT = (GLUSESHADERPROGRAMEXT*)LoadFunction("glUseShaderProgramEXT");
    glActiveProgramEXT = (GLACTIVEPROGRAMEXT*)LoadFunction("glActiveProgramEXT");
    glCreateShaderProgramEXT = (GLCREATESHADERPROGRAMEXT*)LoadFunction("glCreateShaderProgramEXT");
    glWindowRectanglesEXT = (GLWINDOWRECTANGLESEXT*)LoadFunction("glWindowRectanglesEXT");
    glApplyFramebufferAttachmentCMAAINTEL = (GLAPPLYFRAMEBUFFERATTACHMENTCMAAINTEL*)LoadFunction("glApplyFramebufferAttachmentCMAAINTEL");
    glBeginPerfQueryINTEL = (GLBEGINPERFQUERYINTEL*)LoadFunction("glBeginPerfQueryINTEL");
    glCreatePerfQueryINTEL = (GLCREATEPERFQUERYINTEL*)LoadFunction("glCreatePerfQueryINTEL");
    glDeletePerfQueryINTEL = (GLDELETEPERFQUERYINTEL*)LoadFunction("glDeletePerfQueryINTEL");
    glEndPerfQueryINTEL = (GLENDPERFQUERYINTEL*)LoadFunction("glEndPerfQueryINTEL");
    glGetFirstPerfQueryIdINTEL = (GLGETFIRSTPERFQUERYIDINTEL*)LoadFunction("glGetFirstPerfQueryIdINTEL");
    glGetNextPerfQueryIdINTEL = (GLGETNEXTPERFQUERYIDINTEL*)LoadFunction("glGetNextPerfQueryIdINTEL");
    glGetPerfCounterInfoINTEL = (GLGETPERFCOUNTERINFOINTEL*)LoadFunction("glGetPerfCounterInfoINTEL");
    glGetPerfQueryDataINTEL = (GLGETPERFQUERYDATAINTEL*)LoadFunction("glGetPerfQueryDataINTEL");
    glGetPerfQueryIdByNameINTEL = (GLGETPERFQUERYIDBYNAMEINTEL*)LoadFunction("glGetPerfQueryIdByNameINTEL");
    glGetPerfQueryInfoINTEL = (GLGETPERFQUERYINFOINTEL*)LoadFunction("glGetPerfQueryInfoINTEL");
    glGetTextureHandleNV = (GLGETTEXTUREHANDLENV*)LoadFunction("glGetTextureHandleNV");
    glGetTextureSamplerHandleNV = (GLGETTEXTURESAMPLERHANDLENV*)LoadFunction("glGetTextureSamplerHandleNV");
    glMakeTextureHandleResidentNV = (GLMAKETEXTUREHANDLERESIDENTNV*)LoadFunction("glMakeTextureHandleResidentNV");
    glMakeTextureHandleNonResidentNV = (GLMAKETEXTUREHANDLENONRESIDENTNV*)LoadFunction("glMakeTextureHandleNonResidentNV");
    glGetImageHandleNV = (GLGETIMAGEHANDLENV*)LoadFunction("glGetImageHandleNV");
    glMakeImageHandleResidentNV = (GLMAKEIMAGEHANDLERESIDENTNV*)LoadFunction("glMakeImageHandleResidentNV");
    glMakeImageHandleNonResidentNV = (GLMAKEIMAGEHANDLENONRESIDENTNV*)LoadFunction("glMakeImageHandleNonResidentNV");
    glUniformHandleui64NV = (GLUNIFORMHANDLEUI64NV*)LoadFunction("glUniformHandleui64NV");
    glUniformHandleui64vNV = (GLUNIFORMHANDLEUI64VNV*)LoadFunction("glUniformHandleui64vNV");
    glProgramUniformHandleui64NV = (GLPROGRAMUNIFORMHANDLEUI64NV*)LoadFunction("glProgramUniformHandleui64NV");
    glProgramUniformHandleui64vNV = (GLPROGRAMUNIFORMHANDLEUI64VNV*)LoadFunction("glProgramUniformHandleui64vNV");
    glIsTextureHandleResidentNV = (GLISTEXTUREHANDLERESIDENTNV*)LoadFunction("glIsTextureHandleResidentNV");
    glIsImageHandleResidentNV = (GLISIMAGEHANDLERESIDENTNV*)LoadFunction("glIsImageHandleResidentNV");
    glBlendParameteriNV = (GLBLENDPARAMETERINV*)LoadFunction("glBlendParameteriNV");
    glBlendBarrierNV = (GLBLENDBARRIERNV*)LoadFunction("glBlendBarrierNV");
    glBeginConditionalRenderNV = (GLBEGINCONDITIONALRENDERNV*)LoadFunction("glBeginConditionalRenderNV");
    glEndConditionalRenderNV = (GLENDCONDITIONALRENDERNV*)LoadFunction("glEndConditionalRenderNV");
    glSubpixelPrecisionBiasNV = (GLSUBPIXELPRECISIONBIASNV*)LoadFunction("glSubpixelPrecisionBiasNV");
    glConservativeRasterParameteriNV = (GLCONSERVATIVERASTERPARAMETERINV*)LoadFunction("glConservativeRasterParameteriNV");
    glDrawVkImageNV = (GLDRAWVKIMAGENV*)LoadFunction("glDrawVkImageNV");
    glGetVkProcAddrNV = (GLGETVKPROCADDRNV*)LoadFunction("glGetVkProcAddrNV");
    glWaitVkSemaphoreNV = (GLWAITVKSEMAPHORENV*)LoadFunction("glWaitVkSemaphoreNV");
    glSignalVkSemaphoreNV = (GLSIGNALVKSEMAPHORENV*)LoadFunction("glSignalVkSemaphoreNV");
    glSignalVkFenceNV = (GLSIGNALVKFENCENV*)LoadFunction("glSignalVkFenceNV");
    glFragmentCoverageColorNV = (GLFRAGMENTCOVERAGECOLORNV*)LoadFunction("glFragmentCoverageColorNV");
    glCoverageModulationTableNV = (GLCOVERAGEMODULATIONTABLENV*)LoadFunction("glCoverageModulationTableNV");
    glGetCoverageModulationTableNV = (GLGETCOVERAGEMODULATIONTABLENV*)LoadFunction("glGetCoverageModulationTableNV");
    glCoverageModulationNV = (GLCOVERAGEMODULATIONNV*)LoadFunction("glCoverageModulationNV");
    glUniform1i64NV = (GLUNIFORM1I64NV*)LoadFunction("glUniform1i64NV");
    glUniform2i64NV = (GLUNIFORM2I64NV*)LoadFunction("glUniform2i64NV");
    glUniform3i64NV = (GLUNIFORM3I64NV*)LoadFunction("glUniform3i64NV");
    glUniform4i64NV = (GLUNIFORM4I64NV*)LoadFunction("glUniform4i64NV");
    glUniform1i64vNV = (GLUNIFORM1I64VNV*)LoadFunction("glUniform1i64vNV");
    glUniform2i64vNV = (GLUNIFORM2I64VNV*)LoadFunction("glUniform2i64vNV");
    glUniform3i64vNV = (GLUNIFORM3I64VNV*)LoadFunction("glUniform3i64vNV");
    glUniform4i64vNV = (GLUNIFORM4I64VNV*)LoadFunction("glUniform4i64vNV");
    glUniform1ui64NV = (GLUNIFORM1UI64NV*)LoadFunction("glUniform1ui64NV");
    glUniform2ui64NV = (GLUNIFORM2UI64NV*)LoadFunction("glUniform2ui64NV");
    glUniform3ui64NV = (GLUNIFORM3UI64NV*)LoadFunction("glUniform3ui64NV");
    glUniform4ui64NV = (GLUNIFORM4UI64NV*)LoadFunction("glUniform4ui64NV");
    glUniform1ui64vNV = (GLUNIFORM1UI64VNV*)LoadFunction("glUniform1ui64vNV");
    glUniform2ui64vNV = (GLUNIFORM2UI64VNV*)LoadFunction("glUniform2ui64vNV");
    glUniform3ui64vNV = (GLUNIFORM3UI64VNV*)LoadFunction("glUniform3ui64vNV");
    glUniform4ui64vNV = (GLUNIFORM4UI64VNV*)LoadFunction("glUniform4ui64vNV");
    glGetUniformi64vNV = (GLGETUNIFORMI64VNV*)LoadFunction("glGetUniformi64vNV");
    glProgramUniform1i64NV = (GLPROGRAMUNIFORM1I64NV*)LoadFunction("glProgramUniform1i64NV");
    glProgramUniform2i64NV = (GLPROGRAMUNIFORM2I64NV*)LoadFunction("glProgramUniform2i64NV");
    glProgramUniform3i64NV = (GLPROGRAMUNIFORM3I64NV*)LoadFunction("glProgramUniform3i64NV");
    glProgramUniform4i64NV = (GLPROGRAMUNIFORM4I64NV*)LoadFunction("glProgramUniform4i64NV");
    glProgramUniform1i64vNV = (GLPROGRAMUNIFORM1I64VNV*)LoadFunction("glProgramUniform1i64vNV");
    glProgramUniform2i64vNV = (GLPROGRAMUNIFORM2I64VNV*)LoadFunction("glProgramUniform2i64vNV");
    glProgramUniform3i64vNV = (GLPROGRAMUNIFORM3I64VNV*)LoadFunction("glProgramUniform3i64vNV");
    glProgramUniform4i64vNV = (GLPROGRAMUNIFORM4I64VNV*)LoadFunction("glProgramUniform4i64vNV");
    glProgramUniform1ui64NV = (GLPROGRAMUNIFORM1UI64NV*)LoadFunction("glProgramUniform1ui64NV");
    glProgramUniform2ui64NV = (GLPROGRAMUNIFORM2UI64NV*)LoadFunction("glProgramUniform2ui64NV");
    glProgramUniform3ui64NV = (GLPROGRAMUNIFORM3UI64NV*)LoadFunction("glProgramUniform3ui64NV");
    glProgramUniform4ui64NV = (GLPROGRAMUNIFORM4UI64NV*)LoadFunction("glProgramUniform4ui64NV");
    glProgramUniform1ui64vNV = (GLPROGRAMUNIFORM1UI64VNV*)LoadFunction("glProgramUniform1ui64vNV");
    glProgramUniform2ui64vNV = (GLPROGRAMUNIFORM2UI64VNV*)LoadFunction("glProgramUniform2ui64vNV");
    glProgramUniform3ui64vNV = (GLPROGRAMUNIFORM3UI64VNV*)LoadFunction("glProgramUniform3ui64vNV");
    glProgramUniform4ui64vNV = (GLPROGRAMUNIFORM4UI64VNV*)LoadFunction("glProgramUniform4ui64vNV");
    glGetInternalformatSampleivNV = (GLGETINTERNALFORMATSAMPLEIVNV*)LoadFunction("glGetInternalformatSampleivNV");
    glGenPathsNV = (GLGENPATHSNV*)LoadFunction("glGenPathsNV");
    glDeletePathsNV = (GLDELETEPATHSNV*)LoadFunction("glDeletePathsNV");
    glIsPathNV = (GLISPATHNV*)LoadFunction("glIsPathNV");
    glPathCommandsNV = (GLPATHCOMMANDSNV*)LoadFunction("glPathCommandsNV");
    glPathCoordsNV = (GLPATHCOORDSNV*)LoadFunction("glPathCoordsNV");
    glPathSubCommandsNV = (GLPATHSUBCOMMANDSNV*)LoadFunction("glPathSubCommandsNV");
    glPathSubCoordsNV = (GLPATHSUBCOORDSNV*)LoadFunction("glPathSubCoordsNV");
    glPathStringNV = (GLPATHSTRINGNV*)LoadFunction("glPathStringNV");
    glPathGlyphsNV = (GLPATHGLYPHSNV*)LoadFunction("glPathGlyphsNV");
    glPathGlyphRangeNV = (GLPATHGLYPHRANGENV*)LoadFunction("glPathGlyphRangeNV");
    glWeightPathsNV = (GLWEIGHTPATHSNV*)LoadFunction("glWeightPathsNV");
    glCopyPathNV = (GLCOPYPATHNV*)LoadFunction("glCopyPathNV");
    glInterpolatePathsNV = (GLINTERPOLATEPATHSNV*)LoadFunction("glInterpolatePathsNV");
    glTransformPathNV = (GLTRANSFORMPATHNV*)LoadFunction("glTransformPathNV");
    glPathParameterivNV = (GLPATHPARAMETERIVNV*)LoadFunction("glPathParameterivNV");
    glPathParameteriNV = (GLPATHPARAMETERINV*)LoadFunction("glPathParameteriNV");
    glPathParameterfvNV = (GLPATHPARAMETERFVNV*)LoadFunction("glPathParameterfvNV");
    glPathParameterfNV = (GLPATHPARAMETERFNV*)LoadFunction("glPathParameterfNV");
    glPathDashArrayNV = (GLPATHDASHARRAYNV*)LoadFunction("glPathDashArrayNV");
    glPathStencilFuncNV = (GLPATHSTENCILFUNCNV*)LoadFunction("glPathStencilFuncNV");
    glPathStencilDepthOffsetNV = (GLPATHSTENCILDEPTHOFFSETNV*)LoadFunction("glPathStencilDepthOffsetNV");
    glStencilFillPathNV = (GLSTENCILFILLPATHNV*)LoadFunction("glStencilFillPathNV");
    glStencilStrokePathNV = (GLSTENCILSTROKEPATHNV*)LoadFunction("glStencilStrokePathNV");
    glStencilFillPathInstancedNV = (GLSTENCILFILLPATHINSTANCEDNV*)LoadFunction("glStencilFillPathInstancedNV");
    glStencilStrokePathInstancedNV = (GLSTENCILSTROKEPATHINSTANCEDNV*)LoadFunction("glStencilStrokePathInstancedNV");
    glPathCoverDepthFuncNV = (GLPATHCOVERDEPTHFUNCNV*)LoadFunction("glPathCoverDepthFuncNV");
    glCoverFillPathNV = (GLCOVERFILLPATHNV*)LoadFunction("glCoverFillPathNV");
    glCoverStrokePathNV = (GLCOVERSTROKEPATHNV*)LoadFunction("glCoverStrokePathNV");
    glCoverFillPathInstancedNV = (GLCOVERFILLPATHINSTANCEDNV*)LoadFunction("glCoverFillPathInstancedNV");
    glCoverStrokePathInstancedNV = (GLCOVERSTROKEPATHINSTANCEDNV*)LoadFunction("glCoverStrokePathInstancedNV");
    glGetPathParameterivNV = (GLGETPATHPARAMETERIVNV*)LoadFunction("glGetPathParameterivNV");
    glGetPathParameterfvNV = (GLGETPATHPARAMETERFVNV*)LoadFunction("glGetPathParameterfvNV");
    glGetPathCommandsNV = (GLGETPATHCOMMANDSNV*)LoadFunction("glGetPathCommandsNV");
    glGetPathCoordsNV = (GLGETPATHCOORDSNV*)LoadFunction("glGetPathCoordsNV");
    glGetPathDashArrayNV = (GLGETPATHDASHARRAYNV*)LoadFunction("glGetPathDashArrayNV");
    glGetPathMetricsNV = (GLGETPATHMETRICSNV*)LoadFunction("glGetPathMetricsNV");
    glGetPathMetricRangeNV = (GLGETPATHMETRICRANGENV*)LoadFunction("glGetPathMetricRangeNV");
    glGetPathSpacingNV = (GLGETPATHSPACINGNV*)LoadFunction("glGetPathSpacingNV");
    glIsPointInFillPathNV = (GLISPOINTINFILLPATHNV*)LoadFunction("glIsPointInFillPathNV");
    glIsPointInStrokePathNV = (GLISPOINTINSTROKEPATHNV*)LoadFunction("glIsPointInStrokePathNV");
    glGetPathLengthNV = (GLGETPATHLENGTHNV*)LoadFunction("glGetPathLengthNV");
    glPointAlongPathNV = (GLPOINTALONGPATHNV*)LoadFunction("glPointAlongPathNV");
    glMatrixLoad3x2fNV = (GLMATRIXLOAD3X2FNV*)LoadFunction("glMatrixLoad3x2fNV");
    glMatrixLoad3x3fNV = (GLMATRIXLOAD3X3FNV*)LoadFunction("glMatrixLoad3x3fNV");
    glMatrixLoadTranspose3x3fNV = (GLMATRIXLOADTRANSPOSE3X3FNV*)LoadFunction("glMatrixLoadTranspose3x3fNV");
    glMatrixMult3x2fNV = (GLMATRIXMULT3X2FNV*)LoadFunction("glMatrixMult3x2fNV");
    glMatrixMult3x3fNV = (GLMATRIXMULT3X3FNV*)LoadFunction("glMatrixMult3x3fNV");
    glMatrixMultTranspose3x3fNV = (GLMATRIXMULTTRANSPOSE3X3FNV*)LoadFunction("glMatrixMultTranspose3x3fNV");
    glStencilThenCoverFillPathNV = (GLSTENCILTHENCOVERFILLPATHNV*)LoadFunction("glStencilThenCoverFillPathNV");
    glStencilThenCoverStrokePathNV = (GLSTENCILTHENCOVERSTROKEPATHNV*)LoadFunction("glStencilThenCoverStrokePathNV");
    glStencilThenCoverFillPathInstancedNV = (GLSTENCILTHENCOVERFILLPATHINSTANCEDNV*)LoadFunction("glStencilThenCoverFillPathInstancedNV");
    glStencilThenCoverStrokePathInstancedNV = (GLSTENCILTHENCOVERSTROKEPATHINSTANCEDNV*)LoadFunction("glStencilThenCoverStrokePathInstancedNV");
    glPathGlyphIndexRangeNV = (GLPATHGLYPHINDEXRANGENV*)LoadFunction("glPathGlyphIndexRangeNV");
    glPathGlyphIndexArrayNV = (GLPATHGLYPHINDEXARRAYNV*)LoadFunction("glPathGlyphIndexArrayNV");
    glPathMemoryGlyphIndexArrayNV = (GLPATHMEMORYGLYPHINDEXARRAYNV*)LoadFunction("glPathMemoryGlyphIndexArrayNV");
    glProgramPathFragmentInputGenNV = (GLPROGRAMPATHFRAGMENTINPUTGENNV*)LoadFunction("glProgramPathFragmentInputGenNV");
    glGetProgramResourcefvNV = (GLGETPROGRAMRESOURCEFVNV*)LoadFunction("glGetProgramResourcefvNV");
    glFramebufferSampleLocationsfvNV = (GLFRAMEBUFFERSAMPLELOCATIONSFVNV*)LoadFunction("glFramebufferSampleLocationsfvNV");
    glNamedFramebufferSampleLocationsfvNV = (GLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVNV*)LoadFunction("glNamedFramebufferSampleLocationsfvNV");
    glResolveDepthValuesNV = (GLRESOLVEDEPTHVALUESNV*)LoadFunction("glResolveDepthValuesNV");
    glViewportSwizzleNV = (GLVIEWPORTSWIZZLENV*)LoadFunction("glViewportSwizzleNV");
    glFramebufferTextureMultiviewOVR = (GLFRAMEBUFFERTEXTUREMULTIVIEWOVR*)LoadFunction("glFramebufferTextureMultiviewOVR");
}

#endif
