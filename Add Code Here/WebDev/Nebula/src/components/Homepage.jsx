import React from 'react';
import millify from "millify";
import { Typography, Row, Statistic, Col} from "antd";
import { Link } from "react-router-dom";

import { useGetCryptosQuery } from '../services/cryptoApi';
import { Cryptocurrencies, News } from '../components';
import Loader from './Loader';

const Homepage = () => {

  const { Title } = Typography;

  const { data, isFetching } = useGetCryptosQuery(10);

  const globalStats = data?.data?.stats;

  if (isFetching) return <Loader />;

  return (
    <>
      <Title level={2} className="heading">
        Global Crypo Stats
      </Title>
      <Row className='crypto-stats'>
        <Col span={12} className='crypto-stats'>
          <Statistic title="Total Cryptocurrencies" value={globalStats.total} />
        </Col>
        <Col span={12} className='crypto-stats'>
          <Statistic
            title="Total Exchanges"
            value={millify(globalStats.totalExchanges)}
          />
        </Col>
        <Col span={12} className='crypto-stats'>
          <Statistic
            title="Total Market Cap"
            value={millify(globalStats.totalMarketCap)}
          />
        </Col>
        <Col span={12} className='crypto-stats'>
          <Statistic
            title="Total 24h volume"
            value={millify(globalStats.total24hVolume)}
          />
        </Col>
        <Col span={12} className='crypto-stats'>
          <Statistic
            title="Total Markets"
            value={millify(globalStats.totalMarkets)}
          />
        </Col>
      </Row>

      <div className="home-heading-container">
        <Title level={2} className="home-title">
          Top 10 Cryptocurrencies in the World
        </Title>

        <Title level={3} className="show-more">
          <Link style={{color: '#C69564'}} to="/cryptocurrencies">Show More</Link>
        </Title>
      </div>

      <Cryptocurrencies simplified />

      <div className="home-heading-container">
        <Title level={2} className="home-title">
          Latest Crypto News
        </Title>

        <Title level={3} className="show-more">
          <Link style={{color: '#C69564'}} to="/news">Show More</Link>
        </Title>
      </div>

      <News simplified />
      
    </>
  );
}

export default Homepage