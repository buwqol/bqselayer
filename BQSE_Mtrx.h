#ifndef BQSELAYER_MTRX_H
#define BQSELAYER_MTRX_H
#include "BQSE_PrimTypes.h"
#include "BQSE_Vect.h"
typedef union { struct { tF32 m00, m01; tF32 m10, m11; }; tF32 m[2][2]; tF32V2D row[2]; } tF32M2x2;
tF32M2x2 tF32M2x2_Make(tF32 m00, tF32 m01, tF32 m10, tF32 m11);
tF32M2x2 tF32M2x2_Zero(tNone);
tF32M2x2 tF32M2x2_Id(tNone);
tF32M2x2 tF32M2x2_Add(tF32M2x2 mat1, tF32M2x2 mat2);
tF32M2x2 tF32M2x2_Sub(tF32M2x2 mat1, tF32M2x2 mat2);
tF32M2x2 tF32M2x2_Mul(tF32M2x2 mat1, tF32M2x2 mat2);
tF32M2x2 tF32M2x2_MulFlt(tF32M2x2 mat, tF32 mod);
/*Warn: Silently returns `tF32M2x2_Zero` on failure when BQSE_DEBUG is not defined.*/
tF32M2x2 tF32M2x2_DivFlt(tF32M2x2 mat, tF32 mod);
/*Note: Returns `False` on success.*/
tBln tF32M2x2_DivFlt_safe(tF32M2x2 *mat, tF32 mod);
tBln tF32M2x2_Eq(tF32M2x2 mat1, tF32M2x2 mat2);
tBln tF32M2x2_Nearby(tF32M2x2 mat1, tF32M2x2 mat2, tF32 eps);
tF32V2D tF32M2x2_MulVec(tF32M2x2 mat, tF32V2D vec);
tF32M2x2 tF32M2x2_Transp(tF32M2x2 mat);
tF32 tF32M2x2_Det(tF32M2x2 mat);
tF32M2x2 tF32M2x2_Cofact(tF32M2x2 mat);
tF32M2x2 tF32M2x2_Adj(tF32M2x2 mat);
/*Warn: Silently returns `tF32M2x2_Zero` on failure when BQSE_DEBUG is not defined.*/
tF32M2x2 tF32M2x2_Inv(tF32M2x2 mat);
/*Note: Returns `False` on success.*/
tBln tF32M2x2_Inv_safe(tF32M2x2 *mat);
tF32M2x2 tF32M2x2_Rot(tF32 ang);
tF32M2x2 tF32M2x2_Scale(tF32 x, tF32 y);
tF32 tF32M2x2_Trace(tF32M2x2 mat);
// TODO: Implement row reduction for all matrices.
// TODO: Implement row echelon form for all matrices.
#ifdef BQSE_MASTER
tF32M2x2 tF32M2x2_Make(tF32 m00, tF32 m01, tF32 m10, tF32 m11)
{
	tF32M2x2 mat;
	mat.m00 = m00;
	mat.m01 = m01;
	mat.m10 = m10;
	mat.m11 = m11;
	return mat;
}
tF32M2x2 tF32M2x2_Zero(tNone)
{
	tF32M2x2 mat;
	mat.m00 = 0.0F;
	mat.m01 = 0.0F;
	mat.m10 = 0.0F;
	mat.m11 = 0.0F;
	return mat;
}
tF32M2x2 tF32M2x2_Id(tNone)
{
	tF32M2x2 mat;
	mat.m00 = 1.0F;
	mat.m01 = 0.0F;
	mat.m10 = 0.0F;
	mat.m11 = 1.0F;
	return mat;
}
tF32M2x2 tF32M2x2_Add(tF32M2x2 mat1, tF32M2x2 mat2)
{
	mat1.m00 += mat2.m00;
	mat1.m01 += mat2.m01;
	mat1.m10 += mat2.m10;
	mat1.m11 += mat2.m11;
	return mat1;
}
tF32M2x2 tF32M2x2_Sub(tF32M2x2 mat1, tF32M2x2 mat2)
{
	mat1.m00 -= mat2.m00;
	mat1.m01 -= mat2.m01;
	mat1.m10 -= mat2.m10;
	mat1.m11 -= mat2.m11;
	return mat1;
}
tF32M2x2 tF32M2x2_Mul(tF32M2x2 mat1, tF32M2x2 mat2)
{
	tF32M2x2 mat;
	mat.m00 = mat1.m00 * mat2.m00 + mat1.m01 * mat2.m10;
	mat.m01 = mat1.m00 * mat2.m01 + mat1.m01 * mat2.m11;
	mat.m10 = mat1.m10 * mat2.m00 + mat1.m11 * mat2.m10;
	mat.m11 = mat1.m10 * mat2.m01 + mat1.m11 * mat2.m11;
	return mat;
}
tF32M2x2 tF32M2x2_MulFlt(tF32M2x2 mat, tF32 mod)
{
	mat.m00 *= mod;
	mat.m01 *= mod;
	mat.m10 *= mod;
	mat.m11 *= mod;
	return mat;
}
tF32M2x2 tF32M2x2_DivFlt(tF32M2x2 mat, tF32 mod)
{
#ifndef BQSE_DEBUG
	if (mod == 0.0F) return tF32M2x2_Zero();
#else
	Assertion(mod != 0.0F);
#endif
	mat.m00 /= mod;
	mat.m01 /= mod;
	mat.m10 /= mod;
	mat.m11 /= mod;
	return mat;
}
tBln tF32M2x2_DivFlt_safe(tF32M2x2 *mat, tF32 mod)
{
	if (mod == 0.0F) return True;
	mat->m00 /= mod;
	mat->m01 /= mod;
	mat->m10 /= mod;
	mat->m11 /= mod;
	return False;
}
tBln tF32M2x2_Eq(tF32M2x2 mat1, tF32M2x2 mat2)
{
	return (mat1.m00 == mat2.m00) && (mat1.m01 == mat2.m01) && (mat1.m10 == mat2.m10) && (mat1.m11 == mat2.m11);
}
tBln tF32M2x2_Nearby(tF32M2x2 mat1, tF32M2x2 mat2, tF32 eps)
{
	return (tF32_Abs(mat1.m00 - mat2.m00) <= eps) && (tF32_Abs(mat1.m01 - mat2.m01) <= eps) && (tF32_Abs(mat1.m10 - mat2.m10) <= eps) && (tF32_Abs(mat1.m11 - mat2.m11) <= eps);
}
tF32V2D tF32M2x2_MulVec(tF32M2x2 mat, tF32V2D vec)
{
	tF32V2D res;
	res.x = mat.m00 * vec.x + mat.m01 * vec.y;
	res.y = mat.m10 * vec.x + mat.m11 * vec.y;
	return res;
}
tF32M2x2 tF32M2x2_Transp(tF32M2x2 mat)
{
	tF32 tmp = mat.m01;
	mat.m01 = mat.m10;
	mat.m10 = tmp;
	return mat;
}
tF32 tF32M2x2_Det(tF32M2x2 mat)
{
	return (mat.m00 * mat.m11) - (mat.m01 * mat.m10);
}
tF32M2x2 tF32M2x2_Cofact(tF32M2x2 mat)
{
	tF32 tmp = mat.m00;
	mat.m00 = mat.m11;
	mat.m11 = tmp;
	mat.m01 = tF32_Neg(mat.m10);
	mat.m10 = tF32_Neg(mat.m01);
	return mat;
}
tF32M2x2 tF32M2x2_Adj(tF32M2x2 mat)
{
	tF32 tmp = mat.m00;
	mat.m00 = mat.m11;
	mat.m11 = tmp;
	mat.m01 = tF32_Neg(mat.m01);
	mat.m10 = tF32_Neg(mat.m10);
	return mat;
}
tF32M2x2 tF32M2x2_Inv(tF32M2x2 mat)
{
	tF32 det = tF32M2x2_Det(mat);
#ifndef BQSE_DEBUG
	if (tF32_Abs(det) <= tF32_Eps) return tF32M2x2_Zero();
#else
	Assertion(tF32_Abs(det) > tF32_Eps);
#endif
	return tF32M2x2_DivFlt(tF32M2x2_Adj(mat), det);
}
tBln tF32M2x2_Inv_safe(tF32M2x2 *mat)
{
	tF32 det = tF32M2x2_Det(*mat);
	if (tF32_Abs(det) <= tF32_Eps) return True;
	*mat = tF32M2x2_DivFlt(tF32M2x2_Adj(*mat), det);
	return False;
}
tF32M2x2 tF32M2x2_Rot(tF32 ang)
{
	tF32M2x2 mat;
	mat.m00 = mat.m11 = tF32_Cosine(ang);
	mat.m10 = tF32_Sine(ang);
	mat.m01 = tF32_Neg(mat.m10);
	return mat;
}
tF32M2x2 tF32M2x2_Scale(tF32 x, tF32 y)
{
	tF32M2x2 mat;
	mat.m00 = x;
	mat.m11 = y;
	mat.m01 = mat.m10 = 0.0F;
	return mat;
}
tF32 tF32M2x2_Trace(tF32M2x2 mat)
{
	return mat.m00 + mat.m11;
}
#endif
typedef union { struct { tF32 m00, m01, m02; tF32 m10, m11, m12; tF32 m20, m21, m22; }; tF32 m[3][3]; tF32V3D row[3]; } tF32M3x3;
tF32M3x3 tF32M3x3_Make(tF32 m00, tF32 m01, tF32 m02, tF32 m10, tF32 m11, tF32 m12, tF32 m20, tF32 m21, tF32 m22);
tF32M3x3 tF32M3x3_Zero(tNone);
tF32M3x3 tF32M3x3_Id(tNone);
tF32M3x3 tF32M3x3_Add(tF32M3x3 mat1, tF32M3x3 mat2);
tF32M3x3 tF32M3x3_Sub(tF32M3x3 mat1, tF32M3x3 mat2);
tF32M3x3 tF32M3x3_Mul(tF32M3x3 mat1, tF32M3x3 mat2);
tF32M3x3 tF32M3x3_MulFlt(tF32M3x3 mat, tF32 mod);
/*Warn: Silently returns `tF32M3x3_Zero` on failure when BQSE_DEBUG is not defined.*/
tF32M3x3 tF32M3x3_DivFlt(tF32M3x3 mat, tF32 mod);
/*Note: Returns `False` on success.*/
tBln tF32M3x3_DivFlt_safe(tF32M3x3 *mat, tF32 mod);
tBln tF32M3x3_Eq(tF32M3x3 mat1, tF32M3x3 mat2);
tBln tF32M3x3_Nearby(tF32M3x3 mat1, tF32M3x3 mat2, tF32 eps);
tF32V3D tF32M3x3_MulVec(tF32M3x3 mat, tF32V3D vec);
tF32M3x3 tF32M3x3_Transp(tF32M3x3 mat);
tF32 tF32M3x3_Det(tF32M3x3 mat);
tF32M3x3 tF32M3x3_Cofact(tF32M3x3 mat);
tF32M3x3 tF32M3x3_Adj(tF32M3x3 mat);
/*Warn: Silently returns `tF32M3x3_Zero` on failure when BQSE_DEBUG is not defined.*/
tF32M3x3 tF32M3x3_Inv(tF32M3x3 mat);
/*Note: Returns `False` on success.*/
tBln tF32M3x3_Inv_safe(tF32M3x3 *mat);
tF32M3x3 tF32M3x3_Transl(tF32 x, tF32 y);
tF32M3x3 tF32M3x3_Scale(tF32 x, tF32 y);
tF32M3x3 tF32M3x3_Rot(tF32 ang);
tF32 tF32M3x3_Trace(tF32M3x3 mat);
tF32V2D tF32M3x3_TransfPoint(tF32M3x3 mat, tF32V2D vec);
tF32V2D tF32M3x3_TransfDir(tF32M3x3 mat, tF32V2D vec);
#ifdef BQSE_MASTER
tF32M3x3 tF32M3x3_Make(tF32 m00, tF32 m01, tF32 m02, tF32 m10, tF32 m11, tF32 m12, tF32 m20, tF32 m21, tF32 m22)
{
	tF32M3x3 mat;
	mat.m00 = m00;
	mat.m01 = m01;
	mat.m02 = m02;
	mat.m10 = m10;
	mat.m11 = m11;
	mat.m12 = m12;
	mat.m20 = m20;
	mat.m21 = m21;
	mat.m22 = m22;
	return mat;
}
tF32M3x3 tF32M3x3_Zero(tNone)
{
	tF32M3x3 mat;
	mat.m00 = mat.m01 = mat.m02 = mat.m10 = mat.m11 = mat.m12 = mat.m20 = mat.m21 = mat.m22 = 0.0F;
	return mat;
}
tF32M3x3 tF32M3x3_Id(tNone)
{
	tF32M3x3 mat;
	mat.m01 = mat.m02 = mat.m10 = mat.m12 = mat.m20 = mat.m21 = 0.0F;
	mat.m00 = mat.m11 = mat.m22 = 1.0F;
	return mat;
}
tF32M3x3 tF32M3x3_Add(tF32M3x3 mat1, tF32M3x3 mat2)
{
	mat1.m00 += mat2.m00;
	mat1.m01 += mat2.m01;
	mat1.m02 += mat2.m02;
	mat1.m10 += mat2.m10;
	mat1.m11 += mat2.m11;
	mat1.m12 += mat2.m12;
	mat1.m20 += mat2.m20;
	mat1.m21 += mat2.m21;
	mat1.m22 += mat2.m22;
	return mat1;
}
tF32M3x3 tF32M3x3_Sub(tF32M3x3 mat1, tF32M3x3 mat2)
{
	mat1.m00 -= mat2.m00;
	mat1.m01 -= mat2.m01;
	mat1.m02 -= mat2.m02;
	mat1.m10 -= mat2.m10;
	mat1.m11 -= mat2.m11;
	mat1.m12 -= mat2.m12;
	mat1.m20 -= mat2.m20;
	mat1.m21 -= mat2.m21;
	mat1.m22 -= mat2.m22;
	return mat1;
}
tF32M3x3 tF32M3x3_Mul(tF32M3x3 mat1, tF32M3x3 mat2)
{
	tF32M3x3 res;
	res.m00 = (mat1.m00 * mat2.m00) + (mat1.m01 * mat2.m10) + (mat1.m02 * mat2.m20);
	res.m01 = (mat1.m00 * mat2.m01) + (mat1.m01 * mat2.m11) + (mat1.m02 * mat2.m21);
	res.m02 = (mat1.m00 * mat2.m02) + (mat1.m01 * mat2.m12) + (mat1.m02 * mat2.m22);
	res.m10 = (mat1.m10 * mat2.m00) + (mat1.m11 * mat2.m10) + (mat1.m12 * mat2.m20);
	res.m11 = (mat1.m10 * mat2.m01) + (mat1.m11 * mat2.m11) + (mat1.m12 * mat2.m21);
	res.m12 = (mat1.m10 * mat2.m02) + (mat1.m11 * mat2.m12) + (mat1.m12 * mat2.m22);
	res.m20 = (mat1.m20 * mat2.m00) + (mat1.m21 * mat2.m10) + (mat1.m22 * mat2.m20);
	res.m21 = (mat1.m20 * mat2.m01) + (mat1.m21 * mat2.m11) + (mat1.m22 * mat2.m21);
	res.m22 = (mat1.m20 * mat2.m02) + (mat1.m21 * mat2.m12) + (mat1.m22 * mat2.m22);
	return res;
}
tF32M3x3 tF32M3x3_MulFlt(tF32M3x3 mat, tF32 mod)
{
	mat.m00 *= mod;
	mat.m01 *= mod;
	mat.m02 *= mod;
	mat.m10 *= mod;
	mat.m11 *= mod;
	mat.m12 *= mod;
	mat.m20 *= mod;
	mat.m21 *= mod;
	mat.m22 *= mod;
	return mat;
}
tF32M3x3 tF32M3x3_DivFlt(tF32M3x3 mat, tF32 mod)
{
#ifndef BQSE_DEBUG
	if (mod == 0.0F) return tF32M3x3_Zero();
#else
	Assertion(mod != 0.0F);
#endif
	mat.m00 /= mod;
	mat.m01 /= mod;
	mat.m02 /= mod;
	mat.m10 /= mod;
	mat.m11 /= mod;
	mat.m12 /= mod;
	mat.m20 /= mod;
	mat.m21 /= mod;
	mat.m22 /= mod;
	return mat;
}
tBln tF32M3x3_DivFlt_safe(tF32M3x3 *mat, tF32 mod)
{
	if (mod == 0.0F) return True;
	mat->m00 /= mod;
	mat->m01 /= mod;
	mat->m02 /= mod;
	mat->m10 /= mod;
	mat->m11 /= mod;
	mat->m12 /= mod;
	mat->m20 /= mod;
	mat->m21 /= mod;
	mat->m22 /= mod;
	return False;
}
tBln tF32M3x3_Eq(tF32M3x3 mat1, tF32M3x3 mat2)
{
	return (mat1.m00 == mat2.m00) && (mat1.m01 == mat2.m01) && (mat1.m02 == mat2.m02) && (mat1.m10 == mat2.m10) && (mat1.m11 == mat2.m11) && (mat1.m12 == mat2.m12) && (mat1.m20 == mat2.m20) && (mat1.m21 == mat2.m21) && (mat1.m22 == mat2.m22);
}
tBln tF32M3x3_Nearby(tF32M3x3 mat1, tF32M3x3 mat2, tF32 eps)
{
	return (tF32_Abs(mat1.m00 - mat2.m00) <= eps) && (tF32_Abs(mat1.m01 - mat2.m01) <= eps) && (tF32_Abs(mat1.m02 - mat2.m02) <= eps) && (tF32_Abs(mat1.m10 - mat2.m10) <= eps) && (tF32_Abs(mat1.m11 - mat2.m11) <= eps) && (tF32_Abs(mat1.m12 - mat2.m12) <= eps) && (tF32_Abs(mat1.m20 - mat2.m20) <= eps) && (tF32_Abs(mat1.m21 - mat2.m21) <= eps) && (tF32_Abs(mat1.m22 - mat2.m22) <= eps);
}
tF32V3D tF32M3x3_MulVec(tF32M3x3 mat, tF32V3D vec)
{
	tF32V3D res;
	res.x = (mat.m00 * vec.x) + (mat.m01 * vec.y) + (mat.m02 * vec.z);
	res.y = (mat.m10 * vec.x) + (mat.m11 * vec.y) + (mat.m12 * vec.z);
	res.z = (mat.m20 * vec.x) + (mat.m21 * vec.y) + (mat.m22 * vec.z);
	return res;
}
tF32M3x3 tF32M3x3_Transp(tF32M3x3 mat)
{
	tF32 tmp = mat.m01;
	mat.m01 = mat.m10;
	mat.m10 = tmp;
	tmp = mat.m02;
	mat.m02 = mat.m20;
	mat.m20 = tmp;
	tmp = mat.m12;
	mat.m12 = mat.m21;
	mat.m21 = tmp;
	return mat;
}
tF32 tF32M3x3_Det(tF32M3x3 mat)
{
	return (mat.m00 * ((mat.m11 * mat.m22) - (mat.m12 * mat.m21))) - (mat.m01 * ((mat.m10 * mat.m22) - (mat.m12 * mat.m20))) + (mat.m02 * ((mat.m10 * mat.m21) - (mat.m11 * mat.m20)));
}
tF32M3x3 tF32M3x3_Cofact(tF32M3x3 mat)
{
	tF32M3x3 cof;
	cof.m00 = mat.m11 * mat.m22 - mat.m12 * mat.m21;
	cof.m01 = tF32_Neg(mat.m10 * mat.m22 - mat.m12 * mat.m20);
	cof.m02 = mat.m10 * mat.m21 - mat.m11 * mat.m20;
	cof.m10 = tF32_Neg(mat.m01 * mat.m22 - mat.m02 * mat.m21);
	cof.m11 = mat.m00 * mat.m22 - mat.m02 * mat.m20;
	cof.m12 = tF32_Neg(mat.m00 * mat.m21 - mat.m01 * mat.m20);
	cof.m20 = mat.m01 * mat.m12 - mat.m02 * mat.m11;
	cof.m21 = tF32_Neg(mat.m00 * mat.m12 - mat.m02 * mat.m10);
	cof.m22 = mat.m00 * mat.m11 - mat.m01 * mat.m10;
	return cof;
}
tF32M3x3 tF32M3x3_Adj(tF32M3x3 mat)
{
	return tF32M3x3_Transp(tF32M3x3_Cofact(mat));
}
tF32M3x3 tF32M3x3_Inv(tF32M3x3 mat)
{
	tF32 det = tF32M3x3_Det(mat);
#ifndef BQSE_DEBUG
	if (tF32_Abs(det) <= tF32_Eps) return tF32M3x3_Zero();
#else
	Assertion(tF32_Abs(det) > tF32_Eps);
#endif
	return tF32M3x3_DivFlt(tF32M3x3_Adj(mat), det);
}
tBln tF32M3x3_Inv_safe(tF32M3x3 *mat)
{
	tF32 det = tF32M3x3_Det(*mat);
	if (tF32_Abs(det) <= tF32_Eps) return True;
	*mat = tF32M3x3_DivFlt(tF32M3x3_Adj(*mat), det);
	return False;
}
tF32M3x3 tF32M3x3_Transl(tF32 x, tF32 y)
{
	tF32M3x3 mat = tF32M3x3_Id();
	mat.m02 = x;
	mat.m12 = y;
	return mat;
}
tF32M3x3 tF32M3x3_Scale(tF32 x, tF32 y)
{
	tF32M3x3 mat = tF32M3x3_Id();
	mat.m00 = x;
	mat.m11 = y;
	return mat;
}
tF32M3x3 tF32M3x3_Rot(tF32 ang)
{
	tF32M3x3 mat = tF32M3x3_Id();
	mat.m00 = mat.m11 = tF32_Cosine(ang);
	mat.m10 = tF32_Sine(ang);
	mat.m01 = tF32_Neg(mat.m10);
	return mat;
}
tF32 tF32M3x3_Trace(tF32M3x3 mat)
{
	return mat.m00 + mat.m11 + mat.m22;
}
tF32V2D tF32M3x3_TransfPoint(tF32M3x3 mat, tF32V2D vec)
{
	tF32V2D res;
	res.x = mat.m00 * vec.x + mat.m01 * vec.y + mat.m02;
	res.y = mat.m10 * vec.x + mat.m11 * vec.y + mat.m12;
	return res;
}
tF32V2D tF32M3x3_TransfDir(tF32M3x3 mat, tF32V2D vec)
{
	tF32V2D res;
	res.x = mat.m00 * vec.x + mat.m01 * vec.y;
	res.y = mat.m10 * vec.x + mat.m11 * vec.y;
	return res;
}
#endif
typedef union { struct { tF32 m00, m01, m02, m03; tF32 m10, m11, m12, m13; tF32 m20, m21, m22, m23; tF32 m30, m31, m32, m33; }; tF32 m[4][4]; tF32V4D row[4]; } tF32M4x4;
tF32M4x4 tF32M4x4_Make(tF32 m00, tF32 m01, tF32 m02, tF32 m03, tF32 m10, tF32 m11, tF32 m12, tF32 m13, tF32 m20, tF32 m21, tF32 m22, tF32 m23, tF32 m30, tF32 m31, tF32 m32, tF32 m33);
tF32M4x4 tF32M4x4_Zero(tNone);
tF32M4x4 tF32M4x4_Id(tNone);
tF32M4x4 tF32M4x4_Add(tF32M4x4 mat1, tF32M4x4 mat2);
tF32M4x4 tF32M4x4_Sub(tF32M4x4 mat1, tF32M4x4 mat2);
tF32M4x4 tF32M4x4_Mul(tF32M4x4 mat1, tF32M4x4 mat2);
tF32M4x4 tF32M4x4_MulFlt(tF32M4x4 mat, tF32 mod);
/*Warn: Silently returns `tF32M4x4_Zero` on failure when BQSE_DEBUG is not defined.*/
tF32M4x4 tF32M4x4_DivFlt(tF32M4x4 mat, tF32 mod);
/*Note: Returns `False` on success.*/
tBln tF32M4x4_DivFlt_safe(tF32M4x4 *mat, tF32 mod);
tBln tF32M4x4_Eq(tF32M4x4 mat1, tF32M4x4 mat2);
tBln tF32M4x4_Nearby(tF32M4x4 mat1, tF32M4x4 mat2, tF32 eps);
tF32V4D tF32M4x4_MulVec(tF32M4x4 mat, tF32V4D vec);
tF32M4x4 tF32M4x4_Transp(tF32M4x4 mat);
tF32 tF32M4x4_Det(tF32M4x4 mat);
// TODO: Do the rest of these
/*Warn: Silently returns `tF32M3x3_Zero` on failure when BQSE_DEBUG is not defined.*/
tF32M3x3 tF32M4x4_Minor(tF32M4x4 mat, tU8 row, tU8 col);
/*Note: Returns `False` on success.*/
tBln tF32M4x4_Minor_s(tF32M3x3 *out, tF32M4x4 mat, tU8 row, tU8 col);
tF32M4x4 tF32M4x4_Cofact(tF32M4x4 mat);
tF32M4x4 tF32M4x4_Adj(tF32M4x4 mat);
/*Warn: Silently returns `tF32M4x4_Zero` on failure when BQSE_DEBUG is not defined.*/
tF32M4x4 tF32M4x4_Inv(tF32M4x4 mat);
/*Note: Returns `False` on success.*/
tBln tF32M4x4_Inv_safe(tF32M4x4 *mat);
tF32M4x4 tF32M4x4_Transl(tF32 x, tF32 y, tF32 z);
tF32M4x4 tF32M4x4_Scale(tF32 x, tF32 y, tF32 z);
tF32M4x4 tF32M4x4_RotX(tF32 ang);
tF32M4x4 tF32M4x4_RotY(tF32 ang);
tF32M4x4 tF32M4x4_RotZ(tF32 ang);
tF32M4x4 tF32M4x4_Persp(tF32 fov, tF32 aspect, tF32 near, tF32 far);
tF32M4x4 tF32M4x4_Ortho(tF32 left, tF32 right, tF32 bot, tF32 top, tF32 near, tF32 far);
tF32 tF32M4x4_Trace(tF32M4x4 mat);
tF32M4x4 tF32M4x4_InvAff(tF32M4x4 mat);
tF32M4x4 tF32M4x4_RotAxis(tF32V3D axis, tF32 ang);
tF32V3D tF32M4x4_TransfPoint(tF32M4x4 mat, tF32V3D vec);
tF32V3D tF32M4x4_TransfDir(tF32M4x4 mat, tF32V3D vec);
#ifdef BQSE_MASTER
tF32M4x4 tF32M4x4_Make(tF32 m00, tF32 m01, tF32 m02, tF32 m03, tF32 m10, tF32 m11, tF32 m12, tF32 m13, tF32 m20, tF32 m21, tF32 m22, tF32 m23, tF32 m30, tF32 m31, tF32 m32, tF32 m33)
{
	tF32M4x4 mat;
	mat.m00 = m00;
	mat.m01 = m01;
	mat.m02 = m02;
	mat.m03 = m03;
	mat.m10 = m10;
	mat.m11 = m11;
	mat.m12 = m12;
	mat.m13 = m13;
	mat.m20 = m20;
	mat.m21 = m21;
	mat.m22 = m22;
	mat.m23 = m23;
	mat.m30 = m30;
	mat.m31 = m31;
	mat.m32 = m32;
	mat.m33 = m33;
	return mat;
}
tF32M4x4 tF32M4x4_Zero(tNone)
{
	tF32M4x4 mat;
	mat.m00 = mat.m01 = mat.m02 = mat.m03 = mat.m10 = mat.m11 = mat.m12 = mat.m13 = mat.m20 = mat.m21 = mat.m22 = mat.m23 = mat.m30 = mat.m31 = mat.m32 = mat.m33 = 0.0F;
	return mat;
}
tF32M4x4 tF32M4x4_Id(tNone)
{
	tF32M4x4 mat;
	mat.m01 = mat.m02 = mat.m03 = mat.m10 = mat.m12 = mat.m13 = mat.m20 = mat.m21 = mat.m23 = mat.m30 = mat.m31 = mat.m32 = 0.0F;
	mat.m00 = mat.m11 = mat.m22 = mat.m33 = 1.0F;
	return mat;
}
tF32M4x4 tF32M4x4_Add(tF32M4x4 mat1, tF32M4x4 mat2)
{
	mat1.m00 += mat2.m00;
	mat1.m01 += mat2.m01;
	mat1.m02 += mat2.m02;
	mat1.m03 += mat2.m03;
	mat1.m10 += mat2.m10;
	mat1.m11 += mat2.m11;
	mat1.m12 += mat2.m12;
	mat1.m13 += mat2.m13;
	mat1.m20 += mat2.m20;
	mat1.m21 += mat2.m21;
	mat1.m22 += mat2.m22;
	mat1.m23 += mat2.m23;
	mat1.m30 += mat2.m30;
	mat1.m31 += mat2.m31;
	mat1.m32 += mat2.m32;
	mat1.m33 += mat2.m33;
	return mat1;
}
tF32M4x4 tF32M4x4_Sub(tF32M4x4 mat1, tF32M4x4 mat2)
{
	mat1.m00 -= mat2.m00;
	mat1.m01 -= mat2.m01;
	mat1.m02 -= mat2.m02;
	mat1.m03 -= mat2.m03;
	mat1.m10 -= mat2.m10;
	mat1.m11 -= mat2.m11;
	mat1.m12 -= mat2.m12;
	mat1.m13 -= mat2.m13;
	mat1.m20 -= mat2.m20;
	mat1.m21 -= mat2.m21;
	mat1.m22 -= mat2.m22;
	mat1.m23 -= mat2.m23;
	mat1.m30 -= mat2.m30;
	mat1.m31 -= mat2.m31;
	mat1.m32 -= mat2.m32;
	mat1.m33 -= mat2.m33;
	return mat1;
}
tF32M4x4 tF32M4x4_Mul(tF32M4x4 mat1, tF32M4x4 mat2)
{
	tF32M4x4 res;
	res.m00 = (mat1.m00 * mat2.m00) + (mat1.m01 * mat2.m10) + (mat1.m02 * mat2.m20) + (mat1.m03 * mat2.m30);
	res.m01 = (mat1.m00 * mat2.m01) + (mat1.m01 * mat2.m11) + (mat1.m02 * mat2.m21) + (mat1.m03 * mat2.m31);
	res.m02 = (mat1.m00 * mat2.m02) + (mat1.m01 * mat2.m12) + (mat1.m02 * mat2.m22) + (mat1.m03 * mat2.m32);
	res.m03 = (mat1.m00 * mat2.m03) + (mat1.m01 * mat2.m13) + (mat1.m02 * mat2.m23) + (mat1.m03 * mat2.m33);
	res.m10 = (mat1.m10 * mat2.m00) + (mat1.m11 * mat2.m10) + (mat1.m12 * mat2.m20) + (mat1.m13 * mat2.m30);
	res.m11 = (mat1.m10 * mat2.m01) + (mat1.m11 * mat2.m11) + (mat1.m12 * mat2.m21) + (mat1.m13 * mat2.m31);
	res.m12 = (mat1.m10 * mat2.m02) + (mat1.m11 * mat2.m12) + (mat1.m12 * mat2.m22) + (mat1.m13 * mat2.m32);
	res.m13 = (mat1.m10 * mat2.m03) + (mat1.m11 * mat2.m13) + (mat1.m12 * mat2.m23) + (mat1.m13 * mat2.m33);
	res.m20 = (mat1.m20 * mat2.m00) + (mat1.m21 * mat2.m10) + (mat1.m22 * mat2.m20) + (mat1.m23 * mat2.m30);
	res.m21 = (mat1.m20 * mat2.m01) + (mat1.m21 * mat2.m11) + (mat1.m22 * mat2.m21) + (mat1.m23 * mat2.m31);
	res.m22 = (mat1.m20 * mat2.m02) + (mat1.m21 * mat2.m12) + (mat1.m22 * mat2.m22) + (mat1.m23 * mat2.m32);
	res.m23 = (mat1.m20 * mat2.m03) + (mat1.m21 * mat2.m13) + (mat1.m22 * mat2.m23) + (mat1.m23 * mat2.m33);
	res.m30 = (mat1.m30 * mat2.m00) + (mat1.m31 * mat2.m10) + (mat1.m32 * mat2.m20) + (mat1.m33 * mat2.m30);
	res.m31 = (mat1.m30 * mat2.m01) + (mat1.m31 * mat2.m11) + (mat1.m32 * mat2.m21) + (mat1.m33 * mat2.m31);
	res.m32 = (mat1.m30 * mat2.m02) + (mat1.m31 * mat2.m12) + (mat1.m32 * mat2.m22) + (mat1.m33 * mat2.m32);
	res.m33 = (mat1.m30 * mat2.m03) + (mat1.m31 * mat2.m13) + (mat1.m32 * mat2.m23) + (mat1.m33 * mat2.m33);
	return res;
}
tF32M4x4 tF32M4x4_MulFlt(tF32M4x4 mat, tF32 mod)
{
	mat.m00 *= mod;
	mat.m01 *= mod;
	mat.m02 *= mod;
	mat.m03 *= mod;
	mat.m10 *= mod;
	mat.m11 *= mod;
	mat.m12 *= mod;
	mat.m13 *= mod;
	mat.m20 *= mod;
	mat.m21 *= mod;
	mat.m22 *= mod;
	mat.m23 *= mod;
	mat.m30 *= mod;
	mat.m31 *= mod;
	mat.m32 *= mod;
	mat.m33 *= mod;
	return mat;
}
tF32M4x4 tF32M4x4_DivFlt(tF32M4x4 mat, tF32 mod)
{
#ifndef BQSE_DEBUG
	if (mod == 0.0F) return tF32M4x4_Zero();
#else
	Assertion(mod != 0.0F);
#endif
	mat.m00 /= mod;
	mat.m01 /= mod;
	mat.m02 /= mod;
	mat.m03 /= mod;
	mat.m10 /= mod;
	mat.m11 /= mod;
	mat.m12 /= mod;
	mat.m13 /= mod;
	mat.m20 /= mod;
	mat.m21 /= mod;
	mat.m22 /= mod;
	mat.m23 /= mod;
	mat.m30 /= mod;
	mat.m31 /= mod;
	mat.m32 /= mod;
	mat.m33 /= mod;
	return mat;
}
tBln tF32M4x4_DivFlt_safe(tF32M4x4 *mat, tF32 mod)
{
	if (mod == 0.0F) return True;
	mat->m00 /= mod;
	mat->m01 /= mod;
	mat->m02 /= mod;
	mat->m03 /= mod;
	mat->m10 /= mod;
	mat->m11 /= mod;
	mat->m12 /= mod;
	mat->m13 /= mod;
	mat->m20 /= mod;
	mat->m21 /= mod;
	mat->m22 /= mod;
	mat->m23 /= mod;
	mat->m30 /= mod;
	mat->m31 /= mod;
	mat->m32 /= mod;
	mat->m33 /= mod;
	return False;
}
tBln tF32M4x4_Eq(tF32M4x4 mat1, tF32M4x4 mat2)
{
	return mat1.m00 == mat2.m00 && mat1.m01 == mat2.m01 && mat1.m02 == mat2.m02 && mat1.m03 == mat2.m03 && mat1.m10 == mat2.m10 && mat1.m11 == mat2.m11 && mat1.m12 == mat2.m12 && mat1.m13 == mat2.m13 && mat1.m20 == mat2.m20 && mat1.m21 == mat2.m21 && mat1.m22 == mat2.m22 && mat1.m23 == mat2.m23 && mat1.m30 == mat2.m30 && mat1.m31 == mat2.m31 && mat1.m32 == mat2.m32 && mat1.m33 == mat2.m33;
}
tBln tF32M4x4_Nearby(tF32M4x4 mat1, tF32M4x4 mat2, tF32 eps)
{
	return (tF32_Abs(mat1.m00 - mat2.m00) <= eps) && (tF32_Abs(mat1.m01 - mat2.m01) <= eps) && (tF32_Abs(mat1.m02 - mat2.m02) <= eps) && (tF32_Abs(mat1.m03 - mat2.m03) <= eps) && (tF32_Abs(mat1.m10 - mat2.m10) <= eps) && (tF32_Abs(mat1.m11 - mat2.m11) <= eps) && (tF32_Abs(mat1.m12 - mat2.m12) <= eps) && (tF32_Abs(mat1.m13 - mat2.m13) <= eps) && (tF32_Abs(mat1.m20 - mat2.m20) <= eps) && (tF32_Abs(mat1.m21 - mat2.m21) <= eps) && (tF32_Abs(mat1.m22 - mat2.m22) <= eps) && (tF32_Abs(mat1.m23 - mat2.m23) <= eps) && (tF32_Abs(mat1.m30 - mat2.m30) <= eps) && (tF32_Abs(mat1.m31 - mat2.m31) <= eps) && (tF32_Abs(mat1.m32 - mat2.m32) <= eps) && (tF32_Abs(mat1.m33 - mat2.m33) <= eps);
}
tF32V4D tF32M4x4_MulVec(tF32M4x4 mat, tF32V4D vec)
{
	tF32V4D res;
	res.x = (mat.m00 * vec.x) + (mat.m01 * vec.y) + (mat.m02 * vec.z) + (mat.m03 * vec.w);
	res.y = (mat.m10 * vec.x) + (mat.m11 * vec.y) + (mat.m12 * vec.z) + (mat.m13 * vec.w);
	res.z = (mat.m20 * vec.x) + (mat.m21 * vec.y) + (mat.m22 * vec.z) + (mat.m23 * vec.w);
	res.w = (mat.m30 * vec.x) + (mat.m31 * vec.y) + (mat.m32 * vec.z) + (mat.m33 * vec.w);
	return res;
}
tF32M4x4 tF32M4x4_Transp(tF32M4x4 mat)
{
	return tF32M4x4_Make(mat.m00, mat.m10, mat.m20, mat.m30, mat.m01, mat.m11, mat.m21, mat.m31, mat.m02, mat.m12, mat.m22, mat.m32, mat.m03, mat.m13, mat.m23, mat.m33);
}
tF32 tF32M4x4_Det(tF32M4x4 mat)
{
	return (mat.m00 * (tF32M3x3_Det(tF32M3x3_Make(mat.m11, mat.m12, mat.m13, mat.m21, mat.m22, mat.m23, mat.m31, mat.m32, mat.m33)))) - (mat.m01 * (tF32M3x3_Det(tF32M3x3_Make(mat.m10, mat.m12, mat.m13, mat.m20, mat.m22, mat.m23, mat.m30, mat.m32, mat.m33)))) + (mat.m02 * (tF32M3x3_Det(tF32M3x3_Make(mat.m10, mat.m11, mat.m13, mat.m20, mat.m21, mat.m23, mat.m30, mat.m31, mat.m33)))) - (mat.m03 * (tF32M3x3_Det(tF32M3x3_Make(mat.m10, mat.m11, mat.m12, mat.m20, mat.m21, mat.m22, mat.m30, mat.m31, mat.m32))));
}
tF32M3x3 tF32M4x4_Minor(tF32M4x4 mat, tU8 row, tU8 col)
{
#ifndef BQSE_DEBUG
	if (row >= 4U) return tF32M3x3_Zero();
	if (col >= 4U) return tF32M3x3_Zero();
#else
	Assertion(row < 4U);
	Assertion(col < 4U);
#endif
	tF32M3x3 minor;
	tU8 offsetI = 0U;
	for (tU8 idx = 0U; idx < 3U; ++idx)
	{
		if (idx == row) offsetI = 1U;
		tU8 offsetJ = 0U;
		for (tU8 jdx = 0U; jdx < 3U; ++jdx)
		{
			if (jdx == col) offsetJ = 1U;
			minor.m[idx][jdx] = mat.m[idx + offsetI][jdx + offsetJ];
		}
	}
	return minor;
}
tBln tF32M4x4_Minor_s(tF32M3x3 *out, tF32M4x4 mat, tU8 row, tU8 col)
{
	if (row >= 4U) return True;
	if (col >= 4U) return True;
	tU8 offsetI = 0U;
	for (tU8 idx = 0U; idx < 3U; ++idx)
	{
		if (idx == row) offsetI = 1U;
		tU8 offsetJ = 0U;
		for (tU8 jdx = 0U; jdx < 3U; ++jdx)
		{
			if (jdx == col) offsetJ = 1U;
			out->m[idx][jdx] = mat.m[idx + offsetI][jdx + offsetJ];
		}
	}
	return False;
}
tF32M4x4 tF32M4x4_Cofact(tF32M4x4 mat)
{
	tF32M4x4 cof;
	for (tU8 idx = 0U; idx < 4U; ++idx)
	{
		for (tU8 jdx = 0U; jdx < 4U; ++jdx)
		{
			cof.m[idx][jdx] = tF32M3x3_Det(tF32M4x4_Minor(mat, idx, jdx));
			if ((idx + jdx) & 1U) cof.m[idx][jdx] = tF32_Neg(cof.m[idx][jdx]);
		}
	}
	return cof;
}
tF32M4x4 tF32M4x4_Adj(tF32M4x4 mat)
{
	return tF32M4x4_Transp(tF32M4x4_Cofact(mat));
}
tF32M4x4 tF32M4x4_Inv(tF32M4x4 mat)
{
	tF32 det = tF32M4x4_Det(mat);
#ifndef BQSE_DEBUG
	if (tF32_Abs(det) <= tF32_Eps) return tF32M4x4_Zero();
#else
	Assertion(tF32_Abs(det) > tF32_Eps);
#endif
	return tF32M4x4_DivFlt(tF32M4x4_Adj(mat), det);
}
tBln tF32M4x4_Inv_safe(tF32M4x4 *mat)
{
	tF32 det = tF32M4x4_Det(*mat);
	if (tF32_Abs(det) <= tF32_Eps) return True;
	*mat = tF32M4x4_DivFlt(tF32M4x4_Adj(*mat), det);
	return False;
}
tF32M4x4 tF32M4x4_Transl(tF32 x, tF32 y, tF32 z)
{
	return tF32M4x4_Make(1.0F, 0.0F, 0.0F, x, 0.0F, 1.0F, 0.0F, y, 0.0F, 0.0F, 1.0F, z, 0.0F, 0.0F, 0.0F, 1.0F);
}
tF32M4x4 tF32M4x4_Scale(tF32 x, tF32 y, tF32 z)
{
	return tF32M4x4_Make(x, 0.0F, 0.0F, 0.0F, 0.0F, y, 0.0F, 0.0F, 0.0F, 0.0F, z, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F);
}
tF32M4x4 tF32M4x4_RotX(tF32 ang)
{
	const tF32 tmpC = tF32_Cosine(ang);
	const tF32 tmpS = tF32_Sine(ang);
	return tF32M4x4_Make(1.0F, 0.0F, 0.0F, 0.0F, 0.0F, tmpC, -tmpS, 0.0F, 0.0F, tmpS, tmpC, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F);
}
tF32M4x4 tF32M4x4_RotY(tF32 ang)
{
	tF32 tmpC = tF32_Cosine(ang);
	tF32 tmpS = tF32_Sine(ang);
	return tF32M4x4_Make(tmpC, 0.0F, tmpS, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, -tmpS, 0.0F, tmpC, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F);
}
tF32M4x4 tF32M4x4_RotZ(tF32 ang)
{
	tF32 tmpC = tF32_Cosine(ang);
	tF32 tmpS = tF32_Sine(ang);
	return tF32M4x4_Make(tmpC, -tmpS, 0.0F, 0.0F, tmpS, tmpC, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F);
}
tF32M4x4 tF32M4x4_Persp(tF32 fov, tF32 aspect, tF32 near, tF32 far);
tF32M4x4 tF32M4x4_Ortho(tF32 left, tF32 right, tF32 bot, tF32 top, tF32 near, tF32 far)
{
	tF32 tmpX = 1.0F / (right - left);
	tF32 tmpY = 1.0F / (top - bot);
	tF32 tmpZ = 1.0F / (far - near);
	return tF32M4x4_Make(2.0F * tmpX, 0.0F, 0.0F, tF32_Neg(right + left) * tmpX, 0.0F, 2.0F * tmpY, 0.0F, tF32_Neg(top + bot) * tmpY, 0.0F, 0.0F, tmpZ, tF32_Neg(near * tmpZ), 0.0F, 0.0F, 0.0F, 1.0F);
}
tF32 tF32M4x4_Trace(tF32M4x4 mat)
{
	return mat.m00 + mat.m11 + mat.m22 + mat.m33;
}
tF32M4x4 tF32M4x4_InvAff(tF32M4x4 mat);
tF32M4x4 tF32M4x4_RotAxis(tF32V3D axis, tF32 ang);
tF32V3D tF32M4x4_TransfPoint(tF32M4x4 mat, tF32V3D vec);
tF32V3D tF32M4x4_TransfDir(tF32M4x4 mat, tF32V3D vec);
// TODO: tF32M4x4 function implementations.
#endif
typedef union { struct { tF64 m00, m01; tF64 m10, m11; }; tF64 m[2][2]; tF64V2D row[2]; } tF64M2x2;
// TODO: tF64M2x2 function declarations.
#ifdef BQSE_MASTER
// TODO: tF64M2x2 function implementations.
#endif
typedef union { struct { tF64 m00, m01, m02; tF64 m10, m11, m12; tF64 m20, m21, m22; }; tF64 m[3][3]; tF64V3D row[3]; } tF64M3x3;
// TODO: tF64M3x3 function declarations.
#ifdef BQSE_MASTER
// TODO: tF64M3x3 function implementations.
#endif
typedef union { struct { tF64 m00, m01, m02, m03; tF64 m10, m11, m12, m13; tF64 m20, m21, m22, m23; tF64 m30, m31, m32, m33; }; tF64 m[4][4]; tF64V4D row[4]; } tF64M4x4;
// TODO: tF64M4x4 function declarations.
#ifdef BQSE_MASTER
// TODO: tF64M4x4 function implementations.
#endif
#endif/*BQSELAYER_MTRX_H*/