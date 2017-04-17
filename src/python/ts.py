#! /usr/bin/env python
# -*- coding:utf-8 -*-

from sqlalchemy import create_engine
import tushare as ts

if __name__ == '__main__':
    data = ts.get_hist_data('600487')
    print(data)
    engine = create_engine('mysql://mahone:taobao@127.0.0.1/ts_dev?charset=utf8')
    data.to_sql('hist_data', engine,if_exists='append')
    # data.to_csv('600487_hist_data.csv')
    # data.to_excel('600487_hist_data.xlsx')
    # print(ts.__version__)

    print('end...')