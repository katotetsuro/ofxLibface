/** ===========================================================
 * @file
 *
 * This file is a part of libface project
 * <a href="http://libface.sourceforge.net">http://libface.sourceforge.net</a>
 *
 * @date    2009-12-21
 * @brief
 * @section DESCRIPTION
 *
 * @author Copyright (C) 2009 by Aleksey
 *
 * @section LICENSE
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software Foundation;
 * either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * ============================================================ */

#include "FisherCore.h"

namespace libface
{
  
FisherCore::FisherCore()
{
    // TODO Auto-generated constructor stub
}

FisherCore::~FisherCore()
{
    // TODO Auto-generated destructor stub
}

CvMat* FisherCore::mean(CvMat* matrix)
{
    int rows      = matrix->rows;
    int cols      = matrix->cols;
    CvMat* result = cvCreateMat(rows, 1, CV_32FC1);

    for (int i=0 ; i<rows ; i++)
    {
        double sum = 0;

        for (int j=0 ; j<cols ; j++)
        {
            sum = sum + cvGet2D(matrix, i, j).val[0];
        }
        sum = sum / cols;

        CvScalar mean = cvScalarAll(sum);
        cvSet2D(result,i,0,mean);
    }

    return result;
}

CvMat* FisherCore::subtract(CvMat* src1, CvMat* src2)
{
    CvMat* result = cvCreateMat(src1->rows, src1->cols, CV_32FC1);

    for (int i=0 ; i<src1->rows ; i++)
    {
        for (int j=0 ; j<src1->cols ; j++)
        {
            double diff   = cvGet2D(src1, i, j).val[0] - cvGet2D(src2, i, 0).val[0];
            CvScalar data = cvScalarAll(diff);
            cvSet2D(result, i, j, data);
        }
    }

    return result;
}

void FisherCore::reverseOrder(CvMat* matrix)
{
    CvMat* result = cvCreateMat(matrix->rows,matrix->cols,CV_32FC1);

    for (int i=matrix->rows-1 ; i>=0 ; i--)
    {
        for (int j=matrix->cols-1 ; j>=0 ; j--)
        {
            cvSet2D(result, matrix->rows-i-1, matrix->cols-j-1, cvGet2D(matrix,i,j));
        }
    }
}

CvMat* FisherCore::getColoumn(CvMat* matrix, int col)
{
    CvMat* result = cvCreateMat(matrix->rows,1,CV_32FC1);

    for (int i=0 ; i<matrix->rows ; i++)
    {
        cvSet2D(result, i, 0, cvGet2D(matrix, i, col));
    }

    return result;
}

} // namespace libface
