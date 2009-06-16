/*******************************************************************************
    Copyright 2006-2009 Lukas Käll <lukas.kall@cbr.su.se>

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

 *******************************************************************************/

#ifndef LOGISTICREGRESSION_H_
#define LOGISTICREGRESSION_H_
#include<vector>
using namespace std;
#include "BaseSpline.h"

class LogisticRegression : public BaseSpline
{
public:
  LogisticRegression();
  virtual ~LogisticRegression();
  void predict(const vector<double>& x, vector<double>& predict) { return BaseSpline::predict(x,predict);}
  void setData(const vector<double>& xx, const vector<unsigned int>& yy, const vector<unsigned int>& mm) {
  	  BaseSpline::setData(xx);y=yy; m=mm;}
protected:
  virtual void calcPZW();
  virtual void initg();
  virtual void limitg();
  virtual void limitgamma();
  vector<unsigned int> y,m;
  static const double gRange;
  Vec p;
};

#endif /*LOGISTICREGRESSION_H_*/