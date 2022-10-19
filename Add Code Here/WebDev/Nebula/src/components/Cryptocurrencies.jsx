import React, { useEffect, useState } from 'react';
import millify from 'millify'
import { Link } from 'react-router-dom';
import { Card, Row, Col, Input } from 'antd';
import { useGetCryptosQuery } from '../services/cryptoApi';
import Loader from './Loader';

const Cryptocurrencies = ({ simplified }) => { //by default if no value is assed, true is passed

  const count = simplified ? 10 : 100
  const { data: cryptosList, isFetching } = useGetCryptosQuery(count);

  const [cryptos, setCryptos] = useState([])
  const [searchTerm, setSearchTerm] = useState("")

  useEffect(() => {
    const filteredData = cryptosList?.data?.coins.filter(coin => coin.name.toLowerCase().includes(searchTerm.toLowerCase()))

    setCryptos(filteredData)
  }, [cryptosList, searchTerm])
  
  if(isFetching) return <Loader />

  return (
    <>
      {!simplified && 
        <div className='search-crypto'>
          <Input  placeholder='Search Cryptocurrency' onChange={(e) => setSearchTerm(e.target.value)}/>
        </div>
      }

      <Row gutter={[32, 32]} className="crypto-card-container"> {/* gutters are just spaces */}
        {cryptos?.map(crypto => (
          <Col xs={24} sm={12} lg={6} className="crypto-card" key={crypto.uuid}>
            <Link to={`/crypto/${crypto.uuid}`}>
              <Card 
                title={`${crypto.rank}. ${crypto.name}`}
                extra={<img className='crypto-image' src={crypto.iconUrl} alt="crypto icon" />}
                hoverable
                className='cryptocurrency-card'
                bodyStyle={{backgroundColor: '#fffbf4'}}
              >
                <p>Price: {millify(crypto.price)}</p>
                <p>Market Cap: {millify(crypto.marketCap)}</p>
                <p>Daily Change: {millify(crypto.change)}</p>
              </Card>
            </Link>
          </Col>
        ))}
      </Row>
    </>
  )
}

export default Cryptocurrencies