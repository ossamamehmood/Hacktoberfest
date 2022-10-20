import React from 'react'
import { useGetCryptosQuery } from '../services/cryptoApi';
import Loader from './Loader';

const Exchanges = () => {

  const {data, isFetching} = useGetCryptosQuery(10);
  if (isFetching) return <Loader />;

  console.log(data);

  return (
    <div>Exchanges</div>
  )
}

export default Exchanges